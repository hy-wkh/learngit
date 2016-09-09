/*
#include<dirent.h>
void rewinddir(DIR *dir);
----功能：该函数把目录流重定位在起始处（函数将一个目录的当前读写位置回到目录文件的开始处，这个操作称为回卷）。
----参数dir表示对应于打开的目录流（表示需要回卷的目录文件）
----返回值：该函数不需要返回值。
----目录文件作为一种文件，其内部存储文件的目录项。每次读目录文件实际上跳过一个目录项的大小。因此目录文件也可以回卷
*/
#include<stdio.h>
#include<errno.h>
#include<dirent.h>
#include<unistd.h>
int main(){
	DIR *dir;
	struct dirent *ptr;
	dir=opendir("/home/hy/桌面");
	if(dir==NULL){
		perror("fail to opendir");
		return 1;
	}
	errno=0;
	while((ptr=readdir(dir))!=NULL){//记得打括号
		printf("%s\n",ptr->d_name);
	}
	if(errno==1){
		perror("fail to readdir");
		return 1;
	}
	printf("******again*******\n");
	rewinddir(dir);
	while((ptr=readdir(dir))!=NULL){
		printf("%s\n",ptr->d_name);
	}
	closedir(dir);
return 0;				
}











