NAME
       mq_notify - register for notification when a message is available

SYNOPSIS
       #include <mqueue.h>
       int mq_notify(mqd_t mqdes, const struct sigevent *sevp);
       Link with -lrt.

	   ----该函数为指定队列建立或删除异步事件通知。
	   ----(1)如果sevp参数非空，那么当前进程希望在有一个消息到达所指定的先前为空的队列时得到通知。我们说“该进程被注册为接收该队列的通知”
	   	   (2)如果sevp参数为空指针，而且当前进程目前被注册为接收所指定队列的通知，那么已存在的注册将被撤销。
	   	   (3)任意时刻只有一个进程可以被注册为接收某个给定队列的通知。
	   	   .....(p69)
	   	   

DESCRIPTION
       mq_notify() allows the calling process to register or unregister for deliv‐
       ery of an asynchronous(异步的) notification when a new message arrives on the empty
       message queue referred to by the descriptor mqdes.

       The sevp argument is a pointer to a sigevent structure.  For the definition
       and general details of this structure, see sigevent(7).

       If sevp is a non-null  pointer,  then  mq_notify()  registers  the  calling
       process  to  receive  message  notification.  The sigev_notify field of the
       sigevent structure to which sevp points specifies how notification is to be
       performed.  This field has one of the following values:

SIGEV_NONE
              A "null" notification: the calling process is registered as the tar‐
              get for notification, but when a message arrives, no notification is
              sent.

       SIGEV_SIGNAL
              Notify  the  process by sending the signal specified in sigev_signo.
              See sigevent(7) for general details.  The si_code field of the  sig‐
              info_t  structure will be set to SI_MESGQ.  In addition, si_pid will
              be set to the PID of the process that sent the message,  and  si_uid
              will be set to the real user ID of the sending process.

       SIGEV_THREAD
              Upon  message  delivery,  invoke sigev_notify_function as if it were
              the start function of a new thread.  See sigevent(7) for details.

       Only one process can be registered to receive notification from  a  message
       queue.

       If sevp is NULL, and the calling process is currently registered to receive
       notifications for this message queue, then  the  registration  is  removed;
       another  process  can  then  register to receive a message notification for
       this queue.

 If sevp is NULL, and the calling process is currently registered to receive
       notifications for this message queue, then  the  registration  is  removed;
       another  process  can  then  register to receive a message notification for
       this queue.

       Message notification occurs only when a new message arrives and  the  queue
       was  previously  empty.  If the queue was not empty at the time mq_notify()
       was called, then a notification will occur only after the queue is  emptied
       and a new message arrives.

       If  another  process  or  thread is waiting to read a message from an empty
       queue using mq_receive(3), then any message  notification  registration  is
       ignored:  the  message  is  delivered  to  the  process  or  thread calling
       mq_receive(3), and the message notification registration remains in effect.

       Notification occurs once: after a notification is delivered, the  notifica‐
       tion  registration is removed, and another process can register for message
       notification.  If the notified process wishes to receive the next notifica‐
       tion,  it  can  use  mq_notify()  to  request a further notification.  This
       should be done before emptying all unread messages from the queue.   (Plac‐
       ing  the queue in nonblocking mode is useful for emptying the queue of mes‐
       sages without blocking once it is empty.)

RETURN VALUE
       On success mq_notify() returns 0; on error, -1 is returned, with errno  set
       to indicate the error.

       #include <pthread.h>
       #include <mqueue.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>

       #define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

       static void                     /* Thread start function */
       tfunc(union sigval sv)
       {
           struct mq_attr attr;
           ssize_t nr;
           void *buf;
           mqd_t mqdes = *((mqd_t *) sv.sival_ptr);

           /* Determine max. msg size; allocate buffer to receive msg */

           if (mq_getattr(mqdes, &attr) == -1)
               handle_error("mq_getattr");
           buf = malloc(attr.mq_msgsize);
           if (buf == NULL)
               handle_error("malloc");

           nr = mq_receive(mqdes, buf, attr.mq_msgsize, NULL);
           if (nr == -1)
               handle_error("mq_receive");

           printf("Read %zd bytes from MQ\n", nr);
           free(buf);
           exit(EXIT_SUCCESS);         /* Terminate the process */
       }

       int
       main(int argc, char *argv[])
       {
           mqd_t mqdes;
           struct sigevent sev;

           if (argc != 2) {
               fprintf(stderr, "Usage: %s <mq-name>\n", argv[0]);
               exit(EXIT_FAILURE);
           }

           mqdes = mq_open(argv[1], O_RDONLY);
           if (mqdes == (mqd_t) -1)
               handle_error("mq_open");

           sev.sigev_notify = SIGEV_THREAD;
           sev.sigev_notify_function = tfunc;
           sev.sigev_notify_attributes = NULL;
           sev.sigev_value.sival_ptr = &mqdes;   /* Arg. to thread func. */
           if (mq_notify(mqdes, &sev) == -1)
               handle_error("mq_notify");

           pause();    /* Process will be terminated by thread function */
       }


