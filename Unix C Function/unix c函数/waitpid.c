
#include<sys/wait.h>
pid_t waitpid(pid_t pid,int *statloc,int options);
----pid:要等待的子进程的pid,statloc表示存储子进程结束信息的存储空间
----功能：非阻塞等待指定的子进程中断或结束
----pid指定要等待的子进程的PID，ｐｉｄ＝＝－１，等待任意子进程
	ｐｉｄ>0 :等待进程ＩＤ为ｐｉｄ的子进程  
	ｐｉｄ＝＝０ :等待与调用者在同一个进程组中的任意子进程
	ｐｉｄ<-1 :等待由pid绝对值指定的进程组中任意子进程
----statloc :表示存储子进程结束信息的存储空间
----options :控制选项：
	WCONTINUED :当子进程在暂停后继续执行，且其状态尚未报告，则返回其状态
	WNOHANG :当所等待进程尚未结束运行时不阻塞，waitpid函数直接返回
    WUNTRACED :当子进程暂停时，并且其状态自暂停以来还未报告过，则返回其状态
----返回值 :
	* waitpid函数等待指定的子进程，如该子进程已经结束运行，返回值是子进程的
	PID
	* 若参数ｐｉｄ>0,函数返回值等于参数ｐｉｄ的值
	* 若该进程尚未结束且waitpid函数设置了WNOHANG选项，则返回-1;
	* 如果指定进程或者进程组不存在或参数ｐｉｄ所指定的进程不是调用waitpid函数的进程的子进程，则立即出错返回－1
	
	while((pid=waitpid(-1,&status,WNOHANG))>0)
	The value of pid can be:

       < -1   meaning wait for any child process  whose  process
              group ID is equal to the absolute value of pid.

       -1     meaning wait for any child process.

       0      meaning  wait  for any child process whose process
              group ID is equal to that of the calling process.

       > 0    meaning wait for the child  whose  process  ID  is
              equal to the value of pid.
	RETURN:on  success,  returns  the  process ID(也就是>0) of the child whose state has changed;


#include<stdio.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
	pid_t pid;
	pid=fork();
	if(pid<0){
		perror("fail to fork");
		exit(1);
	}else if(pid==0){
		//sleep(5); //1
		printf("Child\n");//子进程休眠
		sleep(5);//2 休眠，让父进程先运行????printf不是先运行吗？为什么不会输出？？？
		exit(0);
	}else {
		printf("Father\n");
		if(waitpid(pid,NULL,WNOHANG)==-1)
			printf("The child is not available!\n");
	}
	printf("no waitting,parent down\n");
	return 0;
}
/*
第一个sleep:
hy@hy-K53BE:~/桌面$ cc -o ff waitpid.c
hy@hy-K53BE:~/桌面$ ./ff　
Father
no waitting,parent down
hy@hy-K53BE:~/桌面$ Child
----之所以child是运行玩后才输出的是因为：程序是运行完时（本来函数是要等到该进程结束后才返回的，但是由于1／0,所以产生一个信号，提前结束了），子进程并没有死亡，只是sleep了，当sleep结束后，这个进程有复活了，所以又输出了
*/

/*
第二个sleep:
hy@hy-K53BE:~/桌面$ cc -o ff waitpid.c
hy@hy-K53BE:~/桌面$ ./ff
Father
no waitting,parent down
Child ---这个child后输出是进程优先级导致的，不是sleep的原因；　这个是先输出再休眠
hy@hy-K53BE:~/桌面$
*/







