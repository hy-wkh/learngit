/*
sigismember（测试某个信号是否已加入至信号集里）  
 #include<signal.h>
 int sigismember(const sigset_t *set,int signum);
----set是一个信号集，signum是信号编号
----sigismember()用来测试参数signum 代表的信号是否已加入至参数set信号集里。如果信号集里已有该信号则返回1，否则返回0。
----返回值: 信号集已有该信号（signum所对应的位已经被设置）则返回1，没有（未设置）则返回0。如果有错误则返回-1。
----错误代码:
	EFAULT 参数set指针地址无法存取
	EINVAL 参数signum 非合法的信号编号
*/
