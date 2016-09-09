/*
#include<time.h>
char *ctime(const time_t *timep);
----timep为一个time_t类型的指针，它所指向的数据结构为一个系统时间值
----功能：将时间和日期以字符串格式表示表头文件 
----函数说明 ctime()将参数timep所指的time_t结构中的信息转换成真实世界所使用的时间日期表示方法，然后将结果以字符串形态返回。此函数已经由时区转换成当地时间，字符串格式为“Wed Jun 30 21 :49 :08 1993\n”。若再调用相关的时间日期函数，此字符串可能会被破坏。
----返回值 返回一字符串表示目前当地的时间日期。（返回值是一个26字节的字符串指针，它所代表的是字符模式下的时间值）
----函数返回的是一个静态分配的内存空间，每一次调用函数都会覆盖掉内存空间的原始值，所以想保存原始值，需要使用另一个临时变量
*/
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
	time_t loc_time;
	struct tm *tm_ptr;	
	char *buf,*buf1;
	loc_time=time(NULL);
	buf=ctime(&loc_time);
	printf("%s\n",buf);

	loc_time-=60*60*24;//减去一天
	buf1=ctime(&loc_time);
	printf("%s",buf1);
	return 0;
}




