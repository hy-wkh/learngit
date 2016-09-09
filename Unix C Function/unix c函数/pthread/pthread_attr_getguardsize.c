#include <pthread.h>
int pthread_attr_getguardsize(const pthread_attr_t *attr, 
							　size_t *guardsize);
----用来查看警戒参数


int pthread_attr_setguardsize(pthread_attr_t *attr, 
							　size_t guardsize);
----在一个属性对象中设置了用来控制栈溢出的警戒参数，如果参数guardsize为０，栈就是无警戒的。实现为一个非０的guardsize至少分配了guardsize的额外内存

----这两个函数成功都返回０，否则返回一个非０的错误码。

