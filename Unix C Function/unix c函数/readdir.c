/*
#include<dirent.h>
struct dirent* readdir(DIR *DP);
----dp是需要读取内容的目录
----返回：readdir函数返回读取的文件的目录项，如果目录到达结尾或者出错，函数返回NULL。因此，判断readdir函数是否出错应当判断errno的值。
----功能：readdir函数读取目录中每一个文件的目录项，并将其返回。子目录作为文件的一种，同样会返回目录项
*/
#include<dirent.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#define M 1024

int get_file_count(char *buf){
	DIR *dir;
	struct dirent *ptr;
	int total=0;
	char path[M];

	dir=opendir(buf);
	if(dir==NULL){
		perror("fail to opendir");
		return 1;
	}
	errno=0;
	while((ptr=readdir(dir))!=NULL){
		if(strcmp(ptr->d_name,".")==0||strcmp(ptr->d_name,"..")==0)continue;
		if(ptr->d_type==DT_DIR){
			sprintf(path,"%s/%s",buf,ptr->d_name);
			//printf("%s\n",path);
			total+=get_file_count(path);//////////////////
		}
		if(ptr->d_type==DT_REG)total++;
		
	}
	if(errno!=0){
		perror("fail to readdir");
		return 1;
	}
	closedir(dir);
	//printf("####%d\n",total);
	return total;
}

int main(int argc,char *argv[]){
		int total=0;
		if(argc!=2){
			perror("wrong usage");
			return 1;
		}
		total+=get_file_count(argv[1]);
		printf("%s has %d files\n",argv[1],total);
	return 0;
}
