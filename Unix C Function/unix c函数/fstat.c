
#include<sys/stat.h>
int fstat(int filedes,struct stat *buf);
----filedes表示一个已经打开的文件的文件描述符。
----fstat函数从内核中取得文件的状态并将其存储在参数buf所表示的stat结构中返回给用户。
----返回：成功得到文件的状态信息则返回０，失败返回－1
----fstat函数可以从一个打开文件的文件描述符上得到相关信息。
----fstat函数作用与stat完全相同，不同之处在于传入的参数为已打开的文件描述符

#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int fd;
	//struct stat buf;
	struct stat *buf;
	buf=malloc(sizeof(struct stat)*1);
	fd=open("/home/hy/桌面/test.c",O_RDONLY);
	fstat(fd,buf);
	printf("%d\n",buf->st_size);
	return 0;
}
/*
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	int fd;
	struct stat buf;
	fd=open("/home/hy/桌面/test.c",O_RDONLY);
	fstat(fd,&buf);
	printf("%d\n",buf.st_size);
	return 0;
}
*/










