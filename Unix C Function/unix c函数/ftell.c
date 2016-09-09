ftell（取得文件流的读取位置）  
相关函数  fseek，rewind，fgetpos，fsetpos
#include<stdio.h>
long ftell(FILE * stream);
 
----函数说明: 函数返回参数stream指定的流文件指针的当前读写位置。

----返回值： 当调用成功时则返回目前的读写位置，若有错误则返回-1，errno会存放错误代码。
 
----错误代码: EBADF 参数stream无效或可移动读写位置的文件流。
 
范例  参考fseek()。
 
　 

