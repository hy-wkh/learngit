#include<sys/msg.h>
ssize_t msgrcv(int msqid,void *msgp,size_t msgsz,long msgtyp,int msgflg);
----该函数可以从一个消息队列中删除一条消息
----msqid用来标识消息队列
	msgp指向一个用户定义的缓冲区，这个缓冲区中装载了要检索的消息，格式与msgsnd的格式类似
	msgsz指定了消息文本的实际长度
	接收程序可以用参数msgtyp来选择消息
	msgflg说明了在各种条件下应该采取的动作
----成功返回消息文本中的字节数，否则返回（ssize_t）-1 并设置errno

