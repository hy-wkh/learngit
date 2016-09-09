/*
#include<stdio.h>
int feof(FILE *stream);
----注意参数是文件指针类型。
----返回:函数返回int型，说明文件是否到文件结尾。
----函数会检查stream的当前操作位置，经到文件的结尾则返回非0值，否则返回0.（函数feof在运行时会从文件中读出一个字符，并判断该字符是否是EOF字符，是则返回非0，否则返回0）
*/
#include<stdio.h>

int main(){
	FILE *fd;
	fd=fopen("1.c","rb");
	if(fd==NULL){
		perror("fail to open");
		return 0;
	}
	char ch;
	ch=getc(fd);
	while(!feof(fd)){
		putchar(ch);
		ch=getc(fd);
	}
	fclose(fd);
	return 0;
}












