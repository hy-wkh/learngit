#include<semaphore.h>
int sem_unlink(const char *name);
----该函数与unlink函数类似，在所有进程关闭了命名信号量之后，将命名信号量从系统中删除，name指向要删除的那个信号量的指针
----成功返回０，否则返回-1并设置errno
