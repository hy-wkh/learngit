unp p545
1. 每个系统支持有限数量的线程特定数据，系统为每个进程维护一个我们称之为key结构的结构数组，每个结构数组由标志和析构函数指针组成。

2. key结构 中的标志指示这个元素是否正在使用。当一个线程调用pthread_key_create创建一个新的线程特定数据元素时，系统搜索其key结构数组找出第一个不在使用的元素。该元素的索引称为键，返回给调用线程的正是这个索引。

3. pthread结构 用于维护每个线程的多余信息，每个线程有一个pthread结构。

4. 当我们调用pthread_key_create创建一个键时，系统告诉我们这个键(索引)。每个线程可以随后为该键存储一个值(指针)，该指针通常又是每个线程通过调用malloc获取的。注意：该指针是键－值对中的值，但是真正的线程特定数据是该指针指向的任何内容。

5. 程序：

#include<pthread.h>
#include<stdio.h>

void readline_destructor(void *ptr){
	free(ptr);
}

void read_line(){
	pthread_key_create(&r1_key,readline_destructor);
}

ssize_t readline(...){
	pthread_key_t r1_key;
	pthread_once_t r1_once=PTHREAD_ONCE_INIT;

	pthread_once(&r1_once,readline_once);
	if((ptr=pthread_getspecific(r1_key)==NULL){
		ptr=malloc(...);
		pthread_setspecfic(r1_key,ptr);
	}
}

