#include<pthread.h>
int pthread_atfork(void (*prepare)(void),
				   void (*parent)(void),
				   void (*child)(void));

       pthread_atfork registers handler functions  to  be  called  just before and just after a new process is created with fork(2). 
	   The prepare handler will be called from  the  parent  process,  just before  the  new  process is created. (这个fork处理程序的任务是获取父进程定义的所有锁)
pthread_cond_wait    atomically    unlocks    the    mutex    (as   per
       pthread_unlock_mutex) and waits for the condition variable cond  to  be
       signaled.  The  thread  execution is suspended and does not consume any
       CPU time until the condition variable is signaled. The  mutex  must  be
       locked  by  the calling thread on entrance to pthread_cond_wait. Before
       returning to the calling thread,  pthread_cond_wait  re-acquires  mutex
       (as per pthread_lock_mutex).
	   The parent handler will be called from the parent process, just before fork(2) returns. (这个fork处理程序是对prepare处理程序获取的所有锁进行解锁)
	   The child handler will be called from the child process, just before fork(2) returns.（这个处理程序释放prepare处理程序获取的所有锁）

 　　　pthread_atfork returns 0 on success and a non-zero error code on error.



