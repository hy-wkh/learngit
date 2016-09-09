kill（传送信号给指定的进程,然后进程就会执行信号处理函数）  
#include<signal.h>
int kill(pid_t pid,int sig);
----sig表示要发送的信号的编码
----kill()可以用来送参数sig指定的信号给参数pid指定的进程。（kill函数可以向某个进程或者某个进程组发送信号，通过传递信号的方式实现进程间的通信）
	参数pid有几种情况:
	pid>0 将信号传给进程识别码为pid 的进程。
	pid=0 向调用程序的进程组成员发送信号
	pid=-1 向所有它有权发送信息的进程发送信号
	pid<0的其他负数 将信号发送到组ID等于｜pid｜的进程组中
	参数sig代表的信号编号可参考p184表８-1
----返回值 :执行成功则返回0，如果有错误则返回-1。
----错误代码:
	EINVAL 参数sig 不合法
	ESRCH 参数pid 所指定的进程或进程组不存在
	EPERM 权限不够无法传送信号给指定进程
----根用户可以向系统内任意进程发信号，因此根用户可以杀死任何恶意进程，同时得到根用户权限的恶意进程也可以杀死系统内的其他进程。
*/
//#include<unistd.h>
#include<signal.h>
#include<stdio.h>
//#include<sys/types.h>
//#include<sys/wait.h>
int main(){
	pid_t pid;
	int status;
	if(!(pid= fork())){
		printf(“Hi I am child process!\n”);
		sleep(10);
		return;
	}else{
		printf(“send signal to child process (%d) \n”,pid);
		sleep(1);
		kill(pid ,SIGABRT);
		wait(&status);
		if(WIFSIGNALED(status))//见wait.c
		printf(“chile process receive signal %d\n”,WTERMSIG(status));
	}
	return 0;
}
/*
执行  sen signal to child process(3170)
Hi I am child process!
child process receive signal 6
*/
