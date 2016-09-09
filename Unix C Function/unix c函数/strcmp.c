
strcmp（比较字符串）  
相关函数  bcmp，memcmp，strcasecmp，strncasecmp，strcoll
 
#include<string.h>
int strcmp(const char *s1,const char *s2);
 
----strcmp()用来比较参数s1和s2字符串。字符串大小的比较是以ASCII 码表上的顺序来决定，此顺序亦为字符的值。strcmp()首先将s1第一个字符值减去s2第一个字符值，若差值为0则再继续比较下个字符，若差值不为0则将差值返回。例如字符串"Ac"和"ba"比较则会返回字符"A"(65)和'b'(98)的差值(－33)。
 
----若参数s1和s2字符串相同则返回0。s1若大于s2则返回大于0的值。s1若小于s2则返回小于0 的值。
 
#include<string.h>
int main()
{
	char *a="aBcDeF";
	char *b="AbCdEf";
	char *c="aacdef";
	char *d="aBcDeF";
	printf("strcmp(a,b) : %d\n",strcmp(a,b));
	printf("strcmp(a,c) : %d\n",strcmp(a,c));
	printf("strcmp(a,d) : %d\n",strcmp(a,d));
return 0;
}
 
执行  strcmp(a,b) : 32
strcmp(a,c) :-31
strcmp(a,d) : 0
 
　 

