/*
sigaction（查询或设置信号处理方式）  
相关函数 :signal，sigprocmask，sigpending，sigsuspend
#include<signal.h>
int sigaction(int signum,
			  const struct sigaction *restrict act,
			  struct sigaction *restrict oldact);
----signo:表示注册的信号编号
----act和oldact是两个sigaction结构的指针，内核使用参数act指向的结构设置信号处理函数，将原来的值存储在oldact所指向的内存区域内。
----功能：函数会依参数signum指定的信号编号来设置该信号的处理函数。参数signum可以指定SIGKILL和SIGSTOP以外的所有信号。
如参数结构sigaction定义如下:
	struct sigaction{
		void (*sa_handler) (int);//信号处理函数
		sigset_t sa_mask;//屏蔽信号集
		int sa_flags;//信号选项
		void (*sa_sigaction) (int,siginfo_t,void*);//替代sa_handler的信号处理函数
	};
	***sa_handler此参数和signal()的参数func相同，代表新的信号处理函数，其他意义请参考signal()。(sa_handler有两个特殊值SIG_DFL和SIG_IGN)
	***sa_mask表示屏蔽的信号集，在设置信号处理函数时，sa_mask中所表示的信号将被添加到信号屏蔽字中。
	***第４个成员变量表示一个替代的信号处理函数，当信号选项SA_SIGINFO被设置(即非０)时，使用此信号处理函数。该函数有３个参数，这３个参数都由内核传递，分别是信号编号，信号产生的详细信息，进程的上下文{
		这个处理程序的格式必须如下所示：
		void func(int signo,siginfo_t *info,void context);
		其中：
		struct siginfo_t{
			int si_signo;	//信号码
			int si_code;	//引发信号的原因
			union sigval si_value;	//信号值
		};
	}
	si_code定义的值：ｐ236
	***sa_flags表示信号选项，用来设置信号处理的其他相关操作，下列的数值可用(见手册p271):(或见man)
		OR 运算（|）组合:
		SA_NOCIDSTOP : 如果参数signum为SIGCHLD，则当子进程暂停时并不会通知父进程
		SA_ONESHOT/SA_RESETHAND:当调用新的信号处理函数前，将此信号处理方式改为系统预设的方式。
		SA_RESTART:被信号中断的系统调用会自行重启
		SA_NOMASK/SA_NODEFER:在处理此信号未结束前不理会此信号的再次到来。
		如果参数oldact不是NULL指针，则原来的信号处理方式会由此结构sigaction 返回。
----返回值 :如果成功注册了信号处理函数，则返回0，否则返回-1。
----错误代码 :
	EINVAL 参数signum 不合法， 或是企图拦截SIGKILL/SIGSTOPSIGKILL信号
	EFAULT 参数act，oldact指针地址无法存取。
	EINTR 此调用被中断
----sigaction函数可以完全代替signal函数，其功能的强大是signal函数所不能比的，sigaction函数用于注册一个信号处理函数，在注册的同时可以设定屏蔽的信号集，以及信号处理选项
*/
#include<unistd.h>
#include<signal.h>
void show_handler(struct sigaction *act){
	switch(act->sa_flags){
		case SIG_DFL:printf("default\n");break;
		case SIG_IGN:printf("Ignore\n");break;
		default:printf("0x%x\n",act->sa_handler);
	}
}
int main(){
	struct sigaction act,oldact;
	act.sa_handler=show_handler;
	act.sa_flags=SA_ONESHOT|SA_NOMASK;
	sigaction(SIGUSR1,&act,&oldact);
	int i;
	for(i=5;i<15;++i){
		printf("sa_handler of signal %2d=",i);
		sigaction(i,NULL,&oldact);
	}
	return 0;
}
/*
执行  sa_handler of signal 5 = Default action
sa_handler of signal 6= Default action
sa_handler of signal 7 = Default action
sa_handler of signal 8 = Default action
sa_handler of signal 9 = Default action
sa_handler of signal 10 = 0x8048400
sa_handler of signal 11 = Default action
sa_handler of signal 12 = Default action
sa_handler of signal 13 = Default action
sa_handler of signal 14 = Default action
*/
