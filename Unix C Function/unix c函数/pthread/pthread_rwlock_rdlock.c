#include <pthread.h>
int pthread_rwlock_rdlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_tryrdlock(pthread_rwlock_t *rwlock);
----允许为读操作获取一个读写锁

#include <pthread.h>
int pthread_rwlock_trywrlock(pthread_rwlock_t *rwlock);
int pthread_rwlock_wrlock(pthread_rwlock_t *rwlock);
----允许为写操作获取一个读写锁

#include <pthread.h>
int pthread_rwlock_unlock(pthread_rwlock_t *rwlock);
----该函数会将锁释放掉


----返回：这些函数成功返回０，否则返回一个非０错误码
