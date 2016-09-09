	   #include <sys/epoll.h>

       int epoll_create(int size);
       int epoll_create1(int flags);
       
       	int epoll_create(int size);
    
    ----这个函数用于创建epoll.
    
	----在现在的Linux版本中，size已不重要，只是给内核一个提示，告诉它事件表需要多大，默认的不超过最大值就可以。size 就是描述符数目的最大值。
	
	----函数的返回值是一个描述符（句柄）,该描述符将用作其他所有epoll系统调用的第一个参数，用以指定要访问的内核事件表。
	
DESCRIPTION
       epoll_create() creates an epoll(7) instance.  Since Linux
       2.6.8,  the size argument is ignored, but must be greater
       than zero; see NOTES below.

       epoll_create() returns a file descriptor referring to the
       new epoll instance.  This file descriptor is used for all
       the subsequent calls to the  epoll  interface.   When  no
       longer   required,   the   file  descriptor  returned  by
       epoll_create() should be closed by using close(2).   When
       all  file descriptors referring to an epoll instance have
       been  closed,  the  kernel  destroys  the  instance   and
       releases the associated resources for reuse.

   epoll_create1()
       If  flags  is 0, then, other than the fact that the obso‐
       lete size argument is  dropped,  epoll_create1()  is  the
       same  as  epoll_create().   The  following  value  can be
       included in flags to obtain different behavior:
       
    EPOLL_CLOEXEC
              Set the close-on-exec (FD_CLOEXEC) flag on the new
              file  descriptor.   See  the  description  of  the
              O_CLOEXEC flag in open(2) for reasons why this may
              be useful.

	RETURN VALUE
       On  success, these system calls return a nonnegative file
       descriptor.  On error, -1 is returned, and errno  is  set
       to indicate the error.

