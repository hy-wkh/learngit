/*
#include<unistd.h>
int chdir(char *pathname);
----参数pathname表示将要切换到的工作目录的路径名。
----返回：如果成功改变进程的工作目录，函数返回０，失败返回-1.
----功能：改变进程的工作目录。
----当进程的工作目录改变后，所有新创建的文件均在新目录下，所有程序中引用的相对路径名也全部以该目录为基准开始引用。
----子进程的工作目录的改变不影响到父进程，父进程的工作目录的改变会影响到子进程。
----注：执行完这个程序后，在终端运行pwd显示的仍是以前的目录，因为pwd并没有执行chdir函数。

int fchdir(int fd);
----用打开的文件描述符来指定新的当前工作目录

*/
#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
int main(){
	int fd;
	char *p="Hello,nice to meet you!";

	if((chdir("/home/hy/amy/"))==-1){
		perror("fail to chdir");
		return 1;
	}
	if((fd=open("1.c",O_CREAT|O_RDWR))==-1){		
		perror("open error");
		return 1;
	}
	if((write(fd,p,strlen(p)))==-1){
		perror("fail to write");
		return 1;
	}
	close (fd);
return 0;
}













