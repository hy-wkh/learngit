
#include<signal.h>
int sigwait(const sigset_t *restrict sigmask,
			int *restrict signo);
----sigmask是一个指向信号集的指针（在此信号集中的信号是能使sigwait返回的指针，sigsuspend正好相反）
----功能：该函数一直阻塞到*sigmask指定的任何一个信号被挂起为止，然后从挂起信号集中删除那个信号，并解除对它的阻塞。当函数返回时，从挂起信号集中删除的信号的个数被存储在signo指向的那个位置
----返回：成功返回０，失败返回-1并设置errno
----sigwait没有改变进程的信号掩码。sigmask中的信号应该在调用sigwait之前被阻塞起来

The  sigwait()  function suspends execution of the calling thread until
       one of the signals specified in the signal  set  sigmask  becomes  pending.
       The  function  accepts  the signal (removes it from the pending list of
       signals), and returns the signal number in sig.








