
execl（执行文件）  
相关函数  fork，execle，execlp，execv，execve，execvp
 
#include<unistd.h>
int execl(const char * path,const char * arg,....);
 
----execl()用来执行参数path字符串所代表的文件路径，接下来的参数代表执行该文件时传递过去的argv(0)、argv[1]……，最后一个参数必须用空指针(NULL)作结束。
 
----返回值: 如果执行成功则函数不会返回，执行失败则直接返回-1，失败原因存于errno中。
 
#include<unistd.h>
int main(){
	//ls 在/bin/ls目录下，cat也是
	execl("/bin/ls","ls","-al","/etc/passwd",(char *)0);
	return 0;
}

#include<unistd.h>
int main(){
	execl("/bin/cat","cat","-n","/home/hy/Pipe.cpp",(char *)0);
	return 0;
}

执行  /*执行/bin/ls -al /etc/passwd */
-rw-r--r-- 1 root root 705 Sep 3 13 :52 /etc/passwd
 
　 
