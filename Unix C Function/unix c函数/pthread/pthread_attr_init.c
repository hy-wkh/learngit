#include <pthread.h>
int pthread_attr_init(pthread_attr_t *attr);
----该函数用默认值对一个线程属性对象进行初始化
----attr为一个指向pthread_attr_t属性对象的指针
----返回：成功返回０，否则返回一个非０的错误码

int pthread_attr_destroy(pthread_attr_t *attr);
----该函数释放该线程属性的内存空间，除此以外，该函数还会用无效的值初始化该内存空间
----attr为一个指向pthread_attr_t属性对象的指针
----返回：成功返回０，否则返回一个非０的错误码









