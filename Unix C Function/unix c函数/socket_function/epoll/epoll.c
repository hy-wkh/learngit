	   epoll事件类型：
	   The events member is a bit  set  composed  using  the  following
       available event types:

       EPOLLIN
              The associated file is available for read(2) operations.

       EPOLLOUT
              The associated file is available for write(2) operations.

       EPOLLRDHUP (since Linux 2.6.17)
              Stream  socket peer closed connection, or shut down writ‐
              ing half of connection.  (This flag is especially  useful
              for  writing  simple  code  to  detect peer shutdown when
              using Edge Triggered monitoring.)

       EPOLLPRI
              There is urgent data available for read(2) operations.

       EPOLLERR
              Error condition happened on the associated file  descrip‐
              tor.   epoll_wait(2)  will always wait for this event; it
              is not necessary to set it in events.
                     EPOLLHUP
              Hang up  happened  on  the  associated  file  descriptor.
              epoll_wait(2)  will always wait for this event; it is not
              necessary to set it in events.

       EPOLLET
              Sets the Edge Triggered behavior for the associated  file
              descriptor.   The  default  behavior  for  epoll is Level
              Triggered.  See epoll(7) for  more  detailed  information
              about  Edge and Level Triggered event distribution archi‐
              tectures.

       EPOLLONESHOT (since Linux 2.6.2)
              Sets  the  one-shot  behavior  for  the  associated  file
              descriptor.  This means that after an event is pulled out
              with epoll_wait(2)  the  associated  file  descriptor  is
              internally  disabled and no other events will be reported
              by the epoll interface.  The user must  call  epoll_ctl()
              with  EPOLL_CTL_MOD  to  rearm the file descriptor with a

              new event mask.

       EPOLLWAKEUP (since Linux 3.5)
              If EPOLLONESHOT and EPOLLET are clear and the process has
              the  CAP_BLOCK_SUSPEND capability, ensure that the system
              does not enter "suspend" or "hibernate" while this  event
              is  pending  or being processed.  The event is considered
              as being "processed" from the time when it is returned by
              a   call   to   epoll_wait(2)  until  the  next  call  to
              epoll_wait(2) on the same epoll(7) file  descriptor,  the
              closure of that file descriptor, the removal of the event
              file descriptor with EPOLL_CTL_DEL, or  the  clearing  of
              EPOLLWAKEUP   for   the   event   file   descriptor  with
              EPOLL_CTL_MOD.  See also BUGS.




	
	
	缓冲区的引入是为了减少频繁I/O操作而引起频繁的 系统调用(你知道它很慢的)，当你操作一个流时，更多的是以缓冲区为单位进行操作，这是相对于用户空间而言。对于内核来说，也需要缓冲区。
	
	假设一开始内核缓冲区是空的，B作为读出方，被阻塞着。然后首先A往管道写入，这时候内核缓冲区由空的状态变到非空状态，内核就会产生一个事件告诉Ｂ该醒来了，这个事件姑且称之为“缓冲区非空”。
	但是“缓冲区非空”事件通知B后，B却还没有读出数据；且内核许诺了不能把写入管道中的数据丢掉这个时候，Ａ写入的数据会滞留在内核缓冲区中， 如果内核也缓冲区满了，B仍未开始读数据，最终内核缓冲区会被填满，这个时候会产生一个I/O事件，告诉进程A，你该等等（阻塞）了，我们把这个事件定义 为“缓冲区满”。
	假设后来Ｂ终于开始读数据了，于是内核的缓冲区空了出来，这时候内核会告诉A，内核缓冲区有空位了，你可以从长眠中醒来了，继续写数据了，我们把这个事件叫做“缓冲区非满”
	也许事件Y1已经通知了A，但是A也没有数据写入了，而Ｂ继续读出数据，知道内核缓冲区空了。这个时候内核就告诉B，你需要阻塞了！，我们把这个时间定为“缓冲区空”。
	这四个情形涵盖了四个I/O事件，缓冲区满，缓冲区空，缓冲区非空，缓冲区非满（注都是说的内核缓冲区，且这四个术语都是我生造的，仅为解释其 原理而造）。这四个I/O事件是进行阻塞同步的根本。（如果不能理解“同步”是什么概念，请学习操作系统的锁，信号量，条件变量等任务同步方面的相关知识）。
	
	然后我们来说说阻塞I/O的缺点。但是阻塞I/O模式下，一个线程只能处理一个流的I/O事件。如果想要同时处理多个流，要么多进程(fork)，要么多线程(pthread_create)，很不幸这两种方法效率都不高。
	我们只要不停的把所有流从头到尾问一遍，又从头开始。这样就可以处理多个流了，但这样的做法显然不好，因为如果所有的流都没有数据，那么只会白 白浪费CPU。
	阻塞模式下，内核对于I/O事件的处理是阻塞或者唤醒，而非阻塞模式下则把I/O事件交给其他对象（后文介绍的 select以及epoll）处理甚至直接忽略。
	为了避免CPU空转，可以引进了一个代理（一开始有一位叫做select的代理，后来又有一位叫做poll的代理，不过两者的本质是一样的）。 这个代理比较厉害，可以同时观察许多流的I/O事件，在空闲的时候，会把当前线程阻塞掉，当有一个或多个流有I/O事件时，就从阻塞态中醒来，于是我们的 程序就会轮询一遍所有的流（于是我们可以把“忙”字去掉了）。
	于是，如果没有I/O事件产生，我们的程序就会阻塞在select处。但是依然有个问题，我们从select那里仅仅知道了，有I/O事件发生 了，但却并不知道是那几个流（可能有一个，多个，甚至全部），我们只能无差别轮询所有流，找出能读出数据，或者写入数据的流，对他们进行操作。
	但是使用select，我们有O(n)的无差别轮询复杂度，同时处理的流越多，每一次无差别轮询时间就越长。
	epoll可以理解为event poll，不同于忙轮询和无差别轮询，epoll之会把哪个流发生了怎样的I/O事件通知我们。此时我们对这些流的操作都是有意义的。（复杂度降低到了O(1)）
	
	
