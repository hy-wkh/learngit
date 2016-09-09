#include <signal.h>
int  sigqueue(pid_t pid, int sig, const union sigval value);
----union sigval可以装载一个指针，也可以装载一个整数（p237）
----sigqueue函数向ID为pid的进程发送带有值为value的信号signo,设置了struct sigaction结构的sa_flags字段的SA_SIGINFO，并被送往接收进程
----返回：成功返回０，失败返回-1并设置errno
union sigval{
    int   sival_int;
    void *sival_ptr;
};



