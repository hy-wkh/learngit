#include<pthread.h>
int pthread_attr_getstacksize(const pthread_attr_t *restrict attr,
							  size_t *restrict stacksize);
----该函数读取线程属性stacksize


int pthread_attr_setstacksize(pthread_attr_t *attr,
							  size_t stacksize);
----该函数设置线程属性stacksize

----stacksize控制着线程栈末尾之后用以避免栈溢出的扩展内存的大小








