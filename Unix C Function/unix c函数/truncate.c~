truncate（改变文件大小）  
相关函数  open，ftruncate
 
#include<unistd.h>
int truncate(const char * path,off_t length);
 
----函数说明: truncate()会将参数path 指定的文件大小改为参数length 指定的大小。如果原来的文件大小比参数length大，则超过的部分会被删去。如果原来的文件大小比length小，则以前文件末端和新的文件末端之间的数据将读作０
 
----返回值: 执行成功则返回0，失败返回-1，错误原因存于errno。

int ftruncate(int fd,off_t length);
----
       With ftruncate(), the file must be open for writing; with
       truncate(), the file must be writable.


错误代码 
EACCESS 参数path所指定的文件无法存取。
EROFS 欲写入的文件存在于只读文件系统内
EFAULT 参数path指针超出可存取内存空间
EINVAL 参数path包含不合法字符
ENAMETOOLONG 参数path太长
ENOTDIR 参数path路径并非一目录
EISDIR 参数path 指向一目录
ETXTBUSY 参数path所指的文件为共享程序，而且正被执行中
ELOOP 参数path’有过多符号连接问题
EIO I/O 存取错误。
 
