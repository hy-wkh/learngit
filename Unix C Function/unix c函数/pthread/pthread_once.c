#include <pthread.h>
int pthread_once(pthread_once_t *initflag,void(*init_routine) (void));
----pthread_once_t once_control=PTHREAD_ONCE_INIT;//对参数once_control进行静态初始化
----参数initflag必须是一个非本地变量，而且必须被初始化为PTHREAD_ONCE_INIT;该函数用来确保初始化程序init_routine只被调用一次
----成功返回０，否则返回一个非０错误码



