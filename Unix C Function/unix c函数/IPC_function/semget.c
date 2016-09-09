#include<sys/sem.h>
int semget(key_t key,int nsems,int semflag);
----该函数返回与参数key相关的信号量集标识符。如果键值为IPC_ORIVATE或者semflg&IPC_CTEAT非０而且没有信号量集或标识符关联key,那么semget函数就创建标识符及与之相关的信号量集
----nsems指定了集合中元素的个数，semflg指定了信号量集的优先级
----成功：返回一个对应于信号量集标识符的非负整数，否则返回-1并设置errno
