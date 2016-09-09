 
strpbrk（查找字符串中第一个出现的指定字符）  
相关函数  index，memchr，rindex，strpbrk，strsep，strspn，strstr，strtok strchr
 
#include <include.h>
char *strpbrk(const char *s,const char *accept);
 
----strpbrk()用来找出参数s 字符串中最先出现存在参数accept 字符串中的任意字符。
 
----返回值: 如果找到指定的字符则返回该字符所在地址，否则返回0。
 
#include <string.h>
int main()
{
	char *s="0123456789012345678901234567890";
	char *p;
	p=strpbrk(s,"a1 839"); /*1会最先在s字符串中找到*/
	printf("%s\n",p);
	p=strprk(s,"4398");/*3 会最先在s 字符串中找到*/
	printf("%s\n",p);
return 0;
}
执行  1.23E+29
 
　 

