
#include<unistd.h>
ssize_t read(int filedes,void *buf,size_t nbytes);
----filedes :表示一个文件描述符。
----buf :表示一个缓冲区，将文件内容读入到该缓冲区中。
----nbytes :表示需要读取的字节数。
----返回值：read函数的返回值是实际读出字节数，其值有三种情况：(字节数，０，-1)
	1.返回值和nbytes相等。
	2.文件剩余字节数小于nbytes,返回值是实际读出的字节数。如果文件已经达到末尾则返回值为０。
	3.读操作出现错误，返回值为-1。
----注：read函数不会在读入的内容后面添加'\0'结束符，（这和ｃ语言函数库中提供的read不一样），如果需要的话必须手动添加。

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
	int p;//open返回值是int型
	p=open("test.c",O_RDWR);//O_RDWR需要fcntl.h头文件
	if(p==-1){
		perror("fail to open");
		exit -1;
	}
	char buf[1024];
	int n=read(p,buf,1023);
	if(n<=0){
		perror("fail to read");
		exit -1;
	}
	buf[n]='\0';
	printf("%s\n",buf);
	close(p);
	return 0;
}





