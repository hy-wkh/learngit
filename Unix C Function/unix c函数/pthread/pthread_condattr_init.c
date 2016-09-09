//条件变量属性(支持进程共享属性和时钟属性)
#include<pthread.h>
int pthread_condattr_init(pthread_condattr_t *attr);
int pthread_condattr_destroy(pthread_condattr_t *attr);

//条件变量支持的进程共享属性
int pthread_condattr_getpshared(const pthread_condattr_t *restrict attr,
								int *restrict pshared);
int pthread_condattr_setpshared(pthread_cond_attr_t *attr,
								int pshared);

//条件变量支持的时钟属性(时钟属性控制计算机pthread_cond_timedwait函数的超时参数时采用的是哪个时钟)
int pthread_condattr_getclock(const pthread_condattr_t *restrict attr,
							  clockid_t *restrict clock_id);
----该函数获取可被用于pthread_cond_timedwait函数的时钟ID,在使用pthread_cond_timedwait函数前需要用pthread_condattr_t对象对条件变量进行初始化
int pthread_condattr_setclock(pthread_condattr_t *attr,
							  clockid_t clock_id);


