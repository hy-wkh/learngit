/*alarm（设置信号传送闹钟）  
#include<unistd.h>
unsigned int alarm(unsigned int seconds);
----seconds表示定时器设置的秒数
----函数用来设置一个定时器，从设置定时器开始，如果系统时间超过该时间后，就会向调用alarm函数的进程发送一个SIGALARM的信号，这个信号的默认动作是终止调用alarm函数的进程。（系统在经过参数seconds指定的秒数后传送给目前的进程）
----返回值 :返回之前闹钟的剩余秒数，如果之前未设闹钟或设置过定时器但该定时器已经超时，则返回0，如果之前设置过定时器且该定时器未超时，则返回剩余的秒数;如果参数seconds 为0，则之前设置的闹钟会被取消，并将剩下的时间返回。

*/
#include<stdio.h>
#include<unistd.h>
#include<signal.h>
void handler(int signo){
	printf("got the message!\n");
}

int main(){
	if(signal(SIGALRM,handler)==SIG_ERR){
		perror("fail to set handler...");
		return 1;
	}
	alarm(5);
	int i;
	for(i=1;i<=10;++i){
		printf("%d\n",i);
		sleep(1);
	}
	return 1;
}



