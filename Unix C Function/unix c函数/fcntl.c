APUE-p65
#include<fcntl.h>
int fcntl(int filedes,int cmd,...);//改变文件的状态
int fcntl(int fd,int cmd,long arg);
int fcntl(int fd,int cmd,struct flock * lock);
 
----filedes为需要修改文件状态的文件描述符，cmd为操作的命令，第三个参数通常是一个整数，其意义根据第二个参数的不同而不同。
----函数返回值和命令有关。
----功能：fcntl是一个通用函数，可用来检索和修改／与打开的文件描述符相关联的标志符。
----fcntl函数相当于一个文件操作的大集合，函数均可以用fcntl函数代替，例如dup等。
----返回值: 成功则返回0，若有错误则返回-1，错误原因存于errno.
----函数说明: fcntl()用来操作文件描述词的一些特性。参数fd代表欲设置的文件描述词，参数cmd代表欲操作的指令,有以下几种情况:
	F_DUPFD用来查找大于或等于参数arg的最小且仍未使用的文件描述词，并且复制参数fd的文件描述词。执行成功则返回新复制的文件描述词。请参考dup2()。F_GETFD取得close-on-exec旗标。若此旗标的FD_CLOEXEC位为0，代表在调用exec()相关函数时文件将不会关闭。
	F_SETFD 设置close-on-exec 旗标。该旗标以参数arg 的FD_CLOEXEC位决定。
	F_GETFL 取得文件描述词状态旗标，此旗标为open（）的参数flags。
	F_SETFL 设置文件描述词状态旗标，参数arg为新旗标，但只允许O_APPEND、O_NONBLOCK和O_ASYNC位的改变，其他位的改变将不受影响。
	F_GETLK 取得文件锁定的状态。
	F_SETLK 设置文件锁定的状态。此时flcok 结构的l_type 值必须是F_RDLCK、F_WRLCK或F_UNLCK。如果无法建立锁定，则返回-1，错误代码为EACCES 或EAGAIN。
	F_SETLKW F_SETLK 作用相同，但是无法建立锁定时，此调用会一直等到锁定动作成功为止。若在等待锁定的过程中被信号中断时，会立即返回-1，错误代码为EINTR。参数lock指针为flock 结构指针，定义如下
	struct flcok{
		short int l_type; //锁定的状态
		short int l_whence;//决定l_start位置
		off_t l_start; //锁定区域的开头位置
		off_t l_len; //锁定区域的大小
		pid_t l_pid; //锁定动作的进程
	};
	l_type 有三种状态:
	F_RDLCK 建立一个供读取用的锁定
	F_WRLCK 建立一个供写入用的锁定
	F_UNLCK 删除之前建立的锁定
	l_whence 也有三种方式:
	SEEK_SET 以文件开头为锁定的起始位置。
	SEEK_CUR 以目前文件读写位置为锁定的起始位置
	SEEK_END 以文件结尾为锁定的起始位置。 


#include<fcntl.h>
#include<unistd.h>

static struct flock lock_it,unlock_it;
static int lock_fd;

void my_lock_init(char *pathname)
{
	....unp2 p660
}


void my_lock()
{
	int rc;
	whlie((rc=fcntl(lock_fd,F_SETLKW,&lock_it))<0)
	{
		if(errno==EINTR)
			continue;
		else
			perror("...");
	}
}

void my_lock_release()
{
	if((fcntl(lock_fd,F_SETLKW,&unlock_it))<0)
		perror("---");
}




#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(){
	int fd;
	int flag;
	char *p="1st linux";
	char *q="2nd linux";
	fd=open("1.c",O_WRONLY);
	if(fd==-1){
		perror("fail to open");
		return 1;
	}
	if(write(fd,p,strlen(p))==-1){//输入新内容，该内容会覆盖部分旧内容
	 	perror("fail to write");
		return 1;
	}
	flag=fcntl(fd,F_GETFL,0);//先使用F_GETFL命令得到文件标志状态
	if(flag==-1){
		perror("fail to fcntl");
		return 1;
	}
	flag |=O_APPEND;//将文件状态标志添加“追加写”选项(这个是或操作)
	if(fcntl(fd,F_SETFL,flag)==-1){//将文件状态修改为追加写
		perror("fcntl");
		return 1;
	}
	if(write(fd,q,strlen(q))==-1){
		perror("fail to write");
		return 1;
	}
	close(fd);
	return 0;
}




#include<stdio.h>
#include<fcntl.h>

int main(int argc,char *argv[]){
	int val;
	if(argc!=2)perror("Usage...");
	val=fcntl(atoi(argv[1]),F_GETFL,0);
	switch(val&0_ACCMODE){
		case O_RDONLY:
			printf("read only\n");
			break;
		case O_WRONLY:
			printf("write only\n");
			break;
	   case O_RDWR:
			printf("read write\n");
			break;
	   default:
	        perror("unknown access mode");
	}
	if(val&O_APPEND)
		printf(",append");
	if(val&O_NONBLOCK)
		printf(",nonblocking");
	if(val&O_SYNC)
		printf(",synchronous writes");
#if !defined(_POSIX_C_SOURCE)&&defined(O_FSYNC)&&(O_FSYNC!=O_SYNC)
	if(val&O_FSYNC)
		printf(",synchronous writes");
#endif
	putchar('\n');
	return 0;
}




