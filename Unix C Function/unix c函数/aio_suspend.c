/*
#include<aio.h>
int aio_suspend(const struct aiocb *const list[],
				int nent,
				const struct timespec *timeout);
----第一个参数指向struct aiocb结构的指针数组
	nent为这些结构的数目
	第三个参数为超时规则
----如果超时规则不为NULL,那么aio_suspend会在一段特定的时间之后返回。否则，它至少要在完成了一个I/O操作而且aio_error不再返回EINPROGRESS的时候才会返回。如果某个参数为NULL，该参数就会被忽视
----返回：成功返回０，否则返回－1并设置errno.
*/











