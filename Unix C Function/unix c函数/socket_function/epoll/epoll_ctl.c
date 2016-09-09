	   
	   #include <sys/epoll.h>
	　　　int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
	　　　
	----返回：０,-1,errno.
	----第一个参数是由epoll_create 返回的描述符
		第二个参数是由宏定义的几个值,用于指定操作类型:
			EPOLL_CTL_ADD：类似于 select 的 FD_SET()，将一个描述符加入到epoll监听队列中(也就是往内核事件表中注册fd上的事件)	
			EPOLL_CTL_MOD：修改已经注册的fd的事件类型
			EPOLL_CTL_DEL：将一个描述符从epoll监听队列中删除
		第三个参数是需要加入的描述符
		第四个是一个结构体参数，用于指定事件，结构是这样的:

           typedef union epoll_data {
               void        *ptr;  //用来指定与fd相关的用户数据(epoll_data_t是一个联合体，我们不能同时使用其ptr成员和fd成员,因此如果要将文件描述符和用户数据关联起来，以实现快速的数据访问，只能使用其他手段，比如放弃使用epoll_data_t的fd成员，而在ptr指向的用户数据中包含fd)
               int          fd;   //
               uint32_t     u32;  //
               uint64_t     u64;  //
           } epoll_data_t;
           
           ----该联合体指定事件所从属的目标文件描述符。
           
		   struct epoll_event {
               uint32_t     events;      /* Epoll events */
               epoll_data_t data;        /* User data variable 用于存储用户数据*/
           };

	epoll_event结构体里面的"events 表示的是返回的事件类型或者是加入时候的事件类型"。也有可能是带外数据或者错误等，它由几个宏定义：
			 EPOLLIN：文件描述符上的读事件
			 EPOLLOUT：文件描述符上的写事件
			 EPOLLPRI：描述符有紧急的数据可读（这里应该表示有带外数据到来）；
			 EPOLLERR：描述符发生错误；
			 EPOLLHUP：描述符被挂断；
			 EPOLLET： 边缘触发(Edge Triggered)模式
			 EPOLLRDHUP:tcp连接被对方关闭，或者对方关闭了写操作
			 EPOLLONESHOT：只监听一次事件，当监听完这次事件之后，如果还需要继续监听这个socket的话，需要再次把这个socket加入到EPOLL队列里 值得一说的是，很多文章都没有提到这个宏其实可能是由你自己改变的，通过 epoll_ctl 或者是在epoll_wait 返回的时候操作系统改的，因为描述符有可能出错等。一般情况下，对于一个描述符，可以使用 | 运算来组合。添加一个描述符，监听是否可读或可写。EPOLLIN | EPOLLOUT 注意一下epoll_data_t中的 ptr 或者 fd 而不是 ptr和fd，这个结构只能包含其中一个，所以在注册相应的描述符上的事件的时候，要么注册的是对应的描述符fd，要么注册的是相应的事件封装，当然，事件封装里面必然有fd，不然无法继续下面的操作。 



DESCRIPTION
       This system  call  performs  control  operations  on  the
       epoll(7)  instance  referred  to  by  the file descriptor
       epfd.  It requests that the operation op be performed for
       the target file descriptor, fd.

       Valid values for the op argument are :

       EPOLL_CTL_ADD
              Register  the  target  file  descriptor  fd on the
              epoll instance referred to by the file  descriptor
              epfd and associate the event event with the inter‐
              nal file linked to fd.
              
	   EPOLL_CTL_MOD
              Change the event event associated with the  target
              file descriptor fd.

       EPOLL_CTL_DEL
              Remove  (deregister) the target file descriptor fd
              from the epoll instance referred to by epfd.   The
              event  is  ignored  and  can be NULL (but see BUGS
              below).

       The event argument describes the  object  linked  to  the
       file descriptor fd.  The struct epoll_event is defined as:

           typedef union epoll_data {
               void        *ptr;
               int          fd;
               uint32_t     u32;
               uint64_t     u64;
           } epoll_data_t;
           
		   struct epoll_event {
               uint32_t     events;      /* Epoll events */
               epoll_data_t data;        /* User data variable */
           };

       The events member is a bit set composed using the follow‐
       ing available event types:

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
	   (以上两个事件对epoll的高效运作非常关键)

       EPOLLIN
              The associated file is available for read(2) oper‐
              ations.

       EPOLLOUT
              The associated  file  is  available  for  write(2)
              operations.
	   ....
	   
	   RETURN VALUE
       When successful, epoll_ctl() returns zero.  When an error
       occurs, epoll_ctl() returns -1 and errno is set appropri‐
       ately.










