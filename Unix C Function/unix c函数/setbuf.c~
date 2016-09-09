setbuf（设置文件流的缓冲区）  
相关函数  setbuffer，setlinebuf，setvbuf
#include<stdio.h>
void setbuf(FILE * stream,char * buf);
 
----函数说明: 在打开文件流后，读取内容之前，调用setbuf()可以用来设置文件流的缓冲区。参数stream为指定的文件流，参数buf指向"自定的缓冲区起始地址"。如果参数buf为NULL指针，则为无缓冲IO。Setbuf()相当于调用:setvbuf(stream,buf,buf?_IOFBF:_IONBF,BUFSIZ) 
 
 
 
 
NAME
       setbuf, setbuffer, setlinebuf, setvbuf - stream buffering
       operations

SYNOPSIS
       #include <stdio.h>

       void setbuf(FILE *stream, char *buf);

       void setbuffer(FILE *stream, char *buf, size_t size);

       void setlinebuf(FILE *stream);

       int setvbuf(FILE *stream, char *buf, int mode, size_t size);

   Feature  Test  Macro  Requirements  for   glibc   (see   fea‐
   ture_test_macros(7)):

       setbuffer(), setlinebuf(): _BSD_SOURCE

DESCRIPTION
       The  three  types  of buffering available are "unbuffered,block buffered, and line buffered".  When an output stream
       is  unbuffered,  information  appears  on the destination
       file or terminal as soon as written;  when  it  is  block
       buffered  many  characters  are saved up and written as a
       block; when it is line buffered(相当于getline()) characters are  saved  up
       until  a  newline  is  output  or  input is read from any
       stream attached to a terminal device  (typically  stdin).
       The function fflush(3) may be used to force the block out
       early.  (See fclose(3).)  
       
       Normally all  files  are  block
       buffered.  When the first I/O operation occurs on a file,
       malloc(3) is called, and a  buffer  is  obtained.   If  a
       stream refers to a terminal (as stdout normally does), it
       is line buffered.  The standard error  stream  stderr  is
       always unbuffered by default.

       The  setvbuf() function may be used on any open stream to
       change its buffer.  The mode argument must be one of  the
       following three macros:

              _IONBF unbuffered

              _IOLBF line buffered
              _IOFBF fully buffered

       Except  for  unbuffered  files,  the  buf argument should
       point to a buffer at least size bytes long;  this  buffer
       will be used instead of the current buffer.  If the argu‐
       ment buf is NULL, only the mode is affected; a new buffer
       will  be  allocated  on the next read or write operation.
       The setvbuf() function may be used only after  opening  a
       stream  and  before  any  other operations have been per‐
       formed on it.

       The other three calls are, in effect(实际上，生效), simply aliases  for
       calls  to  setvbuf().   The  setbuf() function is exactly
       equivalent to the call

           setvbuf(stream, buf, buf ? _IOFBF : _IONBF, BUFSIZ);

       The setbuffer() function is the  same,  except  that  the
       size of the buffer is up to the caller, rather than being
       determined by the default BUFSIZ.  The setlinebuf() func‐
       tion is exactly equivalent to the call:

           setvbuf(stream, NULL, _IOLBF, 0);

RETURN VALUE
       The  function setvbuf() returns 0 on success.  It returns
       nonzero on failure (mode is invalid or the request cannot
       be honored).  It may set errno on failure.

       The other functions do not return a value.

ATTRIBUTES
   Multithreading (see pthreads(7))
       The  setbuf(),  setbuffer(),  setlinebuf(), and setvbuf()
       functions are thread-safe.




