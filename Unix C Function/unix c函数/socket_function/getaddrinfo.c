       #include <sys/types.h>
       #include <sys/socket.h>
       #include <netdb.h>

       int getaddrinfo(const char *node, const char *service,
                       const struct addrinfo *hints,
                       struct addrinfo **res);

       void freeaddrinfo(struct addrinfo *res);
     　　----getaddrinfo所有的存储空间都是动态获取的，包括addrinfo结构，ai_addr结构，ai_canonname字符串，这些空间都通过调用freeaddrinfo返还给系统。
     　　----res指向由getaddrinfo返回的第一个addrinfo结构  
     

       const char *gai_strerror(int errcode);

DESCRIPTION
       Given  node  and  service, which identify an Internet host
       and a service, getaddrinfo() returns one or more  addrinfo
       structures,  each  of  which  contains an Internet address
       that can be specified in a call to bind(2) or  connect(2).
       The getaddrinfo() function combines the functionality pro‐
       vided by the gethostbyname(3) and  getservbyname(3)  func‐
       tions into a single interface, but unlike the latter func‐
       tions, getaddrinfo() is reentrant(再进入的) and allows  programs  to
       eliminate(vt.消除，排除) IPv4-versus-IPv6 dependencies.

       The  addrinfo structure used by getaddrinfo() contains the
       following fields:

           struct addrinfo {
               int              ai_flags;
               int              ai_family;
               int              ai_socktype;
               int              ai_protocol;
               socklen_t        ai_addrlen;
               struct sockaddr *ai_addr;
               char            *ai_canonname;
               struct addrinfo *ai_next;
           };

The hints(暗示，线索) argument points to an  addrinfo  structure  that
       specifies criteria(n.标准，条件) for selecting the socket address struc‐
       tures returned in the list pointed to by res.  If hints is
       not  NULL it points to an addrinfo structure whose ai_fam‐
       ily, ai_socktype, and ai_protocol  specify  criteria  that
       limit  the  set  of  socket  addresses  returned by getad‐
       drinfo(), as follows:

       ai_family   This field specifies the desired address  fam‐
                   ily  for the returned addresses.  Valid values
                   for this field include AF_INET  and  AF_INET6.
                   The  value  AF_UNSPEC  indicates  that  getad‐
                   drinfo() should return  socket  addresses  for
                   any  address  family (either IPv4 or IPv6, for
                   example) that can be used with node  and  ser‐
                   vice.

       ai_socktype This  field  specifies  the  preferred  socket
                   type, for example SOCK_STREAM  or  SOCK_DGRAM.
                   Specifying  0  in  this  field  indicates that
                   socket addresses of any type can  be  returned
                   by getaddrinfo().

ai_protocol This  field  specifies  the  protocol  for the
                   returned socket addresses.   Specifying  0  in
                   this  field  indicates  that  socket addresses
                   with any protocol can be  returned  by  getad‐
                   drinfo().

       ai_flags    This   field   specifies  additional  options,
                   described below.  Multiple flags are specified
                   by bitwise OR-ing them together.

       All  the other fields in the structure pointed to by hints
       must contain either 0 or a null pointer, as appropriate.

       Specifying hints as NULL is equivalent to setting ai_sock‐
       type  and  ai_protocol  to  0; ai_family to AF_UNSPEC; and
       ai_flags to (AI_V4MAPPED | AI_ADDRCONFIG).  (POSIX  speci‐
       fies  different  defaults  for ai_flags; see NOTES.)  node
       specifies either a numerical network  address  (for  IPv4,
       numbers-and-dots  notation  as  supported by inet_aton(3);
       for  IPv6,  hexadecimal  string  format  as  supported  by
       inet_pton(3)),   or  a  network  hostname,  whose  network
       addresses are looked up and resolved.   If  hints.ai_flags
       contains  the  AI_NUMERICHOST  flag,  then  node must be a
       numerical network address.  The AI_NUMERICHOST  flag  sup‐
       presses  any  potentially  lengthy  network  host  address
       lookups.

If the AI_PASSIVE flag is specified in hints.ai_flags, and
       node  is  NULL, then the returned socket addresses will be
       suitable for bind(2)ing a socket that will accept(2)  con‐
       nections.   The  returned  socket address will contain the
       "wildcard  address"  (INADDR_ANY   for   IPv4   addresses,
       IN6ADDR_ANY_INIT  for IPv6 address).  The wildcard address
       is used by applications (typically servers) that intend to
       accept   connections   on   any  of  the  hosts's  network
       addresses.  If node is not NULL, then the AI_PASSIVE  flag
       is ignored.

       If  the AI_PASSIVE flag is not set in hints.ai_flags, then
       the returned socket addresses will  be  suitable  for  use
       with  connect(2),  sendto(2),  or  sendmsg(2).  If node is
       NULL, then the network address will be set to the loopback
       interface  address  (INADDR_LOOPBACK  for  IPv4 addresses,
       IN6ADDR_LOOPBACK_INIT for IPv6 address); this is  used  by
       applications that intend to communicate with peers running
       on the same host.

 service sets the port in each returned address  structure.
       If  this  argument is a service name (see services(5)), it
       is translated to  the  corresponding  port  number.   This
       argument  can also be specified as a decimal number, which
       is simply converted to binary.  If service is  NULL,  then
       the  port  number of the returned socket addresses will be
       left uninitialized.  If  AI_NUMERICSERV  is  specified  in
       hints.ai_flags  and service is not NULL, then service must
       point to a string containing a numeric port number.   This
       flag  is  used to inhibit the invocation of a name resolu‐
       tion service  in  cases  where  it  is  known  not  to  be
       required.

       Either node or service, but not both, may be NULL.

       The  getaddrinfo()  function  allocates  and initializes a
       linked list of addrinfo structures, one for  each  network
       address  that  matches  node  and  service, subject to any
       restrictions imposed by hints, and returns  a  pointer  to
       the  start  of  the  list in res.  The items in the linked
       list are linked by the ai_next field.




















