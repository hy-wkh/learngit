/*#include<pthread.h>
#include<time.h>
int pthread_mutex_timedlock(pthread_mutex_t *restrict mutex,
							const struct timespec *restrict time_out);
----该互斥原语允许绑定线程阻塞时间，在到达超时时间时，该函数不会再对互斥量加锁，而是返回错误码ETIMEDOUT
*/
#include<pthread.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
int main(){
	int err;
	struct timespec tout;
	struct tm *tmp;
	char buf[64];
	pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&lock);
	clock_gettime(CLOCK_REALTIME,&tout);
	tmp=localtime(&tout.tv_sec);
	strftime(buf,sizeof(buf),"%r",tmp);
	printf("******current time is %s*******\n",buf);
	tout.tv_sec+=10;
	err=pthread_mutex_timedlock(&lock,&tout);
	clock_gettime(CLOCK_REALTIME,&tout);
	tmp=localtime(&tout.tv_sec);
	strftime(buf,sizeof(buf),"%r",tmp);
	printf("******the end time is %s*******\n",buf);
	if(err==0)
		printf("mutex locked again\n");
	else 
		printf("cant't lock mvtex again:%s\n",strerror(err));
	return 0;
}



