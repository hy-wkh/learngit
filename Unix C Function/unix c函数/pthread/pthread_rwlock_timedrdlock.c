#include<pthread.h>
#include<time.h>
int pthread_rwlock_timedrdlock(pthread_rwlock_t *restrict rwlock,
              				   const struct timespec *restrict abs_timeout);

int pthread_rwlock_timedwrlock(pthread_rwlock_t *restrict rwlock,
             				   const struct timespec *restrict abs_timeout);

----带有超时的读写锁加锁函数，使应用程序在获取读写锁时避免陷入永久阻塞






