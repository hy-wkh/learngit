       #include <fcntl.h>           /* For O_* constants */
       #include <sys/stat.h>        /* For mode constants */
       #include <mqueue.h>

       mqd_t mq_open(const char *name, int oflag,.../* mode_t mode,
                     struct mq_attr *attr*/);

	   ----oflag参数是O_RDONLY,O_WRONLY,O_RDWR之一，可能按位或上O_CREAT,O_EXCL或O_NONBLOCK
	   ----返回值：成功返回消息队列描述符，否则返回-1


----DESCRIPTION
       mq_open()  creates a new POSIX message queue or opens an existing queue.
       The queue is identified by name.  For details  of  the  construction  of
       name, see mq_overview(7).

       The  oflag  argument  specifies  flags that control the operation of the
       call.  (Definitions of the flags values can  be  obtained  by  including
       <fcntl.h>.)  Exactly one of the following must be specified(n.规定的) in 
       oflag:

       O_RDONLY
              Open the queue to receive messages only.
		
       O_WRONLY
              Open the queue to send messages only.

       O_RDWR Open the queue to both send and receive messages.

       Zero or more of the following flags can additionally be ORed in oflag:

       O_NONBLOCK
              Open  the  queue  in  nonblocking  mode.   In circumstances where
              mq_receive(3) and mq_send(3) would normally  block,  these  func‐
              tions instead fail with the error EAGAIN.

       O_CREAT
              Create  the  message queue if it does not exist.  The owner (user
              ID) of the message queue is set to the effective user ID  of  the
              calling  process.   The  group ownership (group ID) is set to the
              effective group ID of the calling process.

       O_EXCL If O_CREAT was specified in oflag, and a  queue  with  the  given
              name already exists, then fail with the error EEXIST.

       ----If  O_CREAT is specified in oflag, then two additional arguments must be supplied.  
       
       The mode argument specifies the permissions to be  placed  on
       the  new  queue,  as for open(2).  (Symbolic definitions for the permis‐
       sions bits can be obtained by including <sys/stat.h>.)  The  permissions
       settings are masked against the process umask.

       The attr argument specifies attributes for the queue.  See mq_getattr(3)
       for details.  If attr is NULL, then the queue is created with  implemen‐
       tation-defined default attributes.  Since Linux 3.5, two /proc files can
       be used to control these defaults; see mq_overview(7) for details.

RETURN VALUE
       On success, mq_open() returns a message  queue  descriptor  for  use  by
       other  message queue functions.  On error, mq_open() returns (mqd_t) -1,
       with errno set to indicate the error.


