/*
#include<unistd.h>
uid_t geteuid(); //返回当前进程的有效用户标识符，这个标识符确定了调用程序的权限（这个函数可以更改调用程序的权限，linux/unix下一个文件的属性中有setID位，当一个可执行文件被设置了setID后，则调用该程序的euid会等于该文件的uid）
uid_t getuid(); //返回当前进程的用户标识符，如出错返回-1
*/

/*
#include<unistd.h>
gid_t getgid(); //获取当前进程的组标识符(一个进程只能由一个用户创建，该用户可能同时存在多个分组中，该函数只返回用户的一个组识别符)
gid_t getegid(); //获取当前进程的有效组标识符
*/

#include<unistd.h>
#include<stdio.h>

int main(){
	uid_t u1,u2;
	u1=geteuid();
	u2=getuid();
	printf("%u %u\n",u1,u2);
	return 0;
}











