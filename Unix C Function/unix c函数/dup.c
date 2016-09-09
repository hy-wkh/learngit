
#include<unistd.h>
int dup(int filedes);//复制文件描述符
----filedes :表示需要复制的文件。
----返回：如果成功复制一个文件返回新的文件描述符，失败返回-1;
----dup函数总是找到进程文件表中第一个可用的文件描述符，将参数指定的文件复制到该描述符后，返回这个描述符。(利用这一特性，可以知道进程中最小可用的文件描述符。)
----dup复制的文件必须是一个已经打开的有效文件。

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	int fd;
	fd=open("1.c",O_RDWR);
	if(fd==-1){
		perror("fail to open");
		return 1;
	}else 
		printf("open ok\n");
	if(close(1)==-1){//关闭标准输出。因为dup总是找到第一个可用的文件描述符，因此，关闭这个后，等下就可以选这个。
		perror("fail to close");
		return 1;
	}
	if(dup(fd)==-1){//复制文件到标准输出的位置
		perror("fail to dup");
		return 1;
	}else
		printf("dup ok\n");
	printf("Hello World\n"); return 0;
}
/*
hy@hy-K53BE:~/桌面$ cc -o ff dup.c
hy@hy-K53BE:~/桌面$ ./ff
open ok
hy@hy-K53BE:~/桌面$ cat 1.c
dup ok
Hello World
*/
   





