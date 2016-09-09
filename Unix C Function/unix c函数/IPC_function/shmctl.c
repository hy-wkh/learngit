#include<sys/shm.h>
int shmctl(int shmid,int cmd,struct shmid_ds *buf);
----该函数为共享内存段shmid提供了多种控制操作。
----shmid为共享内存段的标识符
----成功返回０，否则返回-1并设置errno
   struct shmid_ds {
               struct ipc_perm shm_perm;    /* Ownership and permissions */
               size_t          shm_segsz;   /* Size of segment (bytes) */
               time_t          shm_atime;   /* Last attach time */
               time_t          shm_dtime;   /* Last detach time */
               time_t          shm_ctime;   /* Last change time */
               pid_t           shm_cpid;    /* PID of creator */
               pid_t           shm_lpid;    /* PID of last shmat(2)/shmdt(2) */
               shmatt_t        shm_nattch;  /* No. of current attaches */
               ...
           };


