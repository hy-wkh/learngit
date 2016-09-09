#include <pthread.h>
int pthread_attr_getscope(const pthread_attr_t *attr, int *scope);
----该函数用来查看竞争范围


int pthread_attr_setscope(pthread_attr_t *attr, int scope);
----该函数用来设置一个属性对象的竞争范围
----attr是一个指向属性对象的指针，scope对应于要为该函数设置的值，以及一个指向要从pthread_attr_getscope获得的指针


----scope的值可能是:
       PTHREAD_SCOPE_SYSTEM
       PTHREAD_SCOPE_PROCESS
	
----这两个函数成功都返回０，否则返回一个非０的错误码。
