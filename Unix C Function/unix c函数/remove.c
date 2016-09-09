 
remove（删除文件）  
相关函数  link，rename，unlink
 
#include<stdio.h>
int remove(const char * pathname);
 
----函数说明: 该函数解除对一个文件或目录的链接。对于文件，该函数的功能与unlink相同，对于目录，该函数的功能与rmdir相同
----返回值: 成功则返回0，失败则返回-1，错误原因存于errno。
 
错误代码
EROFS 欲写入的文件存在于只读文件系统内
EFAULT 参数pathname指针超出可存取内存空间
ENAMETOOLONG 参数pathname太长
ENOMEM 核心内存不足
ELOOP 参数pathname有过多符号连接问题
EIO I/O 存取错误。
 
　 

