#include<pthread.h>
int pthread_key_create(pthread_key_t *key,void(*destr_fuc)(void *));
----功能：该函数创建与线程特定数据关联的键，该键将用于获取对线程特定数据的访问
----key：创建的键存储在key指向的内存单元中，这个键可以被进程中所有的线程使用
	第二个参数为该键关联的一个可选择的析构函数

int pthread_key_delete(pthread_key_t key);
----功能：该函数用来取消键与线程特定数据值之间的关联


int pthread_setspecific(pthread_key_t key,const void *pointer);
----功能：该函数把键和线程特定数据关联起来

void *pthread_getspecific(pthread_key_t key);
----功能：该函数获得线程特定数据的地址

----成功返回０，否则返回错误码
----   Each thread possesses a private memory block, the thread-specific data area,  or  TSD
       area  for  short. This area is indexed by TSD keys. The TSD area associates values of
       type void * to TSD keys. TSD keys are common(共同的，普通的，公有的) to all threads,
	   but the value associatedwith a given TSD key can be different in each thread.

       For  concreteness, the TSD areas can be viewed as arrays of void * pointers, TSD keys
       as integer indices into(整数索引) these arrays, and the value of a TSD key as the value
	   of  the corresponding array element in the calling thread.











