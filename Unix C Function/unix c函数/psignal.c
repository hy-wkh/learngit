p304
#include<signal.h>
void psignal(int signo,const char *msg);
----该函数可移植地打印与信号编号对应的字符串
----msg输出到标准输出文件，后面跟一个冒号和一个空格，再后面对该信号的说明，最后是一个换行符。如果msg为NULL，说明部分输出到标准错误文件，该函数类似于perror

#include<signal.h>
void psiginfo(const siginfo_t *info,const char *msg);
----如果sigaction信号处理程序中有siginfo结构，则可以使用该函数打印信息
----

#include<signal.h>
char *strsignal(int signo);
----如果只需要信号的字符描述部分，也不需要把它写到标准错误文件中（如：可以写到日志文件中），可以使用strsignal函数，它类似于strerror
----返回：指向描述该信号的字符串的指针

#include<signal.h>
#include<stdio.h>
#include<string.h>
int main(){
	int i;
	for(i=0;i<15;++i){
		printf("%d",i);//这个会缓冲
		psignal(i,"error number is ");//这个不会缓冲
	}
	printf("************\n");
	for(i=0;i<15;++i){
		printf("%s\n",strerror(i));
	}
}
/*
error number is : Unknown signal 0
error number is : Hangup
error number is : Interrupt
error number is : Quit
error number is : Illegal instruction
error number is : Trace/breakpoint trap
error number is : Aborted
error number is : Bus error
error number is : Floating point exception
error number is : Killed
error number is : User defined signal 1
error number is : Segmentation fault
error number is : User defined signal 2
error number is : Broken pipe
error number is : Alarm clock
01234567891011121314************
Success
Operation not permitted
No such file or directory
No such process
Interrupted system call
Input/output error
No such device or address
Argument list too long
Exec format error
Bad file descriptor
No child processes
Resource temporarily unavailable
Cannot allocate memory
Permission denied
Bad address


*/
