strncpy（拷贝字符串）  
相关函数  bcopy，memccpy，memcpy，memmove
#include<string.h>
char * strncpy(char *dest,const char *src,size_t n);
----strncpy()会将参数src字符串拷贝前n个字符至参数dest所指的地址。
 
----返回值: 返回参数dest的字符串起始地址。
 
#inclue <string.h>
int main(){
	char a[30]="string(1)";
	char b[]="string(2)";
	printf("before strncpy() : %s\n",a);
	printf("after strncpy() : %s\n",strncpy(a,b,6));
}
 
执行  before strncpy() : string(1)
after strncpy() : string(1)
 
　 

