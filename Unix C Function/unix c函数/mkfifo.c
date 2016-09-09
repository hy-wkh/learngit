/*(unixsysp p139)
mkfifo（建立命名管道）  
相关函数  pipe，popen，open，umask
#include<sys/stat.h>
int mkfifo(const char * pathname,mode_t mode);
----pathname为指定的文件绝对路径字符串指针，mode为一个mode_t类型的权限描述符(注：fifo文件不能具有执行权限)
----mkfifo()会依参数pathname建立特殊的FIFO文件，该文件必须不存在，而参数mode为该文件的权限（mode%~umask），因此umask值也会影响到FIFO文件的权限。Mkfifo()建立的FIFO文件其他进程都可以用读写一般文件的方式存取。当使用open()来打开FIFO文件时，O_NONBLOCK旗标会有影响
	1、当使用O_NONBLOCK 旗标时，打开FIFO 文件来读取的操作会立刻返回，但是若还没有其他进程打开FIFO 文件来读取，则写入的操作会返回ENXIO 错误代码。
	2、没有使用O_NONBLOCK 旗标时，打开FIFO 来读取的操作会等到其他进程打开FIFO文件来写入才正常返回。同样地，打开FIFO文件来写入的操作会等到其他进程打开FIFO 文件来读取后才正常返回。
----返回值: 若成功则返回0，否则返回-1，错误原因存于errno中（注mkfifo不会将errno设置为EINTR）
----错误代码: 
	EACCESS 参数pathname所指定的目录路径无可执行的权限
	EEXIST 参数pathname所指定的文件已存在。
	ENAMETOOLONG 参数pathname的路径名称太长。
	ENOENT 参数pathname包含的目录不存在
	ENOSPC 文件系统的剩余空间不足
	ENOTDIR 参数pathname路径中的目录存在但却非真正的目录。
	EROFS 参数pathname指定的文件存在于只读文件系统内。

#include<sys/stat.h>
#include<fcntl.h>
int main(){
	char buffer[80];
	int fd;
	unlink(FIFO);
	mkfifo(FIFO,0666);
	if(fork()>0){
		char s[] = “hello!\n”;
		fd = open(FIFO,O_WRONLY);
		write(fd,s,sizeof(s));
		close(fd);
	}else{
		fd= open(FIFO,O_RDONLY);
		read(fd,buffer,80);
		printf(“%s”,buffer);
		close(fd);
	}
}
*/
//执行  hello!
#include<sys/stat.h>
#include<stdio.h>
int main(int argc,char *argv[]){
	mode_t mode=0666;
	if(argc!=2){
		perror("Usage...");
		return 1;
	}
	if(mkfifo(argv[1],mode)<0){
		perror("fail to mkfifo");
		return 1;
	}else printf("mkfifo success");
	return 0;
}







