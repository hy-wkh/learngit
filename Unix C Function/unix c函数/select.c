/*
#include<sys/select.h>
int select(int n,fd_set *readfds,fd_set *writefds,fd_set *exceptfds,struct timeval *timeout);
----参数n为所要监控文件描述符集的最大长度加1
----参数readfds为指定的读操作监控集
----writefds为指定的写操作监控集
----exceptfds为忽略监控的文件描述符集
----timeout为函数的超时限制。当设置为NULL,则说明还是一直等待直到有一个文件描述符的状态改变。
----返回：执行成功返回监控集中有操作请求的文件描述符的个数，失败返回-1，并设置全局错误变量errno.
----功能：函数用于等待参数readfds,writefds集中的文件描述符的状态改变，并记录状态改变的个数。

----函数中使用的fd_set为一个位图类型的数据集，该集合中每一个元素为一个bit位，该bit位只有两种取值１或０，系统中为该数据类型提供了４个宏（FD_CLR,FD_ISSET,FD_SET,FD_ZERO）做相应的操作。

----多路I/O转接
*/









