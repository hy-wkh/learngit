/*
#include<signal.h>
int raise(int signo);
----signo表示要发送的信号编码
----返回：成功返回０，失败返回-1
----raise函数向进程本身发送信号的函数
*/
#include<stdio.h>
#include<signal.h>

void handler(int signo){
	printf("got the message!\n");
}

int main(){
	int signo;
	if(signal(SIGUSR1,handler)==SIG_ERR){
		perror("fail to set handler...");
		return 1;
	}
	if(raise(SIGUSR1)==-1){
		perror("fail to raise...");
		return 1;
	}
	return 0;
}









