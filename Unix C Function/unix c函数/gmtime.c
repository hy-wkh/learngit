/* 
gmtime（取得目前时间和日期）  
相关函数  time,asctime,ctime,localtime
#include<time.h>
struct tm*gmtime(const time_t *timep);
----timep中存储的是所要转换的系统时间值
----gmtime()将参数timep 所指的time_t 结构中的信息转换成真实世界所使用的时间日期表示方法，然后将结果由结构tm返回。
----返回值: 返回结构tm代表目前UTC 时间（函数的返回值为以日历时间表示的时间值。成功返回为已转换的日历时间结构体的指针，失败返回NULL,并设置errno）
----函数将参数time所指向的结构体中的时间值转换成相应的日历时间类型tm,并存储到一个××静态××分配的tm结构体中，返回该结构体的指针。
结构tm的定义为:
struct tm{
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
};
int tm_sec 代表目前秒数，正常范围为0-59，但允许至61秒
int tm_min 代表目前分数，范围0-59
int tm_hour 从午夜算起的时数，范围为0-23
int tm_mday 目前月份的日数，范围01-31
int tm_mon 代表目前月份，从一月算起，范围从0-11
int tm_year 从1900 年算起至今的年数
int tm_wday 一星期的日数，从星期一算起，范围为0-6
int tm_yday 从今年1月1日算起至今的天数，范围为0-365
int tm_isdst 日光节约时间的旗标
此函数返回的时间日期未经时区转换，而是UTC时间。
 
*/
范例  
#include <time.h>
int main(){
	char *wday[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	time_t timep;
	struct tm *p;
	time(&timep);
	p=gmtime(&timep);
	printf(“%d%d%d”,(1900+p->tm_year), (1+p->tm_mon),p->tm_mday);
	printf(“%s%d;%d;%d\n”, wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
	return 0;
}
 
执行  2000/10/28 Sat 8:15:38
 
　 
