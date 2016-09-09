
#include<unistd.h>
int fsync(int filedes);
----filedes表示需要写回到磁盘的文件
----返回：成功返回０，失败返回-1
----功能：fsync可以确保文件的实际写出，该函数会阻塞直到修改的盘块写到外存后才返回。
----fsync函数会将内存中的数据内容回写到磁盘空间，但是是否会达到实际的回写效果需要依赖于文件系统的实现

int datasync(int filedes);
----该函数类似于fsync，但它只影响文件的数据部分。而除数据外，fsync还会同步更新文件的属性
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
	int fd;
	int i;
	fd=open("test.c",O_RDWR);
	if(fd==-1){
		perror("fail to open");
		return 1;
	}
	for(i=0;i<3;++i){
		sleep(5);
		printf("hi\n");
		if(write(fd,"hi\n",3)==-1){
			perror("fail to write");
			return 1;
		}
		if(fsync(fd)==-1){
			perror("fail to fsync");
			return 1;
		}
	}
close (fd);
return 1;
}









