NAME
       pthread_setconcurrency,  pthread_getconcurrency - set/get the
       concurrency(n.并发性，同时发生) level

SYNOPSIS
       #include <pthread.h>

       int pthread_setconcurrency(int new_level);
       int pthread_getconcurrency(void);

       Compile and link with -pthread.

DESCRIPTION
       The pthread_setconcurrency() function informs the implementa‐
       tion  of  the application's desired concurrency level, speci‐
       fied in new_level.  The implementation takes this only  as  a
       hint:  POSIX.1 does not specify the level of concurrency that
       should be provided as a result of calling  pthread_setconcur‐
       rency().

       Specifying  new_level  as  0  instructs(vt.命令，指示) the implementation to
       manage the concurrency level as it deems(认为) appropriate.

       pthread_getconcurrency() returns the  current  value  of  the
       concurrency level for this process.
       
RETURN VALUE
       On  success, pthread_setconcurrency() returns 0; on error, it
       returns a nonzero error number.

       pthread_getconcurrency() always succeeds, returning the  con‐
       currency  level  set by a previous call to pthread_setconcur‐
       rency(), or 0, if pthread_setconcurrency() has not previously
       been called.












