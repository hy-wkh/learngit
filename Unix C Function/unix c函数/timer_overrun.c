p240
#include <time.h>
int timer_getoverrun(timer_t timerid);
----该函数用来确定一个特定的定时器出现超时限制的次数
----成功返回超限的次数，否则返回-1并设置errno


#include <time.h>
int timer_settime(timer_t timerid, int flags,
                         const struct itimerspec *new_value,
                         struct itimerspec * old_value);
----该函数负责启动或停止timer_create创建的定时器，flags说明定时器使用的是相对时间还是绝对时间
----new_value指向的值用来用来设置timerid定时器
----old_value如果不为NULL,则用来存放定时器以前的值
----成功返回0，否则返回-1并设置errno

#include <time.h>
int timer_gettime(timer_t timerid, struct itimerspec *curr_value);
----用来获取一个活动定时器的剩余时间
----成功返回0，否则返回-1并设置errno

struct timespec {
    time_t tv_sec;                /* Seconds */
    long   tv_nsec;               /* Nanoseconds */
};

struct itimerspec {
    struct timespec it_interval;  /* Timer interval */
    struct timespec it_value;     /* Initial expiration */
};














