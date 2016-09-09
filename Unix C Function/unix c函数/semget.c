----成功返回０，否则返回-1并设置errno

----该函数销毁了它的参数所引用的互斥量，mutex是一个指向要销毁互斥量的指针，可以用...init函数对...destroy销毁的变量mutex重新初始化
----返回：成功返回０，否则返回一个非０错误码

mutex是一个指向要初始化的互斥量的指针，向mutexattr传递NULL时，初始化一个带有默认变量的互斥量，否则就要用类似于线程属性对象所用的方式，先创建，然后再初始化互斥属性对象


#include<sys/sem.h>
int semget(key_t key,int nsems,int semflag);
----该函数返回与参数key相关的信号量集标识符。如果键值为IPC_ORIVATE或者semflg&IPC_CTEAT非０而且没有信号量集或标识符关联key,那么semget函数就创建标识符及与之相关的信号量集
----nsems指定了集合中元素的个数，semflg指定了信号量集的优先级
----成功：返回一个对应于信号量集标识符的非负整数，否则返回-1并设置errno

#include<setjmp.h>
#include<stdio.h>
#include<signal.h>
#include<unistd.h>
sigset_t mask;
static void handler(int signo){
	printf("&&&&&&&\n");
//	if(sigismember(&mask,SIGALRM))
		printf("Yes\n");
	printf("times\n");
}

int main(){
//	sigemptyset(&mask);
//	sigaddset(&mask,SIGALRM);
	if(signal(SIGALRM,handler)==SIG_ERR)
		perror("fail to signal");
	printf("******\n");
	alarm(3);
	printf("######\n");
//	signal(SIGALRM,handler);	
	return 0;
}


