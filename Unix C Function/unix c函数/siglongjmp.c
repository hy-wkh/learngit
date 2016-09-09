/*(siglongjmp:跳到原先sigsetjmp存储的堆栈环境)
#include<setjmp.h>
void siglongjmp(jum_buf env,int val);
----env表示需要恢复的函数栈帧，该帧保存在一个jmp_buf结构中，根据栈帧的不同，可选择不同的跳转点
----val表示跳转之后setjmp函数的返回值。为了区别设置全局变量跳转点时的setjmp返回值，这个值应当被设置为非０值
----siglongjmp函数执行全局跳转，跳转到第一个参数所表示的全局跳转点上，并且恢复之前保存的信号屏蔽集
----siglongjmp函数的第一个参数决定了全局跳转的位置，因此当有多个全局跳转点时，应该使用不同的栈帧存储结构
----信号集的恢复由系统自动完成，不需要程序员的干预
*/
#include<setjmp.h>
#include<stdio.h>

jmp_buf env;
int val;

void f(){
	printf("function f()\n");
	siglongjmp(env,100);
}
int main(){
	val=setjmp(env);
	if(val!=0)printf("after long jmp,the value is %d\n",val);
	else printf("ready to jmp\n");
	getchar();
	f();
	printf("function main\n");//永远执行不到这条命令
	return 0;
}











