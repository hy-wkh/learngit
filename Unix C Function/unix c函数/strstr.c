  
strstr（在一字符串中查找指定的字符串）  
相关函数  index，memchr，rindex，strchr，strpbrk，strsep，strspn，strtok
 
#include<string.h>
char *strstr(const char *haystack,const char *needle);
 
----strstr()会从字符串haystack 中搜寻字符串needle，并将第一次出现的地址返回。
 
返回值: 返回指定字符串第一次出现的地址，否则返回0。
 
#include<string.h>
#include<stdio.h>
int main()
{
	char * s="012345678901234567890123456789";
	char *p;
	p= strstr(s,"90a");
	if(p!=NULL)printf("%s\n",p);
	else printf("NULL\n");
return 0;
}
 
hy@hy-K53BE:~/桌面$ cc -o ff tmp.c
hy@hy-K53BE:~/桌面$ ./ff
901234567890123456789  //返回的地址就是该字符串的首地址
 

