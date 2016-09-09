/*
#include<string.h>
char *strerror(int errnum);
----函数中的errnum为一个整数常量，用于指定错误代码
----返回：成功后返回值为错误表述字符串的指针，执行失败则返回NULL
----功能：函数根据errnum的值查找该错的提示消息，并返回该消息的字符串指针。
*/
#include<string.h>
#include<errno.h>
#include<stdio.h>
int main(){
	int i;
	for(i=0;i<=15;++i){
		printf("%d :%s\n",i,strerror(i));
	}
	return 0;
}









