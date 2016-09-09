
#include<fcntl.h>
int open(const char *pathname,int oflag,....);
----pathname :表示要打开的文件的路径名或文件名
----oflag :表示指定打开文件的选项，其值是一个“位向量”。通常使用下列一个或多个常量进行“或”操作构成oflag参数，这些常量由宏表示，其定义在fcntl.h 头文件中。
----第三个参数只要在打开的文件并不存在，而且需要系统创建的时候才用(所以也可以用来创建一个文件)。该参数代表创建新文件的权限。
----返回值：如果成功打开一个文件，则返回文件的描述符，否则返回－1.
----open函数可以创建一个新文件，该文件的访问权限受到文件权限屏蔽掩码"unmask"的影响。

----注意：pathname可以是路径。但是，如果文件放在放在家目录下，例如：~/Pipe.cpp，应该写成/home/hy/Pipe.cpp,否则，open打不开那个文件
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
这些标志都定义在fcntl.h中：
1.可以通过对访问模式标识符和附加标志符这对期望组合进行按位或运算来构建oflag参数。
2.访问模式标志符的POSIX值为 :Ｏ_RDWR,O_RDONLY,O_WRONLY;
3.附加标志符包括 :
----O_APPEND:在写操作之前使文件偏移转移到文件的末端，这样就可以向一个已经存在的文件添加内容了
----O_TRUNC :将为写操作打开的正常文件的长度删减为0.
----O_CREAT :如果文件不存在，该标志符就创建文件（这时必须传递第三个参数来指定权限。如果想避免重写一个已经存在的文件，可以使用O_CREAT | O_EXCL的组合,如果文件已经存在，这个组合就返回一个错误）
----O_NOCTTY :防止一个已经打开的设备变成一个控制终端
----O_NONBLOCK :负责控制open是立即返回还是一直阻塞到设备准备好为止。

**************************************************

int openat(int dirfd, const char *pathname, int flags);
int openat(int dirfd, const char *pathname, int flags, mode_t mode);


#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>

int main(){
	int fd;
	fd=open("test.c",O_RDWR|O_CREAT,0700);
	if(fd==-1){
		perror("fail to open");
		exit -1;
	}
	else printf("open ok\n");
	close(fd);
	return 0;
}







