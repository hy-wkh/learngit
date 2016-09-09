#include<pthread.h>
int pthread_barrier_init(pthread_barrier_t *restrict barrier,
						 const pthread_barrierattr_t *restrict attr,
						 unsigned int count);
----该函数对屏障分配资源并进行初始化
----count指定在所有线程继续运行前，必须到达屏障的线程数目
	attr指定屏障对象的属性

int pthread_barrier_destroy(pthread_barrier_t *barrier);
----该函数释放相应的资源

int pthread_barrier_wait(pthread_barrier_t *barrier);
----调用该函数的线程在屏障计数未满足时，会进入休眠状态，如果该线程是最后一个调用这个函数的线程，就满足了屏障计数，所有的线程都会被唤醒
----对任意一个线程，该函数返回PTHREAD_BARRIER_SERIAL_THREAD，剩下的线程看到的返回值是０,这使得一个线程可以作为主线程，它可以工作在其他所有线程已完成的工作结果上







