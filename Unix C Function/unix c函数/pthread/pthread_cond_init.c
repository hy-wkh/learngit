#include <pthread.h>
int pthread_cond_init(pthread_cond_t *cond,
					  pthread_condattr_t *cond_attr);
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
----pthread_cond_t类型表示条件变量类型(等待某一条件为真的线程队列相关的数据类型)，程序必须在使用pthread_cond_t变量之前对其进行初始化。（静态方式和init方式）
----cond_attr是一个指向要初始化的条件变量的指针，向cond_attr传递NULL时，用默认属性来初始化一个条件变量。否则就要用类似于线程属性对象所用的方式，先创建，然后再初始化条件变量属性对象
----返回：成功返回０，否则返回一个非０错误码


********************************************************************


int pthread_cond_wait(pthread_cond_t *cond,pthread_mutex_t *mutex);
----该函数会将mutex解锁并等待条件变量cond收到信号，线程会暂停（也就是使线程等待，但不是忙等）并且不会消耗cpu，直到条件变量收到信号。在调用该函数前，互斥量一定要被锁上，在返回调用线程前，该函数又会获得互斥量（该函数原子地挂起调用线程并解除对互斥量的锁定，可以认为它将线程放入一个队列，队列中的线程都在等待条件发生变化的通知。线程收到通知时，函数会带着重新获得的互斥量返回到线程，在继续执行前，线程必须再次对条件进行测试）
----线程会对一个断言进行测试，如果测试失败，就调用该函数（也就是使线程等待）
----返回：成功返回０，否则返回一个非０错误码
pthread_cond_wait    atomically    unlocks    the    mutex    (as   per
       pthread_unlock_mutex) and waits for the condition variable cond  to  be
       signaled.  The  thread  execution is suspended and does not consume any
       CPU time until the condition variable is signaled. The  mutex  must  be
       locked  by  the calling thread on entrance to pthread_cond_wait. Before
       returning to the calling thread,  pthread_cond_wait  re-acquires  mutex
       (as per pthread_lock_mutex).


*******************************************************************


int pthread_cond_timedwait(pthread_cond_t *cond,
						   pthread_mutex_t *mutex, 
						   const struct timespec *abstime);
----该函数可以用来等待一段有限的时间（该函数对cond解锁并在cond上等待）
----cond是一个指向条件变量的指针，第二个参数是一个指向互斥量的指针，线程在调用之前应该拥有这个互斥量。当线程被放置在条件变量等待队列中时，等待操作（...wait）会使线程释放这个互斥量，第三个参数是一个指向返回时间的指针，如果条件变量信号没有在此之前出现的话，线程就在这个时间返回
----返回：成功返回０，否则返回一个非０错误码


*******************************************************************


int pthread_cond_destroy(pthread_cond_t *cond);
----该函数销毁参数cond引用的条件变量，已经被销毁的pthread_cond_t可以用...init进行重新初始化(在释放变量底层的内存空间以前，)
----返回：成功返回０，否则返回一个非０错误码
-----  pthread_cond_destroy destroys a condition variable, free‐
       ing the resources it might hold. No threads must be wait‐
       ing  on   the   condition   variable   on   entrance   to
       pthread_cond_destroy. In the LinuxThreads implementation,

       no resources are  associated  with  condition  variables,
       thus  pthread_cond_destroy  actually  does nothing except

       checking that the condition has no waiting threads.


*******************************************************************


int pthread_cond_signal(pthread_cond_t *cond);
----该函数至少解除了一个阻塞在cond指向的条件变量上的线程的阻塞(重新启动一个在cond上的线程)
----该函数可以将条件变量x所做的修改通知等待线程。在不拥有互斥量的情况下，被阻塞的线程是不能从pthread_cond_wait中返回的，所以pthread_cond_signal可以将线程从条件变量队列转移到互斥变量队列中去
----返回：成功返回０，否则返回一个非０错误码
       pthread_cond_signal restarts one of the threads that are waiting on the
       condition  variable  cond.  If  no threads are waiting on cond, nothing
       happens. If several  threads  are  waiting  on  cond,  exactly  one  is
       restarted, ----but it is not specified(规定的) which.----


*******************************************************************


int pthread_cond_broadcast(pthread_cond_t *cond);
----该函数解除了所有阻塞在cond指向的条件变量上的线程的阻塞
----返回：成功返回０，否则返回一个非０错误码




