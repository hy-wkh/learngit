#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
<1>
unsigned long int inet_addr(const char *cp);
 
----函数说明: inet_addr()用来将参数cp所指的网络地址点分十进制字符串转换成网络所使用的二进制数字。网络地址字符串是以数字和点组成的字符串，例如:“163.13.132.68”。
----返回值: 成功则返回对应的网络二进制的数字，失败返回-1。

<2>
int inet_aton(const char * cp,struct in_addr *inp);
 
----函数说明: inet_aton()用来将参数cp所指的网络地址字符串转换成网络使用的二进制的数字，然后存于参数inp所指的in_addr结构中。

struct in_addr{
	unsigned long int s_addr;
};
----返回值: 成功则返回非0值，失败则返回0。
 
<3>
char *inet_ntoa(struct in_addr in);
 
----函数说明: inet_ntoa()用来将参数in所指的网络二进制的数字转换成网络地址，然后将指向此网络地址字符串的指针返回。
----返回值: 成功则返回字符串指针，失败则返回NULL。
 
　>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> 
以下两个函数同时支持ipv4和ipv6:
<4>
       #include <arpa/inet.h>
       int inet_pton(int af, const char *src, void *dst);

       This function converts the character string  src  into  a
       network  address structure in the af address family, then
       copies the network address  structure  to  dst.   The  af
       argument must be either AF_INET or AF_INET6.

       The following address families are currently supported:
       AF_INET AF_INET6
	   例如：inet_pton(AF_INET,ip,&address.sin_addr);
	   
RETURN VALUE
       inet_pton()  returns  1  on  success (network address was
       successfully converted).  0 is returned if src  does  not
       contain  a  character string representing a valid network
       address in the specified address family.  If af does  not
       contain  a valid address family, -1 is returned and errno
       is set to EAFNOSUPPORT.
　 
<5>　 
      #include <arpa/inet.h>
       const char *inet_ntop(int af, const void *src,
                             char *dst, socklen_t size);

DESCRIPTION
       This function converts the network address structure  src
       in  the  af  address family into a character string.  The
       resulting string is copied to the buffer  pointed  to  by
       dst, which must be a non-null pointer.  The caller speci‐
       fies the number of bytes available in this buffer in  the
       argument size.

       inet_ntop()  extends the inet_ntoa(3) function to support
       multiple address families, inet_ntoa(3) is now considered
       to  be deprecated(不赞成的) in favor of inet_ntop().  		　　　The following　address families are currently supported:
      
      AF_INET
              src points to a struct in_addr  (in  network  byte
              order)  which  is  converted  to  an  IPv4 network
              address    in    the    dotted-decimal     format,
              "ddd.ddd.ddd.ddd".   The  buffer  dst  must  be at
              least INET_ADDRSTRLEN bytes long.

       AF_INET6
              src points to a struct in6_addr (in  network  byte
              order)  which  is converted to a representation of
              this address in the most appropriate IPv6  network
              address  format  for this address.  The buffer dst
              must be at least INET6_ADDRSTRLEN bytes long.

RETURN VALUE
       On success, inet_ntop() returns  a  non-null  pointer  to
       dst.   NULL is returned if there was an error, with errno
       set to indicate the error.


　 
　 
　 
　 
　 
　 
　 
　 
　 
　 　 
　 
