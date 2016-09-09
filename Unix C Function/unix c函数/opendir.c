/*
#include<dirent.h>
DIR *opendir(const char *pathname);
----pathname表示需要打开目录的路径名。
----返回：返回值是一个DIR结构的指针。该结构是一个内部结构，用于保存所打开目录的信息，其作用类似于FILE结构。如果出错则返回NULL.
----功能：函数打开一个目录文件，之后就可以像操作普通文件一样操作该文件。(作用和ls命令一样)

DIR *fdopendir(int fd);
----这两个返回的指向DIR结构的指针由另外５个函数使用
----fdopendir函数提供了一种把打开文件描述符转换成目录处理函数需要的DIR结构
struct dirent *readdir(DIR *dp);
void rewinddir(DIR *dp);
int closedir(DIR *dp);
long telldir(DIR *dp);
void seekdir(DIR *dp,long loc);
*/
#include<dirent.h>
#include<stdio.h>
#include<errno.h>
#define M 1024
int main(){
	DIR *dir;
	struct dirent *ptr;
	char buf[M];
	if((getcwd(buf,M))==NULL){
		perror("fail to getcwd");
		return 1;
	}
	dir=opendir(buf);
	if(dir==NULL){
		perror("fail to opendir");
		return 1;
	}
	errno=0;
	while((ptr=readdir(dir))!=NULL){
		printf("%s\n",ptr->d_name);
	}
	if(errno!=0){
		perror("fail to readdir");
		return 1;
	}
	closedir(dir);
	return 0;
}








