#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	pid_t pid=fork();
	if(pid<0){
		perror("fail to fork!\n");
		exit(0);
	}else if(pid==0){
		if(execl("/bin/ls","ls","-l","/home/hy/",NULL)<0){
			perror("fail to execl\n");
			exit(0);
		}
		printf("the child is not hello\n");//这里应该永远不会执行，因为调用ececl后，这里的代码被hello程序的所取代了，绝不会执行到这个位置。
		exit(0);
	}
	printf("the parent\n");
return 0;
}






