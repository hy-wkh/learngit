#include <time.h>
int timer_delete(timer_t timerid);
----删除了ID为timerid的POSIX:TMR定时器
----返回：成功返回０，否则返回-1并设置errno.

