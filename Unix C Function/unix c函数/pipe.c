/*
#include<unistd.h>
int pipe(int filedes[2]);
----函数说明 pipe()会建立匿名管道，并将文件描述词由参数filedes数组返回(filedes为文件描述符数组)，filedes[0]为管道里的读取端，filedes[1]则为管道的写入端。
----返回值 若成功则返回0，否则返回-1，错误原因存于errno中。
----函数在内核文件树上建立一个供读写数据的节点，并分别返回该节点的读写文件描述符，该值存放在filedes所指向的数组中
----使用说明：函数使用时，传入一个长度为２的文件描述符数组，然后函数创建一个管道，并使用参数filedes存放该管道的读写两段文件描述符，fd[0]是读出端，fd[1]是写入端，由于管道文件描述符也是系统文件资源，所以在使用完后或不使用时，应调用close关闭文件
----错误代码 
	EMFILE 进程已用完文件描述词最大量。
	ENFILE 系统已无文件描述词可用。
	EFAULT 参数filedes数组地址不合法。
*/

#include<unistd.h>
#include<stdio.h>
int main(){
	int fd[2];
	char buf[50];
	//int fi;
	//fi=open("test.c","r");
	if(pipe(fd)==-1){
		perror("fail to pipe");
		return 1;
	}
	if(write(fd[1],"hello",6)==-1){
		perror("fail to write");
		return 1;
	}
	if(read(fd[0],buf,6)==-1){
		perror("fail to read");
		return 1;
	}
	printf("%d %d\n",fd[0],fd[1]);
printf("%s\n",buf);
close(fd[0]);
close(fd[1]);
return 0;
}





