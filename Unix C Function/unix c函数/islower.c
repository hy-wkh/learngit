
islower（测试字符是否为小写字母）  
相关函数  isalpha，isupper
 
#include<ctype.h>
int islower(int c)
----检查参数c是否为小写英文字母。
----若参数c为小写英文字母，则返回TRUE，否则返回NULL(0)。
 
附加说明: 此为宏定义，非真正函数。
 
#include<ctype.h>
int main()
{
	char str[]="123@#FDsP[e?";
	int i;
	for(i=0;str[i]!=0;i++)
	if(islower(str[i])) printf("%c is a lower-case character\n",str[i]);
}
 
执行  
c is a lower-case character
s is a lower-case character
e is a lower-case character
 
　 

 
