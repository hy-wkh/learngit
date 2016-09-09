#include<unistd.h>
long sysconf(int name);
long pathconf(const char *pathname,int name);
long fpathconf(int fd,int name);
----pathname用于标识文件路径，fd为文件描述符
----name用于标识系统限制
----三个函数返回值：成功则返回相应值，若出错则返回-1并将errno置为EINVAL;

----注：与文件或目录无关的运行时选项用sysconf函数来判断
		与文件或目录有关的运行时选项用pathconf或fpathconf函数来判断

#include<unistd.h>
#include<stdio.h>
int main(){
	int name;
	long len=sysconf(_SC_CLK_TCK);
	long len1=pathconf("/sys",_PC_NAME_MAX);
	printf("%ld",len1);
	return 0;
}
