#include<sys/msg.h>
int msgsnd(int msqid,const void *msgp,size_t msgsz,int msgflg);
----用msgget获得了对消息队列的访问权后，程序用msgsnd向队列中插入消息
----msqid标识了消息队列,
	msgp指向一个用户定义的缓冲区，缓冲区中包含了要传送的消息，
	msgsz指定了消息文本的实际长度，
	msgflg说明了在各种条件下应采取的行动
----成功返回０，否则返回-1并设置errno




