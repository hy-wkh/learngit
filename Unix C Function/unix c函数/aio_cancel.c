/*p217
#include<aio.h>
int aio_cancel(int fildes,struct aioch *aiocbp);
----aiocbp指向要取消请求的控制块（aiocbp为NULL,则函数会取消filedes中所有挂起的请求）
----功能：函数会取消文件描述符fildes上的一个或多个异步I/O请求
*/


