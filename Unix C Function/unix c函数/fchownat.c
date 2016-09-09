#include<unistd.h>
int fchownat(int fd,
			 const char *pathname,
			 uid_t owner,
			 gid_t group,
			 int flag);

----
	   fchownat()
       The  fchownat()  system call operates in exactly the same
       way as chown(),  except  for  the  differences  described
       here.

       If the pathname given in pathname is relative, then it is
       interpreted(v.解释，说明) relative to the directory referred to by  the
       file  descriptor  dirfd (rather than relative to the cur‐
       rent working directory of the calling process, as is done
       by chown() for a relative pathname).

       If  pathname  is  relative and dirfd is the special value
       AT_FDCWD, then pathname is interpreted  relative  to  the
       current  working  directory  of the calling process (like
       chown()).

       If pathname is absolute, then dirfd is ignored.

       The flags  argument  is  a  bit  mask  created  by  ORing
       together 0 or more of the following values;


