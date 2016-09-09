#include <pthread.h>
pthread_mutex_t fastmutex=PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t recmutex=PTHREAD_RECURSIVE_MUTEX_INI‐TIALIZER_NP;
pthread_mutex_t errchkmutex=PTHREAD_ERRORCHECK_MUTEX_INITIALIZER_NP;

int pthread_mutex_init(pthread_mutex_t *mutex, 
					   const pthread_mutexattr_t *mutexattr);
----mutex是一个指向要初始化的互斥量的指针，向mutexattr传递NULL时，初始化一个带有默认变量的互斥量，否则就要用类似于线程属性对象所用的方式，先创建，然后再初始化互斥属性对象
----返回：成功返回０，否则返回一个非０错误码
	o pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;(该变量以静态方式分配)

int pthread_mutex_destroy(pthread_mutex_t *mutex);
----该函数销毁了它的参数所引用的互斥量，mutex是一个指向要销毁互斥量的指针，可以用...init函数对...destroy销毁的变量mutex重新初始化

int pthread_mutex_lock(pthread_mutex_t *mutex);
----该函数可以用来获取互斥量，该函数会一直阻塞到互斥量可用为止

int pthread_mutex_trylock(pthread_mutex_t *mutex);
----该函数可以用来获取互斥量(该函数不会使线程被阻塞)，该函数通常会立即返回

int pthread_mutex_unlock(pthread_mutex_t *mutex);
----该函数用来释放指定的互斥量
　　o 这三个函数的mutex是一个指向互斥量的指针

----返回：对以上所有函数，成功返回０，否则返回一个非０错误码


