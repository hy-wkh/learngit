/*
#include<time.h>
char *asctime_r(const struct tm *restrict timeptr,char *restrict buf);
char *ctime_r(const time_t *clock,char *buf);
struct tm *gmtime_r(const time_t *restrict timer,
				    struct tm *restrict result);
struct tm *localtime_r(const time_t *restrict timer,
					   struct tm *restrict result);
----这些都是线程安全版本的函数，它们都将一个由调用程序提供的缓冲区作为额外的参数
----返回：它们返回一个指向装载结果的参数的指针，前两个函数将结果存储在buf中，后两个将结果存储在result中。失败返回NULL
----
struct tm {
     int tm_sec;    / Seconds (0-60) /
     int tm_min;    / Minutes (0-59) /
	 int tm_hour;   / Hours (0-23) /
     int tm_mday;   / Day of the month (1-31) /
     int tm_mon;    / Month (0-11) /
     int tm_year;   / Year - 1900 /
	 int tm_wday;   / Day of the week (0-6, Sunday = 0) /
     int tm_yday;   / Day in the year (0-365, 1 Jan = 0) /
     int tm_isdst;  / Daylight saving time /
};




