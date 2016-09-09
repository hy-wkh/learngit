#include<semaphore.h>
int sem_getvalue(sem_t *sem,int *sval);
----该函数允许用户检测一个命名信号量或者无名信号量的值。这个函数在不影响信号量状态的情况下，用信号量sem的值来设置sval引用的整数
----成功返回０，否则返回-1并设置errno
