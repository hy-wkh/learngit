#include<sys/sem.h> 
int semop(int semid,struct sembuf *sops,size_t nsops);
----该函数可以原子地执行一组用户定义的，在标识符semid相关的信号量集上进行的信号量操作
----sops指向一个元素操作数组，nsops指定了sops数组中元素操作的数目
----返回：成功返回０，否则返回-1并设置errno

struct sembuf{
	unsigned short sem_num;  /* semaphore number */
    short          sem_op;   /* semaphore operation */
    short          sem_flg;  /* operation flags */
};
