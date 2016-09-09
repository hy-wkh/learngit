/*
#include<sys/select.h>
int pselect(int n,
			fd_set *restric readfds,
			fd_set *restrict writefds,
			fd_set *restrict exceptfds,
			const struct timespec *restrict tsptr,
			const sigset_t *restrict sigmask);
----参数n为所要监控文件描述符集的最大长度加1
----参数readfds为指定的读操作监控集
----writefds为指定的写操作监控集
----exceptfds为忽略监控的文件描述符集
----参数tsptr表示等待时间，timespec结构所能表示的最小精度是ns。
----参数sigmask可以用来屏蔽信号。
----返回：执行成功返回监控集中有操作请求的文件描述符的个数，失败返回-1，并设置全局错误变量errno.
----功能：函数用于等待参数readfds,writefds集中的文件描述符的状态改变，并记录状态改变的个数。

----函数中使用的fd_set为一个位图类型的数据集，该集合中每一个元素为一个bit位，该bit位只有两种取值１或０，系统中为该数据类型提供了４个宏（FD_CLR,FD_ISSET,FD_SET,FD_ZERO）做相应的操作。

----pselect函数返回后，将屏蔽的信号恢复，并且所有的操作都是原子的。使用pselect函数将不必再担心会被信号中断，sigmask提供一个信号的位向量，上面所设置的信号都将在等待时被屏蔽。如果愿意，可以屏蔽除了SIGKILL和SIGSTOP之外所有的信号，真正地做到死等一个设备。

----名称：多路转接I/O
*/

#include<stdio.h>
#include<sys/select.h>
void sigusr1_handler(int signo){
	printf("Catch SIGUSR1\n");//接收SIGUSR1信号，打印接收信息
}

int main(){
	int rdy;//准备好的设备数
	sigset_t set;//信号集
	
	/*注册信号处理函数，如果捕捉到信号则输出提示信息*/
	if(signal(SIGUSR1,sigusr1_handler)==SIG_ERR){
		perror("can't set handler for SIGUSR1");
		exit(1);
	}
	setfillset(&set);//设置信号集，屏蔽所有的信号，包括SIGKILL和SIGSTOP

	rdy=pselect(1,NULL,NULL,NULL,NULL,&set);//不关心所有的设备准备状态，所以检查设备的最大文件描述符值也不再有意义。等待时间结构为NULL,表示将等待时间设置为无限等待。

	printf("should never be here\n");//因为是无限等待，所以绝对不会执行到这里，输出提示信息。
return 0;
}






