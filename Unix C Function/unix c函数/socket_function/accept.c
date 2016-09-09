
       //#include <sys/socket.h>
       int accept(int socket, struct sockaddr *restrict address,
              socklen_t *restrict address_len);
       ----函数功能：从已完成连接队列队头返回下一个已完成连接；若已完成连接队列为空，则进程进入睡眠；  
       ----accept 函数由 TCP 服务器调用，用于从已完成连接队列队头返回下一个已完成连接。如果已完成连接队列为空，那么进程被投入睡眠。该函数的返回值是一个新的套接字描述符，返回值是表示已连接的套接字描述符，而第一个参数是服务器监听套接字描述符。*****一个服务器通常仅仅创建一个监听套接字*****，它在该服务器的生命周期内一直存在。内核为每个由服务器进程接受的客户连接创建一个已连接套接字(表示 TCP 三次握手已完成)，当服务器完成对某个给定客户的服务时，相应的已连接套接字就会被关闭。
       
       -----参数 address 和 address_len 用来返回已连接的对端（客户端）的协议地址；address_len是值-结果参数：调用前，我们将由 *addrlen所指的整数值置为由cliaddr所指的套接口地址结构长度，返回时，此整数值即为由内核存在此套接口地址结构内的准确字节数。
       ----如果函数accept执行成功，"则返回值是由内核自动生成的一个全新描述字，代表与客户的TCP连接。当我们讨论accept函数时，常把它的第一个参数称为监听套接字(由函数socket生成的描述符，用作函数bind和listen的第一个参数)，把它的返回值称为已连接的套接字描述符"。把这两个套接字描述符区分开很重要，一个给定的服务器常常是只生成一个监听套接自而且一直存在，直到该服务器关闭。内核为每个被接受的客户连接创建了一个已连接的套接字（也就是内核已经为它完成tcp的三路握手过程）。当服务器完成某客户的服务时，关闭已连结的套接字
       
       
	   ----该函数返回套接字描述符，该描述符连接到调用connect函数的客户端；这个新的套接字描述符和原始的套接字描述符sockfd具有相同的套接字类型和地址族，:"而传给accept函数的套接字描述符sockfd没有关联到这个链接，而是继续保持可用状态并接受其他连接请求"；  
 	   ----若不关心客户端协议地址，可将address和address_len参数设置为NULL，否则，在调用accept之前，应将参数address设为足够大的缓冲区来存放地址，并且将address_len设为指向代表这个缓冲区大小的整数指针；  
 	   ----accept函数返回时，会在缓冲区填充客户端的地址并更新address_len所指向的整数为该地址的实际大小；若没有连接请求等待处理，accept会阻塞直到一个请求到来；  












accept（接受socket连线）  
相关函数 socket，bind，listen，connect
 
#include<sys/types.h>
#include<sys/socket.h>
int accept(int s,struct sockaddr * addr,int * addrlen);
 
----函数说明: accept()用来接受参数s的socket连线。参数s的socket必需先经bind()、listen()函数处理过，当有连线进来时accept()会返回一个新的socket处理代码，往后的数据传送与读取就是经由新的socket处理，而原来参数s的socket能继续使用accept()来接受新的连线要求。连线成功时，参数addr所指的结构会被系统填入远程主机的地址数据，参数addrlen为scokaddr的结构长度。关于结构sockaddr的定义请参考bind()。
 
----返回值: 成功则返回新的socket处理代码，失败返回-1，错误原因存于errno中。
 
错误代码:  
	EBADF 参数s 非合法socket处理代码。
	EFAULT 参数addr指针指向无法存取的内存空间。
	ENOTSOCK 参数s为一文件描述词，非socket。
	EOPNOTSUPP 指定的socket并非SOCK_STREAM。
	EPERM 防火墙拒绝此连线。
	ENOBUFS 系统的缓冲内存不足。
	ENOMEM 核心内存不足。
 
范例 参考listen()。
 
　 
