sigpending（查询被搁置的信号）  
相关函数  signal，sigaction，sigprocmask，sigsuspend
#include<signal.h>
int sigpending(sigset_t *set);
----sigpending()会将被阻塞的信号集合由参数set指针返回。该函数可以用来判定哪些信号是设置为阻塞并处于未决状态的
----如果参数set的值是NULL,则不会更改信号屏蔽字，这种方法用于得到当前进程的信号屏蔽字
----成功则返回0，如果有错误则返回-1。
 
错误代码 :
EFAULT 参数set指针地址无法存取
EINTR 此调用被中断。
