#include<semaphore.h>
int sem_wait(sem_t *sem);
----该函数实现wait操作，如果信号量的值为０，则调用进程就一直阻塞直到一个相应的sem_post解除了它的阻塞为止，或者它被信号中断为止
----成功返回０，否则返回-1并设置errno

int sem_trywait(sem_t *sem);
----该函数和sem_wait类似，只是在试图对一个为０的信号量进行减量操作时，它不阻塞，而是返回－1并设置errno为EAGAIN
----成功返回０，否则返回-1并设置errno

int sem_timedwait(sem_t *sem,const struct timespec *abs timeout);
