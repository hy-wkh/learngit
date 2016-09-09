//屏障属性：（目前屏障属性只有进程共享属性）
#include<pthread.h>
int pthread_barrierattr_init(pthread_barrierattr_t *attr);
int pthread_barrierattr_destroy(pthread_barrierattr_t *attr);
int pthread_barrierattr_getpshared(const pthread_barrierattr_t *restrict attr,
								   int *restrict pshared);
int pthread_barrierattr_setpshared(pthread_barrierattr_t *attr,
								   int pshared);






