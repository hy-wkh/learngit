/*#include<time.h>
size_t strftime(char *str,size_t maxsize,
				const char *format,const struct tm *time);
----str为字符数组指针，该参数用于存放函数根据要求转换的时间字符串数组
	maxsize用于指定str数组的长度
	format为所要求的格式化字符串
	tm为要转换的时间结构体
----返回：成功返回转换后字符串的长度（不包含'\0')失败返回０，并设置errno
----功能：函数根据格式化字符串转换参数tm制定结构体中的数据到参数str指向的字符串数组中
----format为格式字符串，该格式字符串中格式与sprintf函数有明显区别，如不支持指定位数。如果转换后的字符串长度超出了指定的缓冲区大小，则函数失败返回。此时应提供更大的缓冲区再试
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	time_t t;
	struct tm *tmp;
	char buf1[16];
	char buf2[64];

	time(&t);
	tmp=localtime(&t);
	if(strftime(buf1,16,"time and date :%r,%a %b %d,%Y",tmp)==0)
		perror("length 16 is small");
	else 
		printf("%s\n",buf1);
	if(strftime(buf2,64,"time and date :%r,%a %b %d,%Y",tmp)==0)
		perror("length 64 is small");
	else 
		printf("%s\n",buf2);
return 0;
}









