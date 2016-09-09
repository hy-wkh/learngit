#include<sys/stat.h>
int fchmodat(int fd,
			 const char *pathname,
			 mode_t mode,
			 int flag);
----该函数计算相对于打开目录（由fd指向）的pathname，

----
   fchmodat()
       The  fchmodat()  system call operates in exactly the same
       way as chmod(),  except  for  the  differences  described
       here.

       If the pathname given in pathname is relative, then it is
       interpreted relative to the directory referred to by  the
       file  descriptor  dirfd (rather than relative to the cur‐
       rent working directory of the calling process, as is done
       by chmod() for a relative pathname).

       If  pathname  is  relative and dirfd is the special value
       AT_FDCWD, then pathname is interpreted  relative  to  the
       current  working  directory  of the calling process (like
       chmod()).

       If pathname is absolute, then dirfd is ignored.
	







