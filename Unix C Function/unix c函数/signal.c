


/*
signal（设置信号处理方式,signal函数设置指定信号的处理函数，这个处理函数通常是用户自己定义的）  
#include<signal.h>
void (*signal(int signum,void(* func)(int)))(int);
----signum是需要加载处理的信号的编号，例如SIGKILL等，该编号是一个宏，其本质是一个整数，定义在signal.h中
----func是一个函数指针，这个函数捕捉第一个函数指定的信号，并对其进行处理。
----signal()会依参数signum 指定的信号编号来设置该信号的处理函数。当指定的信号到达时就会跳转到参数func指定的函数执行。signal函数的第二个参数的值是以下３种中的一种：
	***SIG_IGN 忽略参数signum指定的信号。
	***SIG_DFL 将参数signum 指定的信号重设为核心预设的信号处理方式。（关于信号的编号和说明，请参考附录D）
	***其他已定义的函数的指针：表示用户自己的处理函数处理此信号，该函数成为信号处理程序（signal handler）.信号处理函数原型为void handler(int);
----返回值: signal函数的返回值也是一个函数指针，这个函数指向上一次的信号处理程序，因此这个函数和signal的第二个参数所表示的函数的原型一致，如果出错，函数返回SIG_ERR
----在信号发生跳转到自定的func处理函数执行后，系统会自动将此处理函数换回原来系统预设的处理方式，如果要改变此操作请改用sigaction()。
 */
#include<stdio.h>
#include<signal.h>

void handler(int signo){
	switch(signo){
		case SIGUSR1:
			  printf("parent:catch SIGUSR1\n");
			  break;
		case SIGUSR2:
			  printf("child:catch SIGUSR2\n");
			  break;
		default:
			  printf("shouldn't be here\n");
			  break;
	}
}

int main(){
	pid_t ppid,cpid;
	/*为两个信号设置信号处理程序*/
	if(signal(SIGUSR1,handler)==SIG_ERR){
		perror("can't set handler SIGUSR1....");
		return 1;
	}
	if(signal(SIGUSR2,handler)==SIG_ERR){
		perror("fail to set SIGUSR2....");
		return 1;
	}
	ppid=getppid();
	if((cpid=fork())<0){
		perror("fail to fork");
		return 1;
	}else if(cpid==0){//向父进程发送SIGUSR1信号
		if(kill(ppid,SIGUSR1)==-1){
			perror("fail to send signal1");
			return 1;
		}
		while(1);//死循环，等待父进程的信号
	}else{
		sleep(1);//休眠，保证子进程先运行
		if(kill(cpid,SIGUSR2)==-1){
			perror("fail to send signal2");
			return 1;
		}
		printf("kill child\n");
		if(kill(cpid,SIGKILL)==-1){//发送SIGKILL信号，杀死子进程
			perror("fail to send signal3");
			return 1;
		}
		if(wait(NULL)==-1){//回收子进程状态，避免僵尸进程
			perror("fail to wait");
			return 1;
		}
	}
	return 0;
}












