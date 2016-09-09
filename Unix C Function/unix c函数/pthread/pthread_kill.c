#include<signal.h>
int pthread_kill(pthread_t thread,int signo);
----该函数用于将信号发送给线程，可以传一个０值的signo来检查线程是否存在
----成功返回０,否则返回一个非０的错误码








