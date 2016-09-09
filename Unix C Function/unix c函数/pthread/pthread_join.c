/*

#include <pthread.h>
int pthread_join(pthread_t thread, void **value_ptr);
----参数value_ptr为指向返回值的指针提供了一个位置，这个返回值是由目标线程传递给pthread_exit或return的。如果value_ptr为NULL,调用程序就不会对目标线程的返回状态进行检索了(该无类型指针参数可以传递的值不止一个，这个指针可以传递包函复杂信息的结构的地址，注：该结构所使用的内存在调用者完成调用以后仍然是有效的)
----返回：成功返回０，失败返回一个非０的错误码
----在另一个线程用终止线程的ID作为第一个参数调用pthread_join之前，未分离线程的资源是不会被释放的。该函数将调用线程挂起，直到第一个参数指定的目标线程终止为止
----功能：
	1.调用线程将一直阻塞，直到指定的线程调用pthread_exit,从启动例程中返回或者被取消。可以调用该函数自动把线程置于分离状态，这样资源就可以恢复，如果线程已经处于分离状态，该函数调用就会失败。	
	2.该函数可以获取线程的退出状态
*/

//展示如何获取已终止的线程的退出码

#include<pthread.h>
#include<stdio.h>

void thr_fn1(void *arg){
	printf("thread 1 returning\n");
	return ((void *)1);
}
void thr_fn2(void *arg){
	printf("thread 2 returnint \n");
	return ((void *)1);
}

int main(){
	int err;
	pthread_t tid1,tid2;
	void *tret;
	err=pthread_create(&tid1,NULL,thr_fn1,NULL);
	if(err!=0)
		perror("Can't create pthread 1");
	err=pthread_create(&tid2,NULL,thr_fn2,NULL);
	if(err!=0)
		perror("Can't create pthread 2");
	err=pthread_join(tid1,&tret);
	if(err!=0)
		perror("fail to pthread_join 1");
	printf("pthread 1 exit code %ld \n",(long)tret);
	err=pthread_join(tid2,&tret);
	if(err!=0)
		perror("fail to pthread_join 2");
	printf("pthread 2 exit code %ld \n",(long)tret);
return 0;
}







