#include<stdio.h>
void flockfile(FILE *filehandle);//加
int ftrylockfile(FILE *filehandle);//加
----这两个函数获取FILE对象关联的锁，这个锁是递归的

void funlockfile(FILE *filehandle);//减
----该函数将lock count减少


The  flockfile() function waits for *filehandle to be no longer locked by a different thread,then makes the current thread owner of *filehandle, and increments the lockcount.

The funlockfile() function decrements the lock count.

The ftrylockfile() function is a nonblocking version of flockfile().  It does nothing in case some  other  thread  owns  *filehandle, and it obtains ownership and increments the lockcount otherwise.

****************************************************************

The  stdio  functions  are  thread-safe.  This is achieved by assigning to each FILE object a lockcount and (if the lockcount is nonzero) an owning thread.  For each library  call,  these functions wait until the FILE object is no longer locked by a different thread, then lock it,do the requested I/O, and unlock the object again.

(Note: this locking has nothing to do with the file locking done by functions  like  flock(2) and lockf(3).)


----返回：成功返回０，若不能获取锁，返回非０值









