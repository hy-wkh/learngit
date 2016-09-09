

       //#include <sys/types.h>          /* See NOTES */
       //#include <sys/socket.h>
       int listen(int sockfd, int backlog);
       ----在编写服务器程序时需要使用监听函数 listen 。服务器进程不知道要与谁连接，因此，它不会主动地要求与某个进程连接，只是一直监听是否有其他客户进程与之连接，然后响应该连接请求，并对它做出处理，一个服务进程可以同时处理多个客户进程的连接。
       
       ----listen 函数仅由 TCP 服务器调用，它有以下两种作用：
		   当 socket 函数创建一个套接字时，若它被假设为一个主动套接字，即它是一个将调用connect 发起连接的客户端套接字。listen 函数把一个未连接的套接字转换成一个被动套接字，指示内核应该接受指向该套接字的连接请求;
	       listen 函数的第二个参数规定内核应该为相应套接字排队的最大连接个数;listen 函数一般应该在调用socket 和bind 这两个函数之后，并在调用 accept 函数之前调用。 内核为任何一个给定监听套接字维护两个队列：
		   未完成连接队列，每个这样的 SYN 报文段对应其中一项：已由某个客户端发出并到达服务器，而服务器正在等待完成相应的 TCP 三次握手过程。这些套接字处于 SYN_REVD 状态;
		   已完成连接队列，每个已完成 TCP 三次握手过程的客户端对应其中一项。这些套接字处于 ESTABLISHED 状态;







 listen（等待连接）  
相关函数: socket，bind，accept，connect
 
#include<sys/socket.h> 
int listen(int s,int backlog);
 
----函数说明  listen()用来等待参数s 的socket连线。参数backlog指定同时能处理的最大连接要求，如果连接数目达此上限则client端将收到ECONNREFUSED的错误。Listen()并未开始接收连线，只是设置socket为listen模式，真正接收client端连线的是accept()。通常listen()会在socket()，bind()之后调用，接着才调用accept()。

----函数listen允许服务器为传入的请求准备一个套接字。根据不同的底层协议，listen将套接字置于被动模式,准备接受连接。当服务器唤醒listen时，它也通知操作系统协议软件将同时到达套接字的请求排队。

----返回值  成功则返回0，失败返回-1，错误原因存于errno
 
----附加说明  listen()只适用SOCK_STREAM或SOCK_SEQPACKET的socket类型。如果socket为AF_INET则参数backlog 最大值可设至128。
 
错误代码:
	EBADF 参数sockfd非合法socket处理代码
	EACCESS 权限不足
	EOPNOTSUPP 指定的socket并未支援listen模式。
 
范例:

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define PORT 1234
#define MAXSOCKFD 10
main()
{
int sockfd,newsockfd,is_connected[MAXSOCKFD],fd;
struct sockaddr_in addr;
int addr_len = sizeof(struct sockaddr_in);
fd_set readfds;
char buffer[256];
char msg[ ] =”Welcome to server!”;
if ((sockfd = socket(AF_INET,SOCK_STREAM,0))<0){
perror(“socket”);
exit(1);
}
bzero(&addr,sizeof(addr));
addr.sin_family =AF_INET;
addr.sin_port = htons(PORT);
addr.sin_addr.s_addr = htonl(INADDR_ANY);
if(bind(sockfd,&addr,sizeof(addr))<0){
perror(“connect”);
exit(1);
}
if(listen(sockfd,3)<0){
perror(“listen”);
exit(1);
}
for(fd=0;fd<MAXSOCKFD;fd++)
is_connected[fd]=0;
while(1){
FD_ZERO(&readfds);
FD_SET(sockfd,&readfds);
for(fd=0;fd<MAXSOCKFD;fd++)
if(is_connected[fd]) FD_SET(fd,&readfds);
if(!select(MAXSOCKFD,&readfds,NULL,NULL,NULL))continue;
for(fd=0;fd<MAXSOCKFD;fd++)
if(FD_ISSET(fd,&readfds)){
if(sockfd = =fd){
if((newsockfd = accept (sockfd,&addr,&addr_len))<0)
perror(“accept”);
write(newsockfd,msg,sizeof(msg));
is_connected[newsockfd] =1;
printf(“cnnect from %s\n”,inet_ntoa(addr.sin_addr));
}else{
bzero(buffer,sizeof(buffer));
if(read(fd,buffer,sizeof(buffer))<=0){
printf(“connect closed.\n”);
is_connected[fd]=0;
close(fd);
}else
printf(“%s”,buffer);
}
}
}
}
 
执行  $ ./listen
connect from 127.0.0.1
hi I am client
connected closed.
 
　 
