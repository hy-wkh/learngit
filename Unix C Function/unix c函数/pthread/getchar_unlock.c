SYNOPSIS
       #include <stdio.h>

       int getc_unlocked(FILE *stream);
       int getchar_unlocked(void);
       int putc_unlocked(int c, FILE *stream);
       int putchar_unlocked(int c);
----这四个函数一定要被flockfile() (or ftrylockfile()) and funlockfile()的调用包围，否则尽量不要调用这４个函数。
----一旦对FILE对象加锁，就可以在释放锁之前对这些函数进行多次调用
DESCRIPTION
       Versions of the  functions  getc(),  getchar(),  putc(),  and  putchar()  respectively  named getc_unlocked(),  getchar_unlocked(),  putc_unlocked(),  and putchar_unlocked() shall be provided which are functionally equivalent to the original versions,  with  the  exception  that they are not required to be implemented in a thread-safe manner. They may only safely be used
 within a scope protected by flockfile() (or ftrylockfile()) and funlockfile().These  functions may safely be used in a multi-threaded program if and only if they are called while the invoking thread owns the ( FILE *) object, as is the case after  a  successful  call  to  the flockfile() or ftrylockfile() functions.














