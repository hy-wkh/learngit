#include<pthread.h>
int pthread_mutexattr_init(pthread_mutexattr_t *attr);
----pthread_mutexattr_t:互斥量属性类型

int pthread_mutexattr_destroy(pthread_mutexattr_t *attr);
----互斥量属性类型的３个属性是：进程共享属性，健壮属性，类型属性

//进程共享属性
#include<pthread.h>
int pthread_mutexattr_getpshared(const pthread_mutexattr_t *restrict attr,
								 int *restrict pshared);
int pthread_mutexattr_setpshared(pthread_mutexattr_t *attr,
								 int pshared);

//互斥量健壮属性
int pthread_mutexattr_getrobust(const pthread_mutexattr_t *restrict attr,
								int *restrict robust);
int pthread_mutexattr_setrobust(pthread_mutexattr_t *attr,
								int robust);
----robust的取值有两种情况：
	PTHREAD_MUTEX_STALLED:意味着持有互斥量的进程终止时不需要采取特别的动作，这种情况下使用互斥量后的行为是未定义的，等待该互斥量解锁的应用程序会被有效的“拖住”
	PTHREAD_MUTEX_ROBUST:这个值将导致线程调用pthread_mutex_lock获取锁，而该锁被另一个进程持有，但它终止时并没有对该锁进行解锁，此线程会阻塞，从pthread_mutex_lock返回的值为EOWNERDEAD

int pthread_mutex_consistent(pthread_mutex_t *mutex);
----调用该函数可以用来指明与该互斥量相关的状态在互斥量解锁之前是一致的
----如果线程没有先调用该函数就对互斥量进行了解锁，那么其他试图获取该互斥量的阻塞线程就会得到错误码ENOTRECOVERABLE.如果发生这种情况，互斥量将不再可用。线程通过提前调用该函数，能让互斥量正常工作，这样它就可以持续被使用

//类型互斥量属性
int pthread_mutexattr_gettype(const pthread_mutexattr_t *restrict attr,
							  int *restrict type);
----该函数用来获取互斥量类型属性
int pthread_mutexattr_settype(pthread_mutexattr_t *attr,int type);
----该函数用来修改互斥量类型属性







