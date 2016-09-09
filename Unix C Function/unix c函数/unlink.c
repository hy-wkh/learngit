/*
unlink（删除文件）  
相关函数 link，rename，remove
#include<unistd.h>
int unlink(const char * pathname);
----pathname表示目录项的路径。
----unlink会删除参数pathname指定的文件,并将pathname的文件链接计数减一。如果该文件名为最后连接点，但有其他进程打开了此文件，则在所有关于此文件的文件描述词皆关闭后才会删除。如果参数pathname为一符号连接，则此连接会被删除。
----返回值: 成功则返回0，失败返回-1，错误原因存于errno
----错误代码: 
	EROFS 文件存在于只读文件系统内
	EFAULT 参数pathname指针超出可存取内存空间
	ENAMETOOLONG 参数pathname太长
	ENOMEM 核心内存不足
	ELOOP 参数pathname 有过多符号连接问题
	EIO I/O 存取错误
----unlink函数会将pathname最末端的目录项删除，并且将该目录项所对应的磁盘文件的链接数减1
----使用unlink函数应当注意，即使一个文件的链接数已经为0,只要该文件打开，程序仍可以引用该文件，包括对文件的读和写，不过这时的读写操作实际上是在对内存中缓冲区进行操作，当文件被关闭时，内存中的缓冲区消失，文件也就消失了

int unlinkat(int fd,const char *pathname,int flag);
----如果pathname是相对路径名，那么该函数计算相对于由fd文件描述符参数代表的目录的路径名
*/
#include<stdio.h>
#include<sys/stat.h>
#define MAX 1024
int main(){
	int fd;
	struct stat statbuf;
	char buf[MAX];
	int n;

	if(stat("hah.c",&statbuf)==-1){
		perror("fail to get status1");
		return 1;
	}
	printf("the number of links is: %d\n",statbuf.st_nlink);
	if(unlink("hah.c")==-1){
		perror("fail to unlink");
		return 1;
	}
	if(stat("hah.c",&statbuf)==-1){
		perror("fail to get status2");
		return 1;
	}
	printf("the number of links is: %d\n",statbuf.st_nlink);
return 0;
}









