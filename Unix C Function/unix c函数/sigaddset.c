/*
sigaddset（添加一个信号至信号集）  
相关函数  sigemptyset，sigfillset，sigdelset，sigismember 
#include<signal.h>
int sigaddset(sigset_t *set,int signum);
----set是一个信号集数据，signum指定信号编号
----sigset_t是一个位向量，sigaddset函数将signum指定的信号所对应的位设置为1
----返回：执行成功则返回0，如果有错误则返回-1。
----sigaddset函数的参数是一个信号集类型变量的指针，由于信号集的修改在内核内部发生，因此需要传入指针变量
----错误代码：
	EFAULT 参数set指针地址无法存取
	EINVAL 参数signum非合法的信号编号
*/
#include<stdio.h>
#include<signal.h>
int main(){
	sigset_t set;//信号集数据结构
	int mask;
	if(sigemptyset(&set)==-1){
		perror("fail to sigempty");
		return 1;
	}
	mask=1<<SIGUSR1-1;//得到掩码
	printf("before add\n");
	if(set & mask)//判断信号集是否被设置
		printf("has been set\n");
	else 
		printf("not set\n");

	printf("after set\n");
	if(sigaddset(&set,SIGUSR1-1)==-1){//添加信号到信号集
		perror("fail to sigadd");
		return 1;
	}
	if(set & mask)
		printf("has been set\n");
	else 
		printf("not set\n");
	return 0;
}


