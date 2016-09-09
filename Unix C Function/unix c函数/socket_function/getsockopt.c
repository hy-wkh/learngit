 
getsockopt（取得socket状态）  
相关函数  setsockopt
 
#include<sys/types.h>
#include<sys/socket.h>
 
int getsockopt(int s,int level,int optname,
               void* optval,socklen_t* optlen);
 
----getsockopt()会将参数s所指定的socket状态返回。参数
	optname代表欲取得何种选项状态，
	而参数optval则指向欲保存结果的内存地址，
	参数optlen则为该空间的大小。  
	参数level、optname请参考setsockopt()。

返回值: 成功则返回0，若有错误则返回-1，错误原因存于errno
 
错误代码:  
	EBADF 参数s 并非合法的socket处理代码
	ENOTSOCK 参数s为一文件描述词，非socket
	ENOPROTOOPT 参数optname指定的选项不正确
	EFAULT 参数optval指针指向无法存取的内存空间
 
范例  
#include<sys/types.h>
#include<sys/socket.h>
int main()
{
	int s,optval,optlen = sizeof(int);
	if((s = socket(AF_INET,SOCK_STREAM,0))<0) perror(“socket”);
	getsockopt(s,SOL_SOCKET,SO_TYPE,&optval,&optlen);
	printf(“optval = %d\n”,optval);
	close(s);
}
 
执行  optval = 1 /*SOCK_STREAM的定义正是此值*/
 
　 
