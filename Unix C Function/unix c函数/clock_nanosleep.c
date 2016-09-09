#include<time.h>
int clock_nanosleep(clockid_t clock_id,int flags
					const struct timespec *req,struct timespec *rem);
----clock_id指定了计算延迟时间基于的时钟
	flags用于控制延迟是相对的还是绝对的，另外两个参数和nanosleep的相同（不过使用绝对时间时，sem未使用，因为没有必要）
----返回：若成功休眠要求的时间间隔，则返回０，否则返回错误码










