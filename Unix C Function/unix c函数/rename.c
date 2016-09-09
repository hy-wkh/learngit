rename（更改文件名称或位置）apue-p96
相关函数  link，unlink，symlink
 
#include<stdio.h>
 int rename(const char * oldpath,const char * newpath);
 
----函数说明: rename()会将参数oldpath 所指定的文件名称改为参数newpath所指的文件名称。若newpath所指定的文件已存在，则会被删除。
----返回值: 执行成功则返回0，失败返回-1，错误原因存于errno
 
int renameat(int oldfd,const char *oldname,int newfd,const char *newname);
apue-p96

范例  
/* 设计一个DOS下的rename指令rename 旧文件名新文件名*/
#include <stdio.h>
int main(int argc,char **argv){
	if(argc<3){
		printf(“Usage: %s old_name new_name\n”,argv[0]);
		return 1;
	}
	printf(“%s=>%s”,argc[1],argv[2]);
	if(rename(argv[1],argv[2]<0)
		printf(“error!\n”);
	else
		printf(“ok!\n”);
	return 0;
}
 
　 

