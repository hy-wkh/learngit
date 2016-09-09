 	   #include <sys/time.h>
       #include <sys/resource.h>
       int getrusage(int who, struct rusage *usage);

       getrusage()  returns  resource  usage  measures  for who,
       which can be one of the following:

       RUSAGE_SELF
              Return resource usage statistics for  the  calling
              process, which is the sum of resources used by all
              threads in the process.

       RUSAGE_CHILDREN
              Return resource usage statistics for all  children
              of  the  calling  process that have terminated and
              been waited for.  These  statistics  will  include
              the  resources  used by grandchildren, and further
              removed descendants, if  all  of  the  intervening
              descendants waited on their terminated children.

       RUSAGE_THREAD (since Linux 2.6.26)
              Return  resource  usage statistics for the calling
              thread.  The _GNU_SOURCE feature test  macro  must
              be  defined  (before including any header file) in
              order to obtain the definition  of  this  constant
              from <sys/resource.h>.

       The resource usages are returned in the structure pointed
       to by usage









