/*
#include<unistd.h>
unsigned int sleep(unsigned int nsec);

----让进程休眠一段时间后回复执行。
----参数nsec的单位是秒
----返回值：1.挂起时间超过了指定的时间，sleep返回０。2.挂起期间被信号唤起，sleep返回从挂起以来程序运行的时间
*/

#include<unistd.h>
#include<stdio.h>

int main(){
	printf("1\n");
	sleep(5);
	printf("10\n");
	return 0;
}




