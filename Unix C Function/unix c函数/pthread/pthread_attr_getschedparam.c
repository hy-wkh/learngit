#include <pthread.h>
int pthread_attr_getschedparam(const pthread_attr_t *attr,
                               struct sched_param *param);
----该函数负责查看调度参数

int pthread_attr_setschedparam(pthread_attr_t *attr,
                               const struct sched_param *param);
----该函数负责设置一个属性对象的参数
----attr是一个指向属性对象的指针，第二个参数为该函数要设置的值的指针和一个要从pthread_attr_getschedparam获得的指针

----这两个函数成功都返回０，否则返回一个非０的错误码。
struct sched_param{
     int sched_priority;     /* Scheduling priority */
};
