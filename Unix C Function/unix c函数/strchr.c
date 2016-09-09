
strchr（查找字符串中第一个出现的指定字符）  
相关函数  index，memchr，rinex，strbrk，strsep，strspn，strstr，strtok strpbrk
 
#include<string.h>
char * strchr (const char *s,int c);
 
----strchr()用来找出参数s字符串中第一个出现的参数c地址，然后将该字符出现的地址返回。
 
返回值: 如果找到指定的字符则返回该字符所在地址，否则返回0。
 
#include<string.h>
int main()
{
	char *s="0123456789012345678901234567890";
	char *p;
	p=strchr(s,'5');
	printf("%s\n",p);
return 0;
}

hy@hy-K53BE:~/桌面$ ./ff
56789012345678901234567890

