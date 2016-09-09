#include<time.h>
int nanosleep(const struct timespec *req,
			  struct timespec *rem);
----req指定了需要休眠的时间长度,rem指向的timespec结构会被设置为未休眠完的时间长度
----这个函数挂起调用进程，直到要求的时间已经超时或者某个信号中断了该函数
----返回值：若从休眠到要求的时间，返回０;若出错返回－1
struct timespec {
    time_t tv_sec;        /* seconds */
    long   tv_nsec;       /* nanoseconds */
};




