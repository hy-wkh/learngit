#include<unistd.h>
ssize_t pread(int fd,void *buf,size_t count,off_t offset);

ssize_t pwrite(int fd,const void *buf,size_t count,off_t offset);

       pread()  reads  up to count bytes from file descriptor fd
       at offset offset (from the start of the  file)  into  the
       buffer starting at buf.  The file offset is not changed.

       pwrite()  writes up to count bytes from the buffer start‐
       ing at buf to the file descriptor fd  at  offset  offset.
       The file offset is not changed.

       The file referenced by fd must be capable of seeking.
----up to:一直到







