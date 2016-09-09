	   #include <sys/epoll.h>

       int epoll_wait(int epfd, struct epoll_event *events,
                      int maxevents, int timeout);
                      
       int epoll_pwait(int epfd, struct epoll_event *events,
                       int maxevents, int timeout,
                       const sigset_t *sigmask);
               
    ----该函数在一组timeout时间内等待一组文件描述符上的事件。
    ----返回：就绪的文件描述符的个数，-1,errno
                       
	----等待直到注册的事件发生（注：当对一个非阻塞流的读写发生缓冲区满或缓冲区空，write/read会返回-1，并设置errno=EAGAIN。而epoll只关心缓冲区非满和缓冲区非空事件）。
	----第一个参数是epoll的描述符
	
		events参数是一个指向 struct epoll_event 的指针，这里需要传入的是一个数组，epoll_event类型.(epoll_wait如果检测到事件，就将所有就绪的事件从内核事件表(由epfd)中复制到它的第二个参数events指向的数组中。这个数组只用于输出epoll_wait检测到的就绪事件，这就极大的提高了应用程序索引就绪文件描述符的效率)
		附：select和poll的数组参数既用于传入用户注册的事件，又用于输出内核检测到的事件。
		
		maxevents：指定最多监听多少个事件，它必须大于０。
		
		timeout：是超时时间(和poll接口的timeout相同)，对于Nginx或者很多如libevent的超时时间管理是利用红黑树和最小堆来管理的，很巧妙的方式，以后写一篇博文介绍，这里只需要知道timeout 是 epoll_wait 的阻塞的最大值，如果超过这个值不管是否有事件都返回，0表示立即返回，即有无事件都返回，-1 是永久阻塞
		
DESCRIPTION
       The  epoll_wait()  system call waits for events on the epoll(7) instance referred to by the
       file descriptor epfd.  The memory area pointed to by events will contain  the  events  that
       will  be available for the caller.  Up to maxevents are returned by epoll_wait().  The max‐
       events argument must be greater than zero.

       The timeout argument specifies the number of milliseconds  that  epoll_wait()  will  block.
       The call will block until either:

       *  a file descriptor delivers an event;

       *  the call is interrupted by a signal handler; or

       *  the timeout expires.
 Note that the timeout interval will be rounded up to the system clock granularity, and ker‐
       nel scheduling delays mean that the blocking interval may overrun by a small amount.  Spec‐
       ifying  a timeout of -1 causes epoll_wait() to block indefinitely, while specifying a time‐
       out equal to zero cause epoll_wait() to return immediately, even if no  events  are  avail‐
       able.

       The struct epoll_event is defined as :

           typedef union epoll_data {
               void    *ptr;
               int      fd;
               uint32_t u32;
               uint64_t u64;
           } epoll_data_t;

           struct epoll_event {
               uint32_t     events;    /* Epoll events */
               epoll_data_t data;      /* User data variable */
           };

       The  data  of  each  returned  structure  will  contain  the same data the user set with an
       epoll_ctl(2) (EPOLL_CTL_ADD, EPOLL_CTL_MOD)  while  the  events  member  will  contain  the
       returned event bit field.

  epoll_pwait()
       The  relationship  between  epoll_wait() and epoll_pwait() is analogous to the relationship
       between select(2) and pselect(2): like pselect(2), epoll_pwait() allows an  application  to
       safely wait until either a file descriptor becomes ready or until a signal is caught.

       The following epoll_pwait() call:

           ready = epoll_pwait(epfd, &events, maxevents, timeout, &sigmask);

       is equivalent to atomically executing the following calls:

           sigset_t origmask;

           sigprocmask(SIG_SETMASK, &sigmask, &origmask);
           ready = epoll_wait(epfd, &events, maxevents, timeout);
           sigprocmask(SIG_SETMASK, &origmask, NULL);

       The sigmask argument may be specified as NULL, in which case epoll_pwait() is equivalent to
       epoll_wait().

RETURN VALUE
       When successful, epoll_wait()  returns  the  number  of  file  descriptors  ready  for  the
       requested I/O, or zero if no file descriptor became ready during the requested timeout mil‐
       liseconds.  When an error occurs, epoll_wait() returns -1 and errno is set appropriately.


