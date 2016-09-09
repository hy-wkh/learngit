#include<semaphore.h>
int sem_post(sem_t *sem);
----该函数实现了信号量signal操作，
	如果没有线程阻塞在sem上，那么函数就对信号量sem的值进行增量操作
	如果至少有一个线程阻塞在sem上，那么信号量的值就为０，这时该函数使某个由于sem_wait而阻塞在sem上的线程返回，信号量的值仍然为０

