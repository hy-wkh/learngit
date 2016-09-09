/*#include<signal.h>
int sigsuspend(const sigset_t *sigmask);
----sigmask表示需要屏蔽的信号集
----功能：进程的信号屏蔽字设置为由sigmask指向的值，在捕捉到一个信号或发生了一个会终止该进程的信号之前，该进程被挂起。如果捕捉到一个信号而从该信号处理程序返回，则sigsuspend返回，并且该进程的信号屏蔽字设置为调用sigsuspend之前的值
（在执行该函数时，会使用参数所表示的需要屏蔽的信号集代替进程内部的屏蔽信号集，当信号到来并且执行完信号处理函数后，进程原来的信号集会被恢复，这个是操作系统自动完成的）
----返回：该函数没有成功返回值，如果它返回到调用者，则总是返回-1,并将errno设置为EINTR 
*/
#include<stdio.h>
#include<stdio.h>
#include<signal.h>

static void sig_int(int signo){
	perror("sig_int\n");
}

int main(){
	sigset_t newmask,oldmask,waitmask;
	perror("program start:");
	if(signal(SIGINT,sig_int)==SIG_ERR)
		perror("set signal SININT error");
	sigemptyset(&waitmask);
	sigaddset(&waitmask,SIGUSR1);
	sigemptyset(&newmask);
	sigaddset(&newmask,SIGINT);

	if(sigprocmask(SIG_BLOCK,&newmask,&oldmask)==-1)
		perror("SIG_BLOCK error");
	perror("in critical region");
	if(sigsuspend(&newmask)!=-1)
		perror("sigsuspend error");
	perror("after return from sigsuspend");
	if(sigprocmask(SIG_SETMASK,&oldmask,NULL)==-1)
		perror("SIG_SETMASK error");
	perror("exit");
return 0;
}





