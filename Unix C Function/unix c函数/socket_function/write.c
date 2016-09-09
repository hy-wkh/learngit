
#include<unistd.h>
ssize_t write(int filedes,void *buf,size_t nbytes);
----filedes:是一个文件描述符
----buf:表示缓冲区，该缓冲区的内容输出到文件中
----nbytes:表示需要写的字节数
----ssize_t :有符号整型　s_size:无符号整型
----功能：将缓冲区的内容输出到一个已经打开的文件中
----返回值：返回值是实际写到文件中的字节数，出错则返回-1

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
int main(){
	int p;//open返回值是int型
	p=open("test.c",O_RDWR);//O_RDWR需要fcntl.h头文件
	if(p==-1){
		perror("fail to open");
		exit -1;
	}
	char buf[1024]="123456789";
	int n=write(p,buf,strlen(buf));
	//int n=write(p,...,strlen(buf));这个buf可以用一个文件代替吗？？？？？

	if(n==-1){
		perror("fail to write");
		exit -1;
	}
	printf("write success!\n");
	close(p);
	return 0;
}












