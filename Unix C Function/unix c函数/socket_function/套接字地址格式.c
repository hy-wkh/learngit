	一个地址标识一个特定通信域的套接字端点，地址格式与这个特定的通信域相关。为使不同地址格式能够传入到套接字函数，地址会被强制转换成一个通用的地址结构sockaddr;
	在linux中，这种结构定义如下：
		struct sockaddr{
			sa_family_t sa_family;//address family;
			char 	  sa_data[14];//variable-length address;
		};
		
	因特网地址定义在<netinet/in.h>中。在ipv4因特网域(AF_INET)中，套接字地址用结构sockaddr_in表示：
		struct in_addr{
			in_addr_t s_addr;//ipv4 address;
		};
		struct sockaddr_in{
			sa_family_t sin_family;//address family;
			in_port_t sin_port;	//port number;
			struct in_addr sin_addr;	//ipv4 address
		};

		   struct servent {
               char  *s_name;       /* official service name:服务名 */
               char **s_aliases;    /* alias list */
               int    s_port;       /* port number：端口号 */
               char  *s_proto;      /* protocol to use：使用的具体协议*/
           }

           struct protoent {
               char  *p_name;       /* official protocol name */
               char **p_aliases;    /* alias list */
               int    p_proto;      /* protocol number */
           }
           
           
		   struct hostent {
               char  *h_name;            /* official name of host：主机名*/
               char **h_aliases;         /* alias list */
               int    h_addrtype;        /* host address type,The type of address always AF_INET or AF_INET6 at present.*/
               int    h_length;          /* length of address */
               char **h_addr_list;       /* list of addresses */
           }
           #define h_addr h_addr_list[0] /* for backward compatibility */

	协议族：PF_INET,PF_INET6,PF_UNIX(unix文件系统)
	地址族：AF_INET,AF_INET6...








