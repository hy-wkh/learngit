#include<sys/shm.h>
int shmdt(const void *shmaddr);
----该函数用来分离共享内存段，并对shm_nattch进行减量操作
----shmaddr是共享内存段的起始地址
----成功返回０，否则返回-1并设置errno;最后一个分离内存段的进程应该通过调用shmctl来释放共享内存段




