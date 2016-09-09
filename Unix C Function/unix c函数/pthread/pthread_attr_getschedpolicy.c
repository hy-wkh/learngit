#include <pthread.h>
int pthread_attr_getschedpolicy(const pthread_attr_t *attr, int *policy);
----该函数负责获取调度策略

int pthread_attr_setschedpolicy(pthread_attr_t *attr, int policy);
----该函数负责设置一个属性对象的调度策略
----attr是一个指向属性对象的指针，第二个参数是一个指向要设置的值的指针，对pthread_attr_getschedpolicy来说，该参数指向一个要获取的值的指针
----这两个函数成功都返回０，否则返回一个非０的错误码。
