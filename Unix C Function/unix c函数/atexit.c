atexit（设置程序正常结束前调用的函数）  
相关函数  _exit,exit,on_exit
#include<stdlib.h>
int atexit (void (*function)(void));
----参数是一个函数指针
----atexit()用来设置一个程序正常结束前调用的函数。当程序通过调用exit()或从main中返回时，参数function所指定的函数会先被调用，然后才真正由exit()结束程序。
 
----返回值: 如果执行成功则返回0，否则返回非０值，失败原因存于errno中。

----说明：一个进程可以用atexit登记最多32个函数，这些函数由exit自动调用，我们称这些函数为终止处理程序
 
范例:
#include<stdlib.h>
void my_exit(void){
	printf(“before exit () !\n”);
}
main(){
	atexit (my_exit);
	exit(0);
}
 
执行: before exit()!
 
　 
