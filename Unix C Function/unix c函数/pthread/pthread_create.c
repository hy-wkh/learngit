#include <pthread.h>
int pthread_create(pthread_t *thread,
				   const pthread_attr_t *attr,
                   void *(*start_routine) (void *),
				   void *arg);
----thread指向新创建的线程的ID
	attr表示一个封装了线程的各种属性的属性对象（如果为NULL,新线程就具有默认属性）
	start_routine是线程开始执行的时候调用的函数的名字（该函数返回一个指向void的指针，这个返回被pthread_join当作推出状态来处理）
	arg是函数start_routine的参数,如果需要向start_routine函数传递的参数有一个以上，那么需要把这些参数放到一个结构中，然后把这个结构的地址作为arg参数传入。
----返回：成功返回０，失败返回一个非０的错误码


#include<pthread.h>
#include<stdio.h>

pthread_t ntid;
void print(const char *s){
	pid_t pid;
	pthread_t tid;
	pid=getpid();
	tid=pthread_self();
	printf("%s pid %lu tid %lu (0x%lx)\n",s,(unsigned long)pid,(unsigned long)tid,(unsigned long)tid);
}

void thr_fn(void *arg){
	print("new thread:");
	return (void *)0;
}

int main(){
	int err;
	err=pthread_create(&ntid,NULL,thr_fn,NULL);
	if(err!=0)
		perror("can't create pthread");
	print("main thread:");
	sleep(1);
	return 0;
}





