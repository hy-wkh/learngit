/*
#include<unistd.h>
pid_t getpid();  //返回当前进程的进程PID
pid_t getppid();  //返回当前进程的父进程PID
----如果父进程先于子进程结束，这时候子进程将由0号进程也就是init进程收养。这时候父进程就是init进程
*/
#include<unistd.h>
#include<stdio.h>

int main(){
	pid_t i1,i2;
	i1=getpid();
	i2=getppid();
	printf("%d %d\n",i1,i2);
	return 0;
}











