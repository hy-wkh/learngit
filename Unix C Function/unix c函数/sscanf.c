sscanf（格式化字符串输入）  
相关函数  scanf，fscanf
 
#include<stdio.h>
int sscanf (const char *str,const char * format,........);
 
----函数说明: sscanf()会将参数str的字符串根据参数format字符串来转换并格式化数据。格式转换形式请参考scanf()。转换后的结果存于对应的参数内。
 
----返回值: 成功则返回参数数目，失败则返回-1，错误原因存于errno中。
 
//范例  
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int main(){
	char str[10];
	fgets(str,sizeof(str),stdin);
	int a,b;
	sscanf(str,"%d %d",&a,&b);
	cout<<a<<" "<<b<<endl;
return 0;
}
//输入：1 2 
//输出：1 2



 
