NAME
       mq_unlink - remove a message queue

SYNOPSIS(n.概要)
       #include <mqueue.h>

       int mq_unlink(const char *name);

       Link with -lrt.

DESCRIPTION
       mq_unlink() removes the specified message queue name.  The message queue
       name is removed immediately.  The queue itself  is  destroyed  once  any
       other  processes that have the queue open close their descriptors refer‐
       ring to the queue.

RETURN VALUE
       On success mq_unlink() returns 0; on error, -1 is returned,  with  errno
       set to indicate the error.

----posix消息队列具有随内核的持续性，这就是说，即使当前没有进程打开某个消息队列，该队列及其上的各个消息也将一直存在，直到调用mq_unlink并让它们的引用计数达到０以删除该队列为止。
