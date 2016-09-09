 /*
#include<stdlib.h>
char *getenv(const char *name);
----name代表指定的环境变量的名称，该函数寻找一个形如name=value的字符串，将value字符串的内容作为环境变量的值返回。
----如果成功，getenv函数返回该环境变量值字符串的首地址，失败返回NULL。

*/

#include<stdlib.h>
#include<stdio.h>

int main(){
	char *s;
	s=getenv("HOME");
	if(s==NULL){
		perror("fail to get env...\n");
		exit (1);
	}
	printf("%s\n",s);
	return 0;
}









