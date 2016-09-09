/*
#include<aio.h>
int aio_read(struct aiocb *aiocbp);
----功能：允许进程对一个打开的文件描述符上的读操作请求进行排队。
----aiocbp是一个指向异步I/O控制块的指针
----返回：如果请求成功放入队列就返回０，否则返回-1并设置errno
*/

/*
#include<aio.h>
int aio_write(struct aiocb *aiocbp);
----功能：允许进程对一个打开的文件描述符上的写操作请求进行排队。
----返回：如果请求成功放入队列就返回０，否则返回-1并设置errno
*/

/*
#include<aio.h>
ssize_t aio_return(struct aiocb *aiocbp);
----在异步I/O操作执行完毕之后返回它的状态：
	操作成功，返回值就是读入或写出的字节数
	异步I/O还未完成，返回的结果是未定义的
	一旦调用了aio_return,就不能为同一个struct aiocb调用aio_return或aio_error了，直到这个缓冲区开始了另一个异步操作为止
*/


/*
#include<aio.h>
int aio_error(const struct aiocb *aiocbp);
----用来返回错误状态:
	I/O操作成功地完成时，aio_error返回０
	I/O操作还在进行，返回EINPROGRESS
	失败返回与失败相关的错误代码
*/












