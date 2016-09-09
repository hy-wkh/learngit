

#include<netdb.h>
struct hostent *gethostbyaddr(const char *addr,socklen_t len,int family);

----该函数由一个主机地址作为参数，返回指向该主机信息的结构指针，与gethostbyname正好相反
----addr指向包含主机地址的字节序列的指针
	len是给出地址长度的整数
	family是指明地址类型的一个整数	
	
The gethostbyaddr() function returns a structure of  type
       hostent for the given host address addr of length len and
       address type family.  Valid address types are  AF_INET  and
       AF_INET6.   The  host  address argument is a pointer to a
       struct of a type depending on the address type, for exam‐
       ple  a  struct in_addr * (probably obtained via(经过) a call to
       inet_addr(3)) for address type AF_INET.

RETURN VALUE
       The  gethostbyname() and gethostbyaddr() functions return
       the hostent structure or  a  null  pointer  if  an  error
       occurs.   On  error,  the h_errno variable holds an error
       number.  When non-NULL, the return  value  may  point  at
       static data, see the notes below.

