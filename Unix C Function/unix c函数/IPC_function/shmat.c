#include<sys/shm.h>
void *shmat(int shmid,const void *shmaddr,int shmflg);
----该函数将shmid指定的共享内存段连接到调用进程的地址空间并为shmid增加shm_nattch的值。
----设置shmflg可以正确的对其内存段
----
The  attaching address is specified by shmaddr with one of the following criteria:
	   *  If shmaddr is NULL,  the  system  chooses  a
          suitable (unused) address at which to attach
          the segment.

       *  If shmaddr isn't NULL and SHM_RND is  speci‐
          fied  in  shmflg,  the  attach occurs at the
          address equal to shmaddr rounded down to the
          nearest multiple of SHMLBA.

       *  Otherwise,  shmaddr  must  be a page-aligned
          address at which the attach occurs.
----成功返回内存段的起始地址，否则返回-1
