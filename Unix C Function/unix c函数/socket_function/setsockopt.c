setsockopt（设置socket状态）  
相关函数  getsockopt
 
#include<sys/types.h>
#include<sys/socket.h>
int setsockopt(int sockfd,
			   int level,
			   int optname,
			   const void *optval,
			   socklen_t optlen);

----函数说明: setsockopt()用来设置参数sockfd所指定的socket状态。
----level标识了选项应用的协议如果是通用的套接字层次选项，则level设置成SOL_SOCKET，否则设置成控制这个选项的协议编号。
	optval代表欲设置的值
	optlen则为optval的长度。
	optname代表欲设置的选项，有下列几种数值:
		SO_DEBUG 打开或关闭排错模式
		SO_REUSEADDR 允许在bind（）过程中本地地址可重复使用
		SO_TYPE 返回socket形态。
		SO_ERROR 返回socket已发生的错误原因
		SO_DONTROUTE 送出的数据包不要利用路由设备来传输。
		SO_BROADCAST 使用广播方式传送
		SO_SNDBUF 设置送出的暂存区大小
		SO_RCVBUF 设置接收的暂存区大小
		SO_KEEPALIVE 定期确定连线是否已终止。
		SO_OOBINLINE 当接收到OOB 数据时会马上送至标准输入设备
		SO_LINGER 确保数据安全且可靠的传送出去。
 

----返回值: 成功则返回0，若有错误则返回-1，错误原因存于errno。
 
附加说明:  
EBADF 参数s并非合法的socket处理代码
ENOTSOCK 参数s为一文件描述词，非socket
ENOPROTOOPT 参数optname指定的选项不正确。
EFAULT 参数optval指针指向无法存取的内存空间。
 
范例  参考getsockopt()。
 
