
#include<netdb.h>
struct hostent *gethostbyname(const char *hostname);

----该函数用一个主机域名作为参数，并返回指向该主机信息的结构指针。如果调用成功它就返回一个指向hostent结构的指针，该结构中含有所查找主机的所有ipv4地址。(这个函数局限是只能返回ipv4地址(?????),getaddrinfo能同时处理ipv4和ipv6地址)
----该函数当发生错误时，它不设置errno变量，而是设置h_errno
 		  struct hostent{
               char  *h_name;            /* official name of host */
               char **h_aliases;         /* alias list */
               int    h_addrtype;        /* host address type */
               int    h_length;          /* length of address */
               char **h_addr_list;       /* list of addresses */
           }
           #define h_addr h_addr_list[0] /* for backward compatibility */

	   The members of the hostent structure are:

       h_name The official name of the host.

       h_aliases
              An array of alternative names for the host, termi‐
              nated by a null pointer.

       h_addrtype
              The type of address; always AF_INET or AF_INET6 at
              present.

       h_length
              The length of the address in bytes.

       h_addr_list
              An array of pointers to network addresses for  the
              host (in network byte order), terminated by a null
              pointer.

       h_addr The first address in h_addr_list for backward com‐
              patibility.
              
              
       The gethostbyname() function returns a structure of  type
       hostent  for  the given host name.  Here name is either a
       hostname, or an IPv4 address in standard dot notation(符号) (as
       for  inet_addr(3)), or an IPv6 address in colon(冒号) (and pos‐
       sibly dot) notation.  (See RFC 1884 for  the  description
       of  IPv6 addresses.)  If name is an IPv4 or IPv6 address,
       no lookup is performed and gethostbyname() simply  copies
       name into the h_name field and its struct in_addr equiva‐
       lent into the h_addr_list[0] field of the  returned  hos‐
       tent  structure.   If  name  doesn't end in a dot and the
       environment variable HOSTALIASES is set, the  alias  file
       pointed to by HOSTALIASES will first be searched for name
       (see hostname(7)  for  the  file  format).   The  current
       domain and its parents are searched unless name ends in a
       dot.


RETURN VALUE
       The  gethostbyname() and gethostbyaddr() functions return
       the hostent structure or  a  null  pointer  if  an  error
       occurs.   On  error,  the h_errno variable holds an error
       number.  When non-NULL, the return  value  may  point  at
       static data, see the notes below.



