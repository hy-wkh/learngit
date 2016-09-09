SYNOPSIS
       #include <mqueue.h>
       int mq_getattr(mqd_t mqdes, struct mq_attr *attr);
       int mq_setattr(mqd_t mqdes, const struct mq_attr *newattr,
                        struct mq_attr *oldattr);
       Link with -lrt.

	----mq_getattr把所指定队列的当前属性填入由attr指向的结构
	
	----mq_setattr给所指定的队列设置属性，但是只使用由attr指向的mq_attr结构的mq_flags成员，以设置或清除非阻塞标志，该结构的另外三个成员被忽略。每个队列的最大消息数和每个消息的最大字节数只能在创建队列时设置。队列中的当前消息数只能获取而不能设置。
	
	----如果oattr非空，那么所指定队列的先前属性和当前状态将返回到由该指针指向的结构中。

DESCRIPTION
       mq_getattr() and mq_setattr() respectively retrieve and modify
       attributes of the message queue referred to by the  descriptor
       mqdes.

       mq_getattr()  returns  an  mq_attr  structure  in  the  buffer
       pointed by attr.  This structure is defined as:

           struct mq_attr {
               long mq_flags;       /* Flags: 0 or O_NONBLOCK */
               long mq_maxmsg;      /* Max. # of messages on queue */
               long mq_msgsize;     /* Max. message size (bytes) */
               long mq_curmsgs;     /* # of messages currently in queue
 */
           };
       The mq_flags field contains flags  associated  with  the  open
       message queue description.  This field is initialized when the
       queue is created by mq_open(3).  The only flag that can appear
       in this field is O_NONBLOCK.

       The  mq_maxmsg  and mq_msgsize fields are set when the message
       queue is created by mq_open(3).  The  mq_maxmsg  field  is  an
       upper  limit  on  the number of messages that may be placed on
       the queue using mq_send(3).  The mq_msgsize field is an  upper
       limit on the size of messages that may be placed on the queue.
       Both of these fields must have a value greater than zero.  Two
       /proc files that place ceilings on the values for these fields
       are described in mq_overview(3).

       The mq_curmsgs field returns the number of messages  currently
       held in the queue.

       mq_setattr()  sets  message queue attributes using information
       supplied in the mq_attr structure pointed to by newattr.   The
       only  attribute  that  can  be  modified is the setting of the
       O_NONBLOCK flag in mq_flags.  The other fields in newattr  are
       ignored.   If  the  oldattr field is not NULL, then the buffer
       that it points to is used to return an mq_attr structure  that
       contains   the   same   information   that   is   returned  by
       mq_getattr().
       
       RETURN VALUE
       On success mq_getattr() and mq_setattr() return 0;  on  error,
       -1 is returned, with errno set to indicate the error.



