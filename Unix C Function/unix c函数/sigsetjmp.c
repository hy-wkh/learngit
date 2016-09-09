/*（存储当前堆栈环境和屏蔽信号集）p213
#include<setjmp.h>
int sigsetjmp(jmp_buf env,sigset_t sigmask);
----参数env保存当前栈帧的jmp_buf结构
	sigmask表示需要保存的信号屏蔽集
----返回：有两种可能（在设置跳转点的时候返回和跳转之后返回）
	第一种情况下，setjmp函数返回０；第二种情况下，函数返回非０值
	(若直接调用，则返回０，若从siglongjmp调用返回，则返回非０)
----该函数用于设置一个全局跳转点，并且保存信号集----该函数用于设置一个全局调转点，并保存信号屏蔽集。如果sigmask非０，则sigsetjmp在env中保存进程的当前信号屏蔽字

----在sigsetjmp函数执行时，保存当前的函数栈帧。在执行siglongjmp后，函数栈帧被恢复，因此恢复后的程序执行流程仍然停留在sigsetjmp函数内部　
----在信号处理程序中进行非局部转移时应当用这两个函数
 */
#include<setjmp.h>
#include<signal.h>
#include<stdio.h>
jmp_buf env;
void handler(int signo){
	printf("catch SIGUSR1\n");
}
void f(){
	siglongjmp(env,10);
}

int main(){
	int val;
	//sigset_t set;
	int set;
	printf("set handler\n");signal(SIGUSR1,handler);
	printf("add blocking signal\n");sigemptyset(&set);
	sigaddset(&set,SIGUSR1-1);
	val=sigsetjmp(env,set);
	if(val!=0)printf("after longjmp,value is %d\n",val);
	else printf("ready to jmp\n");
	f();
	sleep(5);//等待信号
	printf("done\n");
	return 0;
}











