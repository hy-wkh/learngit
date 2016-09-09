#include <pthread.h>
int pthread_attr_getinheritsched(const pthread_attr_t *attr,
                                        int *inheritsched);
----该函数负责查看调度继承策略
----

int pthread_attr_setinheritsched(pthread_attr_t *attr,
                                        int inheritsched);
----负责为一个属性对象设置调度继承策略
----attr是一个指向属性对象的指针，第二个参数为该函数要设置的值和一个要从pthread_attr_getinheritsched获得的指针

----这两个函数成功都返回０，否则返回一个非０的错误码。





