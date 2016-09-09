#include<unistd.h>
int lchown(const char *pathname,uid_t owner,gid_t group);

----在符号连接的情况下，lchown和fchownat（设置了AT_SYMLINK_NOFOLLOW）更改符号连接本身的所有者，而不是该符号链接所指向的文件的所有者
----成功返回０，否则返回-1        

lchown() is like chown(), but does not dereference sym‐
         bolic links.





