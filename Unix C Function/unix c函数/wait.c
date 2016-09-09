/*
#include<sys/wait.h>
pid_t wait(int *staloc);
----statloc :表示保存子进程结束信息的内存空间（该参数用来保存子进程的返回信息）,如果该指针为NULL,则表示用户对这个信息并不关心；
----返回值：如果该进程没有子进程，则立即出错返回，返回值－1;否则返回得到结束信息的子进程的PID
----函数功能：调用wait函数的进程会阻塞，直到该进程的任意一个子进程结束（也就是如果还有进程没结束，需要反复调用），wait会取得结束的子进程的信息并且返回孩子进程的PID，结束信息保存在参数statloc所指向的内存空间中
----返回：
 	**函数的返回信息**成功返回pid,若出错，则返回０或－1
	**参数的返回信息**是一个整数，不同的位代表不同的信息，它们是进程正常结束状态，终止进程的信息编号和暂停进程的信息编号。这三个状态是否有效，要用linux系统提供的宏来判断：
	状态			判断宏	    	取值宏
　进程正常结束　　　WIFEXITED       WEXITSTATUS
  进程异常终止　　　WIFSIGNALED     WTERMSIG
  进程暂停			WIFSTOPPED      WSTOPSIG
*/

#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	pid_t pid;
	int status;
 	pid=fork();
	if(pid<0){
		perror("fail to fork");
		exit(1);
	}else if(pid==0){
		printf("The first,the normally!\n");
		exit(0);
	}else {
		if(wait(&status)==-1){
		perror("fail to wait!\n");
		exit(1);
		}
		if(WIFEXITED(&status)==1)//判断宏
			printf("Status is %d\n",WEXITSTATUS(status));//取值宏
	}
	pid=fork();//父进程和子进程都会从这个函数之后开始执行，也就是都会执行下面的if语句。

	if(pid<0){
		perror("fail to fork");
		exit(1);
	}else if(pid==0){
		printf("The second,the abnormally!\n");
		1/0;//除以０会产生SIGFPE信号
	}else {//？？？为什么这个语句两个进程都没有执行？？？？？
		if(wait(&status)==-1){//父进程等待子进程退出
		perror("fail to wait!\n");
		exit(1);
		}
		if(WIFSIGNALED(status)==1)
			printf("the terminal signal is %d\n",WTERMSIG(status));
	}
	return 0;
}







