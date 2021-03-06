
       //#include <sys/types.h>          /* See NOTES */
       //#include <sys/socket.h>
       int socket(int domain, int type, int protocol);
       ----domain:The domain argument specifies a communication domain; 
       			　　ipv4 PFINET
				  ipv6 PFINET6
				  unix文件系统 PF_UNIX
		   type:指明要求的通信类型
		   		SOCK_DGRAM 数据报
		   	　　　　SOCK_STREAM 可靠数据流交付服务
		   	　　　　SOCK_RAW 网络接口的原始类型(允许有特权的程序访问底层协议或网络接口)
		   protocol:选择一个具体的协议(如果在协议族中只有一种能够提供某种type类型的协议，这时可把第三个参数设置为0)







socket（建立一个socket通信）  
相关函数  accept，bind，connect，listen
 
#include<sys/types.h>
#include<sys/socket.h>

----定义函数: int socket(int domain,int type,int protocol);
 
----函数说明: socket()用来建立一个新的socket，也就是向系统注册，通知系统建立一通信端口。
----参数domain 指定使用何种的地址类型，完整的定义在/usr/include/bits/socket.h 内，底下是常见的协议:
	（AF是地址族，PF是协议族）
	PF_UNIX/PF_LOCAL/AF_UNIX/AF_LOCAL UNIX 进程通信协议(AF_LOCAL用于unix域协议)
	PF_INET?AF_INET Ipv4网络协议
	PF_INET6/AF_INET6 Ipv6 网络协议
	PF_IPX/AF_IPX IPX-Novell协议
	PF_NETLINK/AF_NETLINK 核心用户接口装置
	PF_X25/AF_X25 ITU-T X.25/ISO-8208 协议
	PF_AX25/AF_AX25 业余无线AX.25协议
	PF_ATMPVC/AF_ATMPVC 存取原始ATM PVCs
	PF_APPLETALK/AF_APPLETALK appletalk（DDP）协议
	PF_PACKET/AF_PACKET 初级封包接口
 
----参数: type有下列几种数值:
	SOCK_STREAM 提供双向连续且可信赖的数据流，即TCP。支持
	OOB 机制，在所有数据传送前必须使用connect()来建立连线状态。
	SOCK_DGRAM 使用不连续不可信赖的数据包连接
	SOCK_SEQPACKET 提供连续可信赖的数据包连接
	SOCK_RAW 提供原始网络协议存取
	SOCK_RDM 提供可信赖的数据包连接
	SOCK_PACKET 提供和网络驱动程序直接通信。
	
----protocol用来指定socket所使用的传输协议编号，通常此参考不用管它，设为0即可。(因为一个协议族可能有多个协议提供同类型的通信，所以套接字有了第三个参数，用于选择一个具体的协议，如果在协议族中只存在一种能提供某种可能type通信类型（例如：ipv4协议族中只有tcp支持SOCK_STREAM服务），这时可以把第三个参数设置为０)
 
----返回值: 成功则返回socket处理代码，失败返回-1,错误原因存放在errno中。
 
----错误代码:
	EPROTONOSUPPORT 参数domain指定的类型不支持参数type或protocol指定的协议
	ENFILE 核心内存不足，无法建立新的socket结构
	EMFILE 进程文件表溢出，无法再建立新的socket
	EACCESS 权限不足，无法建立type或protocol指定的协议
	ENOBUFS/ENOMEM 内存不足
	EINVAL 参数domain/type/protocol不合法
 

