/*
#include<unistd.h>
char *getcwd(char *buf,size_t size);
----buf表示存储当前工作目录的路径名的缓冲区（该缓冲区可以容纳路径名的字符数加上一个'\0'结束符的长度）。
----size表示该缓冲区的大小。
----返回值：如果成功得到当前工作目录的路径名，则返回缓冲区的首地址，失败则返回NULL
----功能：得到进程的当前工作目录，并将这个目录的字符串形式存储在用户提供的缓冲区中。
*/
#include<stdio.h>
#include<unistd.h>
#define M 1024
int main(){
	pid_t pid;
	char buf[1024];
	if((chdir("/home/hy/amy"))==-1){
		perror("fail to chdir");
		return 1;
	}
	if((getcwd(buf,M))==NULL){
		perror("fail to getcwd");
		return 1;
	}
	printf("%s\n",buf);
	pid=fork();
	if(pid==-1){
		perror("fail to fork");
		return 1;
	}else if(pid==0){
		if((getcwd(buf,M))==NULL){
			perror("fail to getcwd 2");
			return 1;
		}
		printf("%s\n",buf);
	}else{
		if(wait(NULL)==-1){
			perror("fail to wait");
			return -1;
		}
	}
	return 0;
}
/*
hy@hy-K53BE:~/桌面$ cc -o ff getcwd.c
hy@hy-K53BE:~/桌面$ ./ff
/home/hy/amy
/home/hy/amy
*/













