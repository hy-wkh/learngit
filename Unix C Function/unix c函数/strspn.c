 
strspn（返回字符串中连续不含指定字符串内容的字符数）  
相关函数  strcspn，strchr，strpbrk，strsep，strstr
 
#include<string.h>
size_t strspn (const char *s,const char * accept);
 
----strspn()从参数s 字符串的开头计算连续的字符，而这些字符都完全是accept 所指字符串中的字符。简单的说，若strspn()返回的数值为n，则代表字符串s 开头连续有n 个字符都是"属于"字符串accept内的字符。
 
----返回值: 返回字符串s开头连续包含字符串accept内的字符数目(没有的话返回0)。
 
#include<string.h>
int main()
{
	char *str="Linux was first developed for 386/486-based PCs.";
	char *t1="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	printf("%d\n",strspn(str,t1));
return 0;
}
 
执行  5 /*计算大小写字母。不包含“ ”，所以返回Linux的长度。*/
 
　 
