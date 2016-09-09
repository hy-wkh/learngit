/*
fputs（将一指定的字符串写入文件内）  
相关函数  fopen，fwrite，fscanf，fputc，put
#include<stdio.h>
int fputs(const char *s,FILE * stream);
----s指定要写入的字符串
----fputs()用来将参数s所指的字符串写入到参数stream所指的文件内。
----返回值: 若成功则返回写出的字符个数，失败则返回EOF并设置errno。
----函数执行完后，并没有将数据适时地写回文件，而是写入到文件缓冲区中，可使用fflush函数刷新该缓冲区，以确保数据写入文件
范例  请参考fgets（）。
*/
　 
