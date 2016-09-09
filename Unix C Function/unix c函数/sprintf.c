/*
sprintf（格式化字符串复制）
#include<stdio.h>
int sprintf( char *str,const char * format,.........);
----str为目标字符数组，format为格式字符串，其他参数为输入数据
----函数说明 sprintf()会根据参数format字符串来转换并格式化数据，然后将结果复制到参数str所指的字符串数组，直到出现字符串结束(’\0’)为止，并在str的结尾添加字符结束符'\0'.复制过程中会在format参数中依次寻找需要复制的参数，并以特定格式输出到str中，直到format参数中的字符串结束符'\0'为止(关于参数format字符串的格式请参考printf()。)
----返回: 成功则返回参数str字符串长度，失败则返回-1，错误原因存于errno中。
----附加说明 使用此函数得留意堆栈溢出，或改用snprintf().
*/
#include<stdio.h>
#define BUF_SIZE 1024
int main(){
	char str[BUF_SIZE];
	int year,month,day;
	scanf("%d %d %d",&year,&month,&day);
	if((sprintf(str,"year:%d--month:%d--day:%d",year,month,day))==-1){
		perror("fail to sprintf");
		return 1;
	}
	printf("date is %s\n",str);
	return 0;
}

