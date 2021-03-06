
popen（创建管道文件）  
相关函数 pipe，mkfifo，pclose，fork，system，fopen
#include<stdio.h>
FILE * popen( const char * command,const char * type);
----command是字符串指针，该字符串中存储的是所要执行的命令。参数type指定了建立的管道的数据方向
----popen()会先创建一个管道，然后调用fork()创建一个子进程，并在子进程中调用system（或者exec）函数来执行参数command中的内容（也有一种说法是从子进程中调用/bin/sh -c来执行参数command的指令），再根据参数type的值来重定向子进程的标准输入或标准输出，并返回该重定向后的值。参数type可使用“r”代表读取，“w”代表写入。依照此type值，popen()会建立管道连到子进程的标准输出设备或标准输入设备，然后返回一个文件指针。随后进程便可利用此文件指针来读取子进程的输出设备或是写入到子进程的标准输入设备中。此外，所有使用文件指针(FILE*)操作的函数也都可以使用，除了fclose()以外。
----返回值: 若成功则返回一个供读或写的流文件指针，否则返回NULL，错误原因存于errno中。
----错误代码: EINVAL参数type不合法。
----注意事项: 在编写具SUID/SGID权限的程序时请尽量避免使用popen()，popen()会继承环境变量，通过环境变量可能会造成系统安全的问题。
----popen会建立一个父子进程通信的管道，当前进程为父进程，参数command为子进程所要执行的程序或命令。函数返回值为管道的另一端，读写权限由type指定

#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[]){
	char command[20];
	char buf[200];
	FILE *fp;
	snprintf(command,100,"cat %s",argv[1]);
	fp=popen(command,"r");
	fgets(buf,200,fp);  //读取管道内容
	fputs(buf,stdout);
	return 0;
}



#include<stdio.h>
int main(){
	FILE *fp;
	char buf[80];
	fp=popen("cat -n /etc/passwd","r");
	fgets(buf,sizeof(buf),fp);
	printf("%s\n",buf);
pclose(fp);
return 0;
}




