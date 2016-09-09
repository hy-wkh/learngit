/*
#include<stdio.h>
FILE *tmpfile();
----返回：成功返回一个流文件的指针，失败返回NULL,并设置errno
----功能：函数构建一个临时的二进制文件用于程序的读写操作，并为这个文件构造一个具有唯一性的名字。
----在当前进程中最多可以打开TMP_MAX个文件，建立该文件在程序结束后会自动删除。所以如果文件中的数据以后需要使用，应该构建一个新的文件转存
----记得要fclose....

char *tmpnam(char *ptr);
*/
#include<stdio.h>
#define BUF_SIZE 80
int main(){
	FILE *fp;
	char str[BUF_SIZE];
	if((fp=tmpfile())==NULL){
		perror("fail to tmpfile");
		return 1;
	}
	fputs("This is the tmp file\n",fp);
	rewind(fp);
	fgets(str,BUF_SIZE,fp);
	puts(str);
	fclose(fp);
	return 0;
}












