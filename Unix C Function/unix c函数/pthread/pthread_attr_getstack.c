#include <pthread.h>
int pthread_attr_getstack(const pthread_attr_t *attr,
                          void **stackaddr, 
						  size_t *stacksize);
----该函数用来查看栈的参数
----attr是一个指向属性对象的指针,stackaddr和stacksize指向栈的最低可寻址地址和大小


int pthread_attr_setstack(pthread_attr_t *attr,
                          void *stackaddr, 
						  size_t stacksize);
----该函数用来设置一个属性对象的栈参数
----attr是一个指向属性对象的指针,栈的地址和大小是额外的参数

----这两个函数成功都返回０，失败返回一个非０的错误码

