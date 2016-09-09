#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
sem_t *sem_open(const char *name, int oflag);
sem_t *sem_open(const char *name, int oflag,
                mode_t mode, unsigned int value);
----该函数建立了命名信号量和sem_t值之间的连接
----name是一个用名字来标示信号量的字符串,该名字可以对应于文件系统中的实际对象，也可以不对应于文件系统中的实际对象
	oflag用来确定是创建信号量还是仅仅由函数对其进行访问:
	***如果设置了oflag的O_CREAT比特位，sem_open就要求另外两个参数：mode_t类型参数mode要求给出权限，unsigned类型的参数value给出信号量的初始值
----成功返回信号量的地址，否则返回SEM_FAILED并设置errno
