/*
#include <time.h>
int clock_getres(clockid_t clk_id, struct timespec *res);
int clock_gettime(clockid_t clk_id, struct timespec *tp);
int clock_settime(clockid_t clk_id, const struct timespec *tp);
----第一个参数都是clockid_t类型的变量表示的时钟，clockid_t的值为CLOCK_REALTIME的时钟，这个时钟对应于系统时钟
----clock_getres():确定时钟分辨率， 
	clock_gettime()获取时钟时间的函数，
	clock_settime():设置时钟的函数。
----返回：成功返回０，否则返回-1并设置errno.(p226)
struct timespec {
    time_t tv_sec;      /seconds/
    long tv_nsec;       /nanoseconds/
};


*/















