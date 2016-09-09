
strcasecmp（忽略大小写比较字符串）  
相关函数  bcmp，memcmp，strcmp，strcoll，strncmp
 
#include<string.h>
int strcasecmp (const char *s1, const char *s2);
 
----strcasecmp()用来比较参数s1和s2字符串，比较时会自动忽略大小写的差异。
 
返回值: 若参数s1和s2字符串相同则返回0。s1(长度或大小)大于s2则返回大于0 的值，s1若小于s2则返回小于0的值。
 
#include<string.h>
#include<stdio.h>

int main(){
	char A[]="123";
	char E[]="123";
	char B[]="103";
	char C[]="135";
	int val=strcasecmp(E,A);
	printf("%d\n",val);
	
	val=strcasecmp(B,A);
	printf("%d\n",val);
	
	val=strcasecmp(C,A);
	printf("%d\n",val);

return 0;
}


 
　 

