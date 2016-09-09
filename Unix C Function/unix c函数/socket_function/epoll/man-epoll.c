NAME
       epoll - I/O event notification facility

SYNOPSIS
       #include <sys/epoll.h>

DESCRIPTION
       The  epoll  API performs a similar task to poll(2): moni‐
       toring multiple file descriptors to see if I/O is  possi‐
       ble  on any of them.  The epoll API can be used either as
       an edge-triggered  or  a  level-triggered  interface  and
       scales well to large numbers of watched file descriptors.
       The following system calls are  provided  to  create  and
       manage an epoll instance:

       *  epoll_create(2)  creates an epoll instance and returns
          a file descriptor referring to  that  instance.   (The
          more recent epoll_create1(2) extends the functionality
          of epoll_create(2).)

       *  Interest in particular file descriptors is then regis‐
          tered  via  epoll_ctl(2).  The set of file descriptors
          currently registered on an epoll instance is sometimes
          called an epoll set.
   	   *  epoll_wait(2) waits for I/O events, blocking the call‐
          ing thread if no events are currently available.

   Level-triggered and edge-triggered
       The epoll event distribution interface is able to  behave
       both  as edge-triggered (ET) and as level-triggered (LT).
       The  difference  between  the  two  mechanisms   can   be
       described  as  follows.   Suppose that this scenario hap‐
       pens:

       1. The file descriptor that represents the read side of a
          pipe (rfd) is registered on the epoll instance.

       2. A pipe writer writes 2 kB of data on the write side of
          the pipe.

       3. A call to epoll_wait(2) is done that will  return  rfd
          as a ready file descriptor.

       4. The pipe reader reads 1 kB of data from rfd.

       5. A call to epoll_wait(2) is done.
























