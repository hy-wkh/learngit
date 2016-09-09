/*
#include<stdlib.h>
int atoi(const char *nptr);
----参数nptr表示将要被转换成整数的字符串
----返回值：被转换后的整数
----1.将被转换的字符逐个字符进行转换
	2.如果开头是空格，则会跳过，直到数字或正负符号时开始转换
	3.遇到'\0'或其他非数字字符时，该函数立即停止转换，并将转换后的数字返回
*/
#include<stdlib.h>
#include<stdio.h>
int main(){
	char *s1="-20080808";
	char *s2=" 020080808";
	char *s3="2008.0808";
	int r1=0,r2=0,r3=0;
	r1=atoi(s1);
	r2=atoi(s2);
	r3=atoi(s3);
	printf("%d %d %d\0",r1,r2,r3);
	return 0;
}







