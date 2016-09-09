/*
#include<string.h>
void *memcpy(void *dest,const void *src,size_t n);
----dest表示目的内存区
----src表示源内存区
----n表示要复制的字节数
----返回值：指向dest的指针
----功能：函数将源内存区src的前n个字节的内容复制到目的内存区dest中。在复制字符串时，与strncpy及strcpy函数不同的是，该函数不会在遇到　'\0' 时停止复制，而是将参数src的前几个字节内容全部复制到dest指向的内存中。
----可以复制数组；（相当于给数组赋值）
*/
#include<stdio.h>
#include<string.h>
int main(){
	char ch1[20]="0";
	char ch2[20]="Wilcone to China";
	char *p;
	int n=18;
	p=memcpy(ch1,ch2,n);
printf("%s\n",ch1);
printf("%s\n",p);
return 0;
}
















