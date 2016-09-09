NAME
       mq_close - close a message queue descriptor

SYNOPSIS
       #include <mqueue.h>

       int mq_close(mqd_t mqdes);

       Link with -lrt.

DESCRIPTION
       mq_close() closes the message queue descriptor mqdes.

       If  the calling process has attached a notification(n.通知,通告) request to this message queue via mqdes, then this request is removed, and another  process　can now attach a notification request(通知请求).

RETURN VALUE
       On  success  mq_close()  returns 0; on error, -1 is returned, with errno
       set to indicate the error.


