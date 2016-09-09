
#include<unistd.h>
off_t lseek(int filedes,off_t offset,int whence);
----filedes是一个已经打开的文件的文件描述符。offset和whence需要一起解释
----当whence是SEEK_SET,表示将该文件的文件偏移量设置为距文件开始位置offset个字节。
	当whence是SEEK_CUR,表示将该文件的文件偏移量设置为当前文件偏移位置增加offset个字节，offset的值可以是一个负数。
	当whence是SEEK_END,表示将该文件的文件偏移量设置为当前文件结尾位置增加offset个字节，offset可以是一个负数。
----返回值：如果成功设置文件偏移量，则返回所设置的新的偏移量。否则返回-1.
----功能：lseek函数可以更改打开文件的偏移量，实现在文件内部的定位。
----lseek(fd,0,SEEK_CUR);可以得到当前文件的偏移量。
----如果三个参数超过文件本身的长度，会造成一个磁盘文件的空洞，这时该空洞并不占用磁盘空间。

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
	int fd;
	off_t off;
	fd=open("1.c",O_RDWR);
	if(fd==-1){
		perror("fail to open");
		return 1;
	}
	printf("locating\n");
	off=lseek(fd,5,SEEK_CUR);
	if(off==-1){
		perror("fail to lseek");
		return 1;
	}
	printf("writing\n");
	if(write(fd,"hello\n",6)==-1){
		perror("fail to write");
		return 1;
	}
	close(fd);
	return 0;
}








