//读写锁支持的唯一属性是进程共享属性
#include<pthread.h>
int pthread_rwlockattr_init(pthread_rwlockattr_t *attr);
int pthread_rwlockattr_destroy(pthread_rwlockattr_t *attr);
int pthread_rwlockattr_getpshared(const pthread_rwlockattr_t *restrict attr,
								  int *restrict pshared);
int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *attr,
								  int pshared);







