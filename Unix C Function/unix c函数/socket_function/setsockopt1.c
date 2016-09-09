SYNOPSIS
       #include <sys/types.h>          /* See NOTES */
       #include <sys/socket.h>

       int getsockopt(int sockfd, int level, int optname,
                      void *optval, socklen_t *optlen);
       int setsockopt(int sockfd, int level, int optname,
                      const void *optval, socklen_t optlen);

DESCRIPTION
       getsockopt()  and setsockopt() manipulate(vt.操纵) options for the
       socket  referred  to(涉及，参考)  by  the  file  descriptor   sockfd.
       Options  may  exist at multiple protocol levels; they are
       always present at the uppermost(最高点，最主要的) socket level.

       When manipulating socket options, the level at which  the
       option  resides(vt.属于，居住) and the name of the option must be speci‐
       fied.  To manipulate options at the  sockets  API  level,
       level  is specified as SOL_SOCKET.  To manipulate options
       at any other level the protocol number of the appropriate
       protocol  controlling  the option is supplied.  For exam‐
       ple, to indicate that an option is to be  interpreted  by
       the  TCP  protocol,  level  should be set to the protocol
       number of TCP; see getprotoent(3).

       The arguments optval and optlen are used to access option
       values  for setsockopt().  For getsockopt() they identify
       a buffer in which the value for the  requested  option(s)
       are to be returned.  For getsockopt(), optlen is a value-
       result argument, initially containing  the  size  of  the
       buffer  pointed  to  by optval, and modified on return to
       indicate the actual size of the value  returned.   If  no
       option value is to be supplied or returned, optval may be
       NULL.
       Optname and any specified  options  are  passed  uninter‐
       preted to the appropriate protocol module for interpreta‐
       tion.  The include file <sys/socket.h>  contains  defini‐
       tions for socket level options, described below.  Options
       at other protocol levels vary in format and name; consult
       the appropriate entries in section 4 of the manual.

       Most  socket-level  options  utilize  an int argument for
       optval.  For setsockopt(), the argument should be nonzero
       to  enable  a boolean option, or zero if the option is to
       be disabled.

       For a description of the  available  socket  options  see
       socket(7) and the appropriate protocol man pages.

RETURN VALUE
       On  success, zero is returned.  On error, -1 is returned,
       and errno is set appropriately.


