#include <signal.h>
int pthread_sigmask(int how, const sigset_t *set, sigset_t *oldset);
见man或usp_p347或apue_p364

int sigwait(const sigset_t *restrict set,int *restrict sig);
----set指定了线程等待的信号集，返回时，signo指向的整数将包含发送信号的数量
	   The sigwait() function suspends execution of the calling thread until one of the sig‐
       nals specified in the signal set set becomes pending.  The function accepts the  sig‐
       nal  (removes  it from the pending list of signals), and returns the signal number in
       sig.


