NAME
       pthread_cond_init, pthread_cond_destroy, pthread_cond_signal,
       pthread_cond_broadcast, pthread_cond_wait,
       pthread_cond_timedwait - operations on conditions

SYNOPSIS
       #include <pthread.h>

       pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

       int   pthread_cond_init(pthread_cond_t   *cond,  pthread_con‐
       dattr_t *cond_attr);

       int pthread_cond_signal(pthread_cond_t *cond);

       int pthread_cond_broadcast(pthread_cond_t *cond);

       int pthread_cond_wait(pthread_cond_t  *cond,  pthread_mutex_t
       *mutex);

       int pthread_cond_timedwait(pthread_cond_t *cond,
       pthread_mutex_t *mutex, const struct timespec *abstime);

       int pthread_cond_destroy(pthread_cond_t *cond);

DESCRIPTION
       A condition (short for ``condition variable'') is a  synchro‐
       nization  device that allows threads to suspend execution and
       relinquish the processors until some predicate on shared data
       is  satisfied. The basic operations on conditions are: signal
       the condition (when the predicate becomes true), and wait for
       the  condition, suspending the thread execution until another
       thread signals the condition.

       A condition variable must always be associated with a  mutex,
       to  avoid  the race condition where a thread prepares to wait
       on a condition variable and another thread signals the condi‐
       tion just before the first thread actually waits on it.

       ----pthread_cond_init:
       initializes  the  condition variable cond,
       using the condition attributes  specified  in  cond_attr,  or
       default  attributes  if  cond_attr  is NULL. The LinuxThreads
       implementation supports no attributes for  conditions,  hence
       the cond_attr parameter is actually ignored.

       Variables  of  type  pthread_cond_t  can  also be initialized
       statically, using the constant PTHREAD_COND_INITIALIZER.

       ----pthread_cond_signal: int pthread_cond_signal(pthread_cond_t *cond);
       restarts one  of  the  threads  that  are
       waiting  on  the  condition  variable cond. If no threads are
       waiting on cond, nothing  happens.  If  several  threads  are
       waiting  on  cond,  exactly  one  is restarted, but it is not
       specified which.

	   ----pthread_cond_broadcast:
	   restarts  all  the  threads  that  are
       waiting on the condition variable cond. Nothing happens if no
       threads are waiting on cond.

       ----pthread_cond_wait:
       int pthread_cond_wait(pthread_cond_t  *cond,  pthread_mutex_t *mutex);
       ----自动解锁并等待条件变量be signaled.线程的执行将被暂停并且不消耗cpu时间，直到条件变量be signaled.
       ----在返回调用线程前，该函数会重新申请mutex
       	   atomically  unlocks  the  mutex  (as   per
       pthread_unlock_mutex)  and  waits  for the condition variable
       cond to be signaled. The thread execution  is  suspended  and
       does not consume any CPU time until the condition variable is
       signaled. The mutex must be locked by the calling  thread  on
       entrance  to pthread_cond_wait. Before returning to the call‐
       ing  thread,  pthread_cond_wait  re-acquires  mutex  (as  per
       pthread_lock_mutex).

       Unlocking  the mutex and suspending on the condition variable
       is done atomically. Thus, if all threads always  acquire  the
       mutex  before  signaling  the condition, this guarantees that
       the condition cannot be signaled (and thus  ignored)  between
       the  time  a  thread locks the mutex and the time it waits on
       the condition variable.

       pthread_cond_timedwait atomically unlocks mutex and waits  on
       cond, as pthread_cond_wait does, but it also bounds the dura‐
       tion of the wait. If cond has not been  signaled  within  the
       amount  of  time specified by abstime, the mutex mutex is re-
       acquired and pthread_cond_timedwait returns the error ETIMED‐
       OUT.   The abstime parameter specifies an absolute time, with
       the same origin as time(2) and gettimeofday(2): an abstime of
       0 corresponds to 00:00:00 GMT, January 1, 1970.

       pthread_cond_destroy  destroys  a condition variable, freeing
       the resources it might hold. No threads must  be  waiting  on
       the  condition  variable on entrance to pthread_cond_destroy.
       In the LinuxThreads implementation, no resources are  associ‐
       ated  with  condition  variables,  thus  pthread_cond_destroy
       actually does nothing except checking that the condition  has
       no waiting threads.

CANCELLATION
       pthread_cond_wait and pthread_cond_timedwait are cancellation
       points. If a thread is cancelled while suspended  in  one  of
       these  functions,  the  thread immediately resumes execution,
       then locks again the mutex argument to pthread_cond_wait  and
       pthread_cond_timedwait,  and  finally  executes the cancella‐
       tion.  Consequently, cleanup handlers are assured that  mutex
       is locked when they are called.











