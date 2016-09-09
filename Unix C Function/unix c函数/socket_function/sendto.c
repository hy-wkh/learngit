     ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
                      const struct sockaddr *dest_addr, socklen_t addrlen);
                      
       ----通常用于UDP套接口，用数据报方式进行数据传输。由于无连接的数据报模式下，没有建立连接，需指明目的地址，addrlen通常为sizeof(sockaddr)的长度。成功时返回发送的字节数，失败返回-1。

       当本地与不同目的地址通信时，只需指定目的地址，可使用同一个UDP套接口描述符sockfd，而TCP要预先建立连接，每个连接都会产生不同的套接口描述符，体现在：客户端要使用不同的fd进行connect，服务端每次accept产生不同的fd。

       因为UDP没有真正的发送缓冲区，因为是不可靠连接，不必保存应用进程的数据拷贝，应用进程中的数据在沿协议栈向下传递时，以某种形式拷贝到内核缓冲区，当数据链路层把数据传出后就把内核缓冲区中数据拷贝删除。因此它不需要一个发送缓冲区。写UDP套接口的sendto/write返回表示应用程序的数据或数据分片已经进入链路层的输出队列，如果输出队列没有足够的空间存放数据，将返回错误ENOBUFS.

	   每一个TCP套接口有一个发送缓冲区，我们可以用SO_SNDBUF套接口选项来改变这个缓冲区的大小。当应用程序调用write时，内核从应用程序进程的缓冲区中拷贝所有数据到套接口的发送缓冲区。如果套接口的发送缓冲区容不下应用程序的所有数据（或是应用程序的缓冲区大于套接口发送缓冲区，或是套接口发送缓冲区还有其他数据），应用进程将被挂起（睡眠）。这里假设套接口是阻塞的，它是通常的缺省设置（还有非阻塞的套接口）。内核将不从write系统调用返回，直到应用程序缓冲区中的所有数据都拷贝到套接口发送缓冲区。因此从写一个TCP套接口的write调用成功返回仅仅表示我们可以重新使用应用进程的缓冲区。它并不告诉我们对端的TCP或应用程序已接收到数据。

TCP取套接口发送缓冲区的数据并把它发送给对端TCP，其过程基于TCP数据传送的所有规则。对端TCP必需确认收到数据，只有收到对端的ACK，本端TCP才能删除套接口发送缓冲区中已确认的数据。TCP必需保留数据拷贝直到对端确认为止。

TCP以MSS大小的或更小的块把数据传递给IP，同时给每个数据块安上一个TCP头部以构成TCP分节，其中的MSS是由对端通告的，当对端未通告时就用536这个值（IPv4的最小重组缓冲区字节数576减去IPv4头部字节20和TCP头部字节数20）。IP给每个TCP分节安上IP头部以构成IP数据报，查找其宿IP地址的路由表项以确定外出接口，然后把数据报传递给相应的数据链路。IP可能在把数据报传递给数据链路之前将其分片，不过我们已经谈到MSS选项的目的之一就是试图避免分片，而较新的实现又使用了路径MTU发现功能。每个数据链路都有一个输出队列，如果该队列已满，那么新到的分组将被丢弃，并沿协议栈向上返回一个错误，从链路层到IP层，再从IP层到TCP层。TCP将注意到这个错误，并在以后某个时刻重传相应分片。应用进程并不知道这种暂时情况。

	   		这一次我们展示的套接口发送缓冲区用虚线框，因为它并不存在。UDP套接口有发送缓冲区大小（我们可以用SO_SNDBUF套接口选项修改），不过它仅仅是写到套接口的UDP数据报的大小上限。如果应用进程写一个大于套接口发送缓冲区大小的数据包，内核将返回一个EMSGSIZE错误。既然UDP是不可靠的，它不必保存应用程序的数据拷贝，因此无需一个真正的发送缓冲区。（应用进程的数据在沿协议向下传递时，以某种形式拷贝到内核的缓冲区，然而数据链路层在送出这些数据后将丢弃该拷贝）

UDP简单地给用户数据报安上它的8个字节的头部以构成UDP数据报，然后传递给IP。IPv4或IPv6给UDP数据报安上相应的IP头部以构成IP数据报，执行路由操作确定外出接口，然后直接把数据包加入数据链路层输出队列（如果适合于MTU），或者分片后再把每个片加入数据链路层的输出队列。如果某个UDP应用进程发送大数据报，那么它比TCP应用进程更有可能分片，因为TCP会把应用数据划分成MSS大小的块，而UDP却没有对等的手段。

从写UDP套接口的write调用成功地返回表示用户写入的数据报或其所有片段已被加入数据链路层的输出队列。如果该队列没有足够的空间存放该数据报或它的某个片段，内核通常将给应用程序返回一个ENOBUFS错误。
 












sendto（经socket传送数据）  
相关函数  send , sendmsg,recv , recvfrom , socket
 
#include < sys/types.h >
#include < sys/socket.h >
 
int sendto ( int s , const void * msg, int len, unsigned int flags, const struct sockaddr * to , int tolen ) ;
 
----函数说明: sendto() 用来将数据由指定的socket传给对方主机。参数s为已建好连线的socket,如果利用UDP协议则不需经过连线操作。参数msg指向欲连线的数据内容，参数flags 一般设0，详细描述请参考send()。参数to用来指定欲传送的网络地址，结构sockaddr请参考bind()。参数tolen为sockaddr的结果长度。
 
----返回值: 成功则返回实际传送出去的字符数，失败返回－1，错误原因存于errno 中。
 
错误代码:
	EBADF 参数s非法的socket处理代码。
	EFAULT 参数中有一指针指向无法存取的内存空间。
	WNOTSOCK canshu s为一文件描述词，非socket。
	EINTR 被信号所中断。
	EAGAIN 此动作会令进程阻断，但参数s的soket为补课阻断的。
	ENOBUFS 系统的缓冲内存不足。
	EINVAL 传给系统调用的参数不正确。
 
范例 : 
#include < sys/types.h >
#include < sys/socket.h >
# include <netinet.in.h>
#include <arpa.inet.h>
#define PORT 2345 /*使用的port*/
main(){
int sockfd,len;
struct sockaddr_in addr;
char buffer[256];
/*建立socket*/
if(sockfd=socket (AF_INET,SOCK_DGRAM,0))<0){
perror (“socket”);
exit(1);
}
/*填写sockaddr_in 结构*/
bzero ( &addr, sizeof(addr) );
addr.sin_family=AF_INET;
addr.sin_port=htons(PORT);
addr.sin_addr=hton1(INADDR_ANY) ;
if (bind(sockfd, &addr, sizeof(addr))<0){
perror(“connect”);
exit(1);
}
while(1){
bezro(buffer,sizeof(buffer));
len = recvfrom(socket,buffer,sizeof(buffer), 0 , &addr &addr_len);
/*显示client端的网络地址*/
printf(“receive from %s\n “ , inet_ntoa( addr.sin_addr));
/*将字串返回给client端*/
sendto(sockfd,buffer,len,0,&addr,addr_len);”
}
}
 
执行  请参考recvfrom()
 
　 
