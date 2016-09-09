/*
#include<dirent.h>
int closedir(DIR *dp);
----dp表示需要关闭的目录文件
----返回：如果成功关闭目录，返回０，否则返回-1;
----功能：close关闭一个目录，关闭之后则不能在用该目录；
----说明：目录作为一种文件，在打开后必须关闭，否则会由于进程打开文件过多而不能打开新的文件。
*/
#include<dirent.h>
#include<stdio.h>
#include<errno.h>
#define M 1024
int main(){
	DIR *dir;
	struct dirent *ptr;
	char buf[M];
	if(getcwd(buf,M)==NULL){
		perror("fail to getcwd");
		return 1;
	}
	dir=opendir(buf);
	if(dir==NULL){
		perror("fail to opendir");
		return 1;
	}
	errno=0;
	while((ptr=readdir(dir))!=NULL){//顺序读取每一个目录项
		printf("%s\n",ptr->d_name);
	}
	if(errno!=0){//如果errno是0,说明目录中的目录项已经全部读完
		perror("fail to readdir");
		return 1;
	}
	closedir(dir);
	return 0;
}



