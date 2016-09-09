#include <pthread.h>
int pthread_rwlock_destroy(pthread_rwlock_t *rwlock);.
----该函数销毁了它的参数所引用的读写锁，rwlock是一个指向要销毁读写锁的指针，可以用...init函数对...destroy销毁的变量mutex重新初始化
----返回：成功返回０，否则返回一个非０错误码


int pthread_rwlock_init(pthread_rwlock_t *restrict rwlock,
        　　　　　　　  const pthread_rwlockattr_t *restrict attr);
----rwlock是一个指向要初始化的读写锁的指针，向rwlock传递NULL时，初始化一个带有默认变量的互斥量，否则就要用类似于线程属性对象所用的方式，先创建，然后再初始化互斥属性对象

