

       //#include <sys/types.h>          /* See NOTES */
       //#include <sys/socket.h>
       int bind(int sockfd, const struct sockaddr *addr,
                socklen_t addrlen);
                
           ----函数功能：将协议地址绑定到一个套接字；其中协议地址包含IP地址和端口号；  
           ----该函数为套接字建立一个本地地址.应用程序并不关心它们使用的本地地址，而是很愿意让协议软件来填写计算机的ip地址，并选择一个端口号。但是在某个熟知端口上操作的服务进程必须为系统指明端口。如果一个客户没有调用bind，操作系统会自动分配一个端口号
           	　　　sockfd:是要绑定的描述符
           	　　　addr:是一个指定套接字要绑定的本地地址的结构
           	　　　addrlen:是一个指定地址长度
           ----sockaddr是一个通用结构。当该结构中的地址族字段值为２，则意味着其余８位组中包含的是一个tcp/ip地址。每个协议族都规定了如何使用地址族字段中的８位组。对于tcp/ip地址，套接字地址称为sockaddr_in,它包括一个ip地址和一个协议端口号
           
           ----	当socket函数返回一个描述符时，只是存在于其协议族的空间中，并没有分配一个具体的协议地址（这里指IPv4/IPv6和端口号的组合），对于 TCP 协议，调用 bind 函数可以指定一个端口号，或指定一个 IP 地址，也可以两者都指定，还可以都不指定。若 TCP 客户端或服务器端不调用bind 函数绑定一个端口号，当调用connect 或 listen 函数时，内核会为相应的套接字选择一个临时端口号。一般 TCP 客户端使用内核为其选择一个临时的端口号，而服务器端通过调用bind 函数将端口号与相应的套接字绑定。进程可以把一个特定的 IP 地址捆绑到它的套接字上，但是这个 IP 地址必须属于其所在主机的网络接口之一。对于 TCP 客户端，这就为在套接字上发送的 IP 数据报指派了源 IP 地址。对于 TCP 服务器端，这就限定该套接字只接收那些目的地为这个 IP 地址的客户端连接。TCP 客户端一般不把 IP 地址捆绑到它的套接字上。当连接套接字时，内核将根据所用外出网络接口来选择源 IP 地址，而所用外出接口则取决于到达服务器端所需的路径。若 TCP 服务器端没有把 IP 地址捆绑到它的套接字上，内核就把客户端发送的 SYN 的目的 IP 地址作为服务器端的源 IP 地址。一般只有套接字端点能够与地址绑定，尽管有些协议允许多重绑定;
　
		   为了统一地址结构的表示方法，统一接口函数，使得不同的地址结构可以被bind()、connect()、recvfrom()、sendto()等函数调用。但一般的编程中并不直接对此数据结构进行操作，而使用另一个与之等价的数据结构sockaddr_in。

	       通常服务器在启动的时候都会绑定一个众所周知的协议地址，用于提供服务，客户就可以通过它来接连服务器；而客户端可以指定IP或端口也可以都不指定，未分配则系统自动分配。这就是为什么通常服务器端在listen之前会调用bind()，而客户端就不会调用，而是在connect()时由系统随机生成一个。
		   对于因特网域，如果指定ip地址为INADDR_ANY(<netinet/in.h>中定义)，套接字端点可以绑定到所有的系统网络接口上，这意味着可以接受这个系统所安装的任何一个网卡的数据包。
		   可以调用getsockname函数来发现绑定到套接字上的地址






bind（对socket定位）  
相关函数: socket，accept，connect，listen
 
#include<sys/types.h>
#include<sys/socket.h>
 
int bind(int sockfd,struct sockaddr * my_addr,int addrlen);

----bind用于将套接字与一个端口绑定。

DESCRIPTION
       When a socket is created with socket(2), it exists in
       a name space (address  family)  but  has  no  address
       assigned to it.  bind() assigns the address specified
       by addr  to  the  socket  referred  to  by  the  file
       descriptor  sockfd.   addrlen  specifies the size, in
       bytes, of the address structure pointed to  by  addr.
       Traditionally,  this operation is called “assigning a
       name to a socket”.

       It is normally necessary to assign  a  local  address
       using  bind() before a SOCK_STREAM socket may receive
       connections (see accept(2)).

       The rules used in name binding vary  between  address
       families.   Consult  the  manual entries in Section 7
       for detailed information.  For AF_INET see ip(7), for
       AF_INET6  see  ipv6(7),  for AF_UNIX see unix(7), for
       AF_APPLETALK see ddp(7), for AF_PACKET see packet(7),
       for   AF_X25   see  x25(7)  and  for  AF_NETLINK  see
       netlink(7).

       The actual structure passed  for  the  addr  argument
       will  depend  on  the  address  family.  The sockaddr
       structure is defined as something like:
           struct sockaddr {
               sa_family_t sa_family;
               char        sa_data[14];
           }

       The only purpose of this structure  is  to  cast  the
       structure  pointer  passed  in addr in order to avoid
       compiler warnings.  See EXAMPLE below.

RETURN VALUE
       On success,  zero  is  returned.   On  error,  -1  is
       returned, and errno is set appropriately.



 
 
 
----函数说明: bind()用来设置给参数sockfd的socket一个名称。此名称由参数my_addr指向一sockaddr结构，对于不同的socket domain定义了一个通用的数据结构
struct sockaddr
{
	//unsigned short int sa_family;
	sa_family_t sa_family;
	char sa_data[14];
};
sa_family 为调用socket（）时的domain参数，即AF_xxxx值。
sa_data 最多使用14个字符长度。
此sockaddr结构会因使用不同的socket domain而有不同结构定义，例如使用AF_INET domain，其socketaddr结构定义便为
struct socketaddr_in
{
	unsigned short int sin_family;
	uint16_t sin_port;
	struct in_addr sin_addr;
	unsigned char sin_zero[8];
};
struct in_addr
{
	uint32_t s_addr;
};
sin_family 即为sa_family
sin_port 为使用的port编号
sin_addr.s_addr 为IP 地址
sin_zero 未使用。
 
----addrlen为sockaddr的结构长度。
 
----返回值: 成功则返回0，失败返回-1，错误原因存于errno中。
 
错误代码  EBADF 参数sockfd 非合法socket处理代码。
EACCESS 权限不足
ENOTSOCK 参数sockfd为一文件描述词，非socket。
 
范例  参考listen()
 
　 
