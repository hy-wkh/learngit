
       //#include <sys/types.h>
       //#include <sys/socket.h>
       ssize_t send(int sockfd, const void *buf, size_t len, int flags);
       
       ----sockfd:发送端套接字描述符(非监听描述符)
       	   buf：应用要发送数据的缓存
       	　　　len：实际要发送的数据长度
      	 　　flags：一般设置为0
      	 　　
       ----每个TCP套接口都有一个发送缓冲区，它的大小可以用SO_SNDBUF这个选项来改变。调用send函数的过程，实际是内核将用户数据拷贝至TCP套接口的发送缓冲区的过程：若len大于发送缓冲区大小，则返回-1；否则，查看缓冲区剩余空间是否容纳得下要发送的len长度，若不够，则拷贝一部分内容到缓冲区，并返回拷贝长度（指的是非阻塞send，若为阻塞send，则一定等待所有数据拷贝至缓冲区才返回，因此阻塞send返回值必定与len相等）；若缓冲区满，则等待发送，有剩余空间后拷贝至缓冲区；若在拷贝过程出现错误，则返回-1。关于错误的原因，查看errno的值。

       如果send在等待协议发送数据时出现网络断开的情况，则会返回-1。注意：send成功返回并不代表对方已接收到数据，如果后续的协议传输过程中出现网络错误，下一个send便会返回-1发送错误。TCP给对方的数据必须在对方给予确认时，方可删除发送缓冲区的数据。否则，会一直缓存在缓冲区直至发送成功（TCP可靠数据传输决定的）。











 
send（经socket传送数据）  
相关函数  sendto，sendmsg，recv，recvfrom，socket
 
#include<sys/types.h>
#include<sys/socket.h>
int send(int s,const void * msg,int len,unsigned int falgs);
 
----send()用来将数据由指定的socket 传给对方主机。参数s为已建立好连接的socket。参数msg指向欲连线的数据内容，参数len则为数据长度。参数flags一般设0，其他数值定义如下
	MSG_OOB 传送的数据以out-of-band 送出。
	MSG_DONTROUTE 取消路由表查询
	MSG_DONTWAIT 设置为不可阻断运作
	MSG_NOSIGNAL 此动作不愿被SIGPIPE 信号中断。
 
----返回值: 成功则返回实际传送出去的字符数，失败返回-1。错误原因存于errno
 
错误代码  
	EBADF 参数s 非合法的socket处理代码。
	EFAULT 参数中有一指针指向无法存取的内存空间
	ENOTSOCK 参数s为一文件描述词，非socket。
	EINTR 被信号所中断。
	EAGAIN 此操作会令进程阻断，但参数s的socket为不可阻断。
	ENOBUFS 系统的缓冲内存不足
	ENOMEM 核心内存不足
	EINVAL 传给系统调用的参数不正确。
 
	范例  参考connect()
 
　 

 
