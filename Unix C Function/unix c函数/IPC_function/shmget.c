#include<sys/shm.h>
int shmget(key_t key,size_t size,int shmflag);
----该函数返回一个与参数key相关的共享内存段标识符，如果键值为IPC_PRIVATE或者semflg&IPC_CTEAT非０而且没有信号量集或标识符关联key,那么shmget函数就创建这个段
----该共享内存段大小为size
----成功返回一个对应于共享内存段标识符的非负整数，否则返回-1并设置errno

