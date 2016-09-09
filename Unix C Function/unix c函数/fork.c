/*
#include<unistd.h>
pid_t fork();
----fork函数创建一个新进程，之后两个进程相互独立运行。
----返回值是一个进程的ID，对于返回值，有三种情况：
	1.fork函数向父进程返回新创建的子进程的ID
	2.fork函数向子进程返回0。由于系统的0号进程是内核进程，所以子进程的进程号不可能是0,由此区别父进程和子进程。
	3.如果出错，fork函数返回-1
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	pid_t pid;
	pid=fork();
	if(pid<0){
		perror("fail to fork!\n");
		exit(1);
	}else if(pid==0){
		printf("This is child,pid is : %u",getpid());
	}else{
		printf("ppid= %u ,child id = %u\n",getpid(),pid); //为什么返回的是一样的？？？
	}
return 0;
}

/*
----由于在调用fork函数时，复制了父进程的堆栈段，所以两个进程都停留在fork函数中，等待返回。因此，fork会返回两次，一次是在父进程中返回，另一次是在子进程中返回，这两次的返回值是不一样的。
----新进程和父进程地位是平等的，先执行哪一个取决于系统的调度算法。
*/




