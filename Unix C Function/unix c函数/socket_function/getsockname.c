       #include <sys/socket.h>
       int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
	
DESCRIPTION
       getsockname() returns the current address to which the
       socket sockfd is bound, in the buffer  pointed  to  by
       addr.   The  addrlen argument should be initialized to
       indicate the amount of space (in bytes) pointed to  by
       addr.   On  return  it contains the actual size of the
       socket address.

       The returned address is truncated if the  buffer  pro‐
       vided  is too small; in this case, addrlen will return
       a value greater than was supplied to the call.

RETURN VALUE
       On  success,  zero  is  returned.   On  error,  -1  is
       returned, and errno is set appropriately.


