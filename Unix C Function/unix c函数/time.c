
#include<time.h>
time_t time(time_t *t);
----功能：取得目前的时间
----参数t为系统时间类型time_t指针，在函数成功返回时，将系统的当前时间赋值到ｔ指向的数据结构上
----函数说明 此函数会返回从公元1970年1月1日的UTC时间从0时0分0秒算起到现在所经过的秒数。如果t 并非空指针的话，此函数也会将返回值存到t指针所指的内存。
----返回值 成功则返回秒数，失败则返回((time_t)-1)值，错误原因存于errno中。
----时间函数返回的三种类型：time_t,struct tm,char;



#include<time.h>
struct tm *localtime(const time_t * timep);
----timep为time_t结构体类型的指针，其中存储的是所要转换的系统时间值。
----功能：获得当前系统时间,并将返回的时间存储到一个静态分配的tm结构体中，返回该结构体的指针。
----函数说明 localtime()将参数timep所指的time_t结构中的信息转换成真实世界所使用的时间日期表示方法，然后将结果由结构tm返回。结构tm的定义请参考gmtime()。此函数返回的时间日期已经转换成当地时区。
----返回值：返回结构tm代表目前的当地时间，如果成功，返回值为已转换的日历时间结构体的指针，失败返回NULL,并设置errno.



#include<time.h>
char * asctime(const struct tm * timeptr);
----timeptr是一个tm结构体类型指针，tm结构体中存储的是年，月，日，时，分，秒，星期，天数
----功能：函数将参数所指向的结构体中的时间值，转换成用26字节的字符串格式表示（该字符串以'\0'表示）;
----函数说明 asctime()将参数timeptr所指的tm结构中的信息转换成真实世界所使用的时间日期表示方法，然后将结果以字符串形态返回。此函数已经由时区转换成当地时间，字符串格式为:“Wed Jun 30 21:49:08 1993\n”
----返回值 若再调用相关的时间日期函数，此字符串可能会被破坏。此函数与ctime不同处在于传入的参数是不同的结构。（函数返回一个26字节的字符串指针，它所代表的是字符模式下的时间值）


#include<time.h>
#include<stdio.h>

int main(){
	time_t local_time;
	struct tm *tm_ptr;

	//local_time=time(NULL);
	time(&local_time);
	tm_ptr=localtime(&local_time);
	printf(asctime(tm_ptr));
	return 0;
}



