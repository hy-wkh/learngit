/*
sigprocmask（用来检查或修改它的进程信号掩码）  
相关函数  signal，sigaction，sigpending，sigsuspend
#include<signal.h>
int sigprocmask(int how,const sigset_t *set,sigset_t * oldset);
----how是一个整数，用来说明信号掩码的修改方式
	set指向一个信号集，在修改中要用到这个信号集，如果set为NULL,说明不需要修改。该信号集中被设置的位表示需要被屏蔽的信号
	如果oldset不为NULL,函数会将修改之前的信号集放在*oldset中返回
----函数说明: 函数可以用来改变目前的信号掩码(检测或更改信号屏蔽字)，其操作依参数how的取值来决定：
	SIG_BLOCK 新的信号掩码由目前的信号掩码和参数set 指定的信号掩码作或操作相当于mask=mask|set
	SIG_UNBLOCK 将目前的信号掩码删除掉参数set指定的信号掩码，相当于
	            mask=mask&~set
	SIG_SETMASK 设置当前屏蔽信号集为set所指向的值，相当于mask=set;
	如果参数oldset不是NULL指针，那么目前的信号遮罩会由此指针返回。
----返回值：执行成功则返回0，如果有错误则返回-1。
----错误代码:
	EFAULT 参数set，oldset指针地址无法存取。
	EINTR 此调用被中断
----阻塞一个信号被称为信号屏蔽，每个进程内部都有一个信号屏蔽字，标记被屏蔽的信号，信号屏蔽字的本质同信号集一样，是一个位向量。信号编码对应的位为１，表示屏蔽该信号，为０，表示处理该信号
*/
#include<stdio.h>
#include<signal.h>

void sig_handler(int signo){
	printf("catch SIGUSR1\n");
}
int main(){
	sigset_t set;//信号集数据结构
	if(signal(SIGUSR1,sig_handler)==-1){
		perror("fail to set handler...");
		return 1;
	}
	sigemptyset(&set);
	sigaddset(&set,SIGUSR1-1);//设置SIGUSR1
	if(sigprocmask(SIG_BLOCK,&set,NULL)==-1){//屏蔽该信号，与原屏蔽字做或操作
		perror("fail to set mask");
		return 1;
	}
	printf("SIGUSR1 NOT AVAIL...\n");
	sleep(5);//休眠，等待用户发送SIGUSR1信号
	if(sigprocmask(SIG_UNBLOCK,&set,NULL)==-1){//恢复屏蔽信号，与原屏蔽字做“取反”后“与”操作
		perror("fail to set signal_mask");
		return 1;
	}
	printf("available...");
	sleep(5);//再次休眠，等待信号
return 0;
}
