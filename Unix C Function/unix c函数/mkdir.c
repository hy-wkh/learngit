#include<sys/stat.h>
int mkdir(const char *pathname,mode_t mode);
int mkdirat(int fd,const char *parhname,mode_t mode);
----创建一个新的空目录。所指定的文件访问权限mode由进程的文件








