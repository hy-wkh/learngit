/*#include<stdlib.h>
vid abort();
----功能：该函数（将SIGABRT发送给调用进程）异常终止一个进程
----进程调用abort函数异常结束时会收到一个信号，该信号的默认处理方式就是退出进程
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
	pid_t pid;
	int status;
	pid=fork();
	if(pid<0)
		perror("fail to fork");
	else if(pid==0){
		printf("exit abnormally\n");
		abort();
	}
	else{
		if(wait(status)==-1){
			perror("fail to wait");
			return 1;
		}
		if(WIFSIGNALED(status)==-1)
			printf("terminal signaled is : %d\n",WTERMSIG(status));
	}
return 0;
}












