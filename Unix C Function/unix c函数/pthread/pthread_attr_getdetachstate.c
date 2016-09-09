/*#include <pthread.h>
int pthread_attr_getdetachstate(const pthread_attr_t *attr, 
								int *detachstate);
----该函数用来查看一个属性对象的detachstate线程属性
----attr是一个指向属性对象的指针
----detachstate是该函数检索所得到的值的指针
----成功返回０，否则返回一个非０的错误码


int pthread_attr_setdetachstate(pthread_attr_t *attr, int *detachstate);
----该函数用来设置一个属性对象的状态
----attr是一个指向属性对象的指针
----detachstate是要为该函数设置的值,该参数可以设置成PTHREAD_CREATE_DETACHED 或 PTHREAD_CREATE_JOINABLE
----成功返回０，否则返回一个非０的错误码
*/
#include<pthread.h>
int makepthread(void *(*fn)(void *),void *arg){
	int err;
	pthread_t tid;
	pthread_attr_t attr;
	err=pthread_attr_init(&attr);
	if(err!=0)return(err);
	err=pthread_attr_setdetachstate(&attr,&PTHREAD_CREATE_DETACHED);
	if(err==0)pthread_create(&tid,&attr,fn,arg);
	pthread_destroy(&attr);
	return (err);
}










