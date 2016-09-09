      
       //#include <sys/types.h>
       //#include <sys/socket.h>
       ssize_t recv(int sockfd, void *buf, size_t len, int flags);
       
        ----sockfd：接收端套接字描述符；
			buf：指定缓冲区地址，用于存储接收数据；
			len：指定的用于接收数据的缓冲区长度；
			flags：一般指定为0
       ----返回：表示从接收缓冲区拷贝数据。成功时，返回拷贝的字节数，失败返回-1。阻塞模式下，recv/recvfrom将会阻塞到缓冲区里至少有一个字节(TCP)/至少有一个完整的UDP数据报才返回，没有数据时处于休眠状态。若非阻塞，则立即返回，有数据则返回拷贝的数据大小，否则返回错误-1，置错误码为EWOULDBLOCK。
       
    









 
recv（经socket接收数据）  
相关函数  recvfrom，recvmsg，send，sendto，socket
 
#include<sys/types.h>
#include<sys/socket.h>
int recv(int s,void *buf,int len,unsigned int flags);
 
----recv()用来接收远端主机经指定的socket传来的数据，并把数据存到由参数buf 指向的内存空间，参数len为可接收数据的最大长度。

参数:
	flags一般设0。其他数值定义如下:
	MSG_OOB 接收以out-of-band 送出的数据。
	MSG_PEEK 返回来的数据并不会在系统内删除，如果再调用recv()会返回相同的数据内容。
	MSG_WAITALL强迫接收到len大小的数据后才能返回，除非有错误或信号产生。
	MSG_NOSIGNAL此操作不愿被SIGPIPE信号中断返回值成功则返回接收到的字符数，失败返回-1，错误原因存于errno中。
 
错误代码:  
	EBADF 参数s非合法的socket处理代码
	EFAULT 参数中有一指针指向无法存取的内存空间
	ENOTSOCK 参数s为一文件描述词，非socket。
	EINTR 被信号所中断
	EAGAIN 此动作会令进程阻断，但参数s的socket为不可阻断
	ENOBUFS 系统的缓冲内存不足。
	ENOMEM 核心内存不足
	EINVAL 传给系统调用的参数不正确。
 
范例  参考listen()。
 