在讨论epoll的实现细节之前，先把epoll的相关操作列出：
	epoll_create 创建一个epoll对象，一般epollfd = epoll_create()
	epoll_ctl （epoll_add/epoll_del的合体），往epoll对象中增加/删除某一个流的某一个事件
比如：
	epoll_ctl(epollfd, EPOLL_CTL_ADD, socket, EPOLLIN);//注册缓冲区非空事件，即有数据流入
	epoll_ctl(epollfd, EPOLL_CTL_DEL, socket, EPOLLOUT);//注册缓冲区非满事件，即流可以被写入
	epoll_wait(epollfd,...)等待直到注册的事件发生
（注：当对一个非阻塞流的读写发生缓冲区满或缓冲区空，write/read会返回-1，并设置errno=EAGAIN。而epoll只关心缓冲区非满和缓冲区非空事件）。
	
	1.Epoll 没有最大并发连接的限制，上限是最大可以打开文件的数目
	2.效率提升， Epoll 最大的优点就在于它只管你 “ 活跃 ” 的连接 ，而跟连接总数无关，因此在实际的网络环境中， Epoll 的效率就会远远高于 select 和 poll 。
	3.内存拷贝， Epoll 在这点上使用了 “ 共享内存 ” ，这个内存拷贝也省略了。
	4.Epoll 不仅会告诉应用程序有 I/0 事件到来，还会告诉应用程序相关的信息，这些信息是应用程序填充的，因此根据这些信息应用程序就能直接定位到事件，而不必遍历整个 FD 集合。 Epoll 速度快和其数据结构密不可分,epoll_data 是一个 union 结构体 , 借助于它应用程序可以保存很多类型的信息 :fd 、指针等等。有了它，应用程序就可以直接定位目标了。
	5.epoll可以同时支持水平触发和边缘触发（Edge Triggered，只告诉进程哪些文件描述符刚刚变为就绪状态，它只说一遍，如果我们没有采取行动，那么它将不会再次告知，这种方式称为边缘触发），理论上边缘触发的性能要更高一些，但是代码实现相当复杂。
	6.当你调用epoll_create时，就会在虚拟的epoll文件系统里创建一个file结点。当然这个file不是普通文件，它只服务于epoll。epoll在被内核初始化时（操作系统启动），同时会开辟出epoll自己的内核高速cache区，用于安置每一个我们想监控的socket，这些socket会以红黑树的形式保存在内核cache里，以支持快速的查找、插入、删除。这个内核高速cache区，就是建立连续的物理内存页，然后在之上建立slab层，
	
	
	
	
	
	
	
	
	
	
	
	

