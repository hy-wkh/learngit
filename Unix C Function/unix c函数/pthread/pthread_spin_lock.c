#include<pthread.h>
int pthread_spin_init(pthread_spinlock_t *lock,int pshared);
----pshared：表示进程共享属性

int pthread_spin_destroy(pthread_spinlock_t);

int pthread_spin_lock(pthread_spinlock_t *lock);
----该函数对自旋锁进行加锁，在获取锁之前一直忙等

int pthread_spin_trylock(pthread_spinlock_t *lock);
----该函数对自旋锁进行枷锁，但不能忙等

int pthread_spin_unlock(pthread_spinlock_t *lock);
----对自旋锁解锁

----返回：对所有函数，成功返回０，否则返回错误编码




