#include<sys/stat.h>
int fstatat(int fd,
			const char *restrict pathname,
		    struct stat *restrict buf,
			int flag);
----该函数为一个相对于当前打开目录的路径名返回文件统计信息
----成功返回０，否则返回-1









