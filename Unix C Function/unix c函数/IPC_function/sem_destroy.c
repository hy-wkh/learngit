#include<semaphore.h>
int sem_destroy(sem_t *sem);
----销毁一个参数sem引起的，前面已经初始化的无名信号量
----成功返回０，否则返回-1并设置errno
