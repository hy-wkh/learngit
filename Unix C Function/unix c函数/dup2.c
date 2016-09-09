
#include<unistd.h>
int dup2(int filedes1,int filedes2);
----filedes1表示需要复制的文件描述符
----filedes2表示所复制的文件使用新的文件描述符
----返回：成功复制一个文件的描述符则返回新的文件描述符，失败则返回－1;
----功能：和dup类似，不过dup2允许使用第二个参数指定将文件描述符复制到哪一个文件描述符上。
----dup2会将指定的目的描述符所代表的文件关闭，之后再进行复制
----例如：dup2(fd[1],STDOUT_FILENO)将标准输出重定向到fd[1]（即用fd[1]做标准输出）
	：dup2(fd[0],STDIN_FILENO);//将fd[0]做标准输入（即:将管道的输出做标准输入）
----函数返回的新的文件描述符与参数fildes1共享同一个系统文件表
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>

int main(){
	int fd;
	fd=open("1.c",O_RDWR);
	if(fd==-1){
		perror("fail to open");
		return 1;
	}else 
		printf("open ok\n");
	
	if(dup2(fd,1)==-1){
		perror("fail to dup");
		return 1;
	}else 
		printf("dup success\n");
printf("hello");
return 0;
}








