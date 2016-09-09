#include<netdb.h>
struct protoent *getprotobyname(const char *name);

The getprotobyname() function returns a  protoent  struc‐
       ture  for  the  entry  from the database that matches the
       protocol name name.  A connection is opened to the  data‐
       base if necessary.

The  protoent  structure  is defined in <netdb.h> as follows:

           struct protoent {
               char  *p_name;       /* official protocol name */
               char **p_aliases;    /* alias list */
               int    p_proto;      /* protocol number */
           }

       The members of the protoent structure are:

       p_name The official name of the protocol.

       p_aliases
              A NULL-terminated list of  alternative  names  for
              the protocol.

       p_proto
              The protocol number.

RETURN VALUE
       The getprotoent(), getprotobyname() and getprotobynumber() functions return
       a  pointer  to a statically allocated protoent structure, or a null pointer
       if an error occurs or the end of the file is reached.











