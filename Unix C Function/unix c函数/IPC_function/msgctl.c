#include<sys/msg.h>
int msgctl(int msqid,int cmd,struct msqid_ds *buf);
----该函数用来释放或修改msqid标识的消息队列的权限
----cmd说明了要采取的动作，函数根据cmd的值，用它的参数buf来读或写状态信息
----成功返回０，否则返回-1并设置errno


