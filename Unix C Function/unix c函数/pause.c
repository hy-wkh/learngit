/*pause（让进程暂停直到信号出现）  
#include<unistd.h>
int pause(void);
----pause()会令目前的进程挂起()状态，直到接收到某些特殊信号，并且执行了信号处理程序并从其返回后，pause函数才返回，返回值
是-1（唯一能够保证杀死进程的方法是使用kill命令向该进程发送SIGKILL信号）
----返回值 :只返回-1。
----错误代码:EINTR 有信号到达中断了此函数。
*/
#include<stdio.h>
#include<unistd.h>
int main(){
	int i;
	for(i=1;i<=100;++i){
		printf("%d\n",i);
		if(i==50||i==70)pause();
	}
	return 0;
}





