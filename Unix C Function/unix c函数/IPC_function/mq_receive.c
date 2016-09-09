NAME
       mq_receive, mq_timedreceive - receive a message from a message queue

SYNOPSIS
       #include <mqueue.h>

       ssize_t mq_receive(mqd_t mqdes, char *msg_ptr,
                          size_t msg_len, unsigned int *msg_prio);
       Link with -lrt.

	   ----该函数总是返回所指定队列中最高优先级的最早消息，而且该优先级能随该消息的内容及其长度一同返回。
	   ----msg_len不能小于能加到所指定队列中的消息的最大大小。
	   ----msg_prio是一个非空指针，所返回消息的优先级就通过该指针存放。如果应用不必使用优先级不同的消息，那就给mq_send指定值为０的优先级，给mq_receive指定一个空指针作为其最后一个参数。
	   


   Feature Test Macro Requirements for glibc (see feature_test_macros(7)):

       mq_timedreceive():
           _XOPEN_SOURCE >= 600 || _POSIX_C_SOURCE >= 200112L

DESCRIPTION
       mq_receive()  removes the oldest message with the highest priority from the
       message queue referred to by the descriptor mqdes, and  places  it  in  the
       buffer  pointed  to by msg_ptr.  The msg_len argument specifies the size of
       the buffer pointed to by msg_ptr; this must be greater than or equal to the
       mq_msgsize  attribute of the queue (see mq_getattr(3)).  If msg_prio is not
       NULL, then the buffer to which it points is used  to  return  the  priority
       associated with the received message.

       If  the  queue is empty, then, by default, mq_receive() blocks until a mes‐
       sage becomes available, or the call is interrupted by a signal handler.  If
       the  O_NONBLOCK flag is enabled for the message queue description, then the
       call instead fails immediately with the error EAGAIN.

       mq_timedreceive() behaves just like mq_receive(), except that if the  queue
       is  empty  and  the  O_NONBLOCK  flag  is not enabled for the message queue
       description, then abs_timeout points to a structure which specifies a ceil‐
       ing on the time for which the call will block.  This ceiling is an absolute
       timeout in seconds and nanoseconds since  the  Epoch,  1970-01-01  00:00:00
       +0000 (UTC), and it is specified in the following structure:

           struct timespec {
               time_t tv_sec;        /* seconds */
               long   tv_nsec;       /* nanoseconds */
           };

       If no message is available, and the timeout has already expired by the time
       of the call, mq_timedreceive() returns immediately.

RETURN VALUE
       On success, mq_receive() and mq_timedreceive() return the number  of  bytes
       in  the received message; on error, -1 is returned, with errno set to indi‐
       cate the error.


