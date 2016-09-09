#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

char *const ls_envp[]={"PATH=/bin:/usr/bin","TERM=console",NULL};
char *const ls_argv[]={"ls","-l","/home/hy/桌面",NULL};

int main(){
	pid_t pid;
	pid=fork();
	if(pid<0){
		perror("fail to fork!");
		exit(-1);
	}
	if(pid!=0){
	//if(execl("/home/hy/桌面/fff",NULL)==-1){
	//if(execlp("./fff",NULL)==-1){//标记1
	//if(execle("/home/hy/桌面/fff",NULL,ls_envp)==-1){
	//if(execv("/bin/ls",ls_argv)==-1){	
	//if(execvp("./fff",ls_argv)==-1){
	if(execve("/bin/ls",ls_argv,ls_envp)==-1){
		perror("fail to exec");
		exit(-1);
	}
	}
	
	return 0;
}

/*
标记1：
hy@hy-K53BE:~$ PATH="$PATH":./ff
hy@hy-K53BE:~$ echo $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:./ff（----注意在execlp中的执行文件也是./fff）
*/




