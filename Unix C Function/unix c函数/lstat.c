
#include<sys/stat.h>
int lstat(const char *pathname,struct stat *buf);
----pathname指定文件的路径
----buf表示存储stat结构的缓冲区地址。stat结构用于存储文件的状态信息
----返回：如果成功的取得符号链接的状态，lstat函数返回０，失败则返回-1
----功能：lstat函数不跟踪符号链接，因此可以取得符号链接文件本身的文件状态信息
----lstat() 与stat()作用完全相同，差别之处在于，当文件为符号链接时，lstat()会返回该link本身的状态












