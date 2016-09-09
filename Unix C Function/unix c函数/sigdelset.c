/*
sigdelset（从信号集里删除一个信号）  
#include<signal.h>
int sigdelset(sigset_t * set,int signum);
----set是一个信号集数据，signum指定信号编号
----sigdelset()用来将参数signum代表的信号从参数set信号集里删除，（将signum指定的信号所对应的位设置为０，表示删除这个信号）
----返回值: 执行成功则返回0，如果有错误则返回-1。
----错误代码: 
	EFAULT 参数set指针地址无法存取
	EINVAL 参数signum非合法的信号编号
*/
#include<stdio.h>
#include<signal.h>
int main(){
	sigset_t set;//信号集数据结构
	int mask;
	if(sigfillset(&set)==-1){
		perror("fail to sigfillset");
		return 1;
	}
	mask=1<<SIGUSR1-1;//得到掩码
	printf("before delete\n");
	if(set & mask)//判断信号集是否被设置
		printf("has been set\n");
	else 
		printf("not set\n");

	printf("after delete\n");
	if(sigdelset(&set,SIGUSR1-1)==-1){//删除信号集中的信号
		perror("fail to sigdel....");
		return 1;
	}
	if(set & mask)
		printf("has been set\n");
	else 
		printf("not set\n");
	return 0;
}









