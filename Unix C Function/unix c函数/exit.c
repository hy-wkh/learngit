exit（正常结束进程）  
相关函数  _exit，atexit，on_exit
#include<stdlib.h>
void exit(int status);
 
----函数说明  exit()用来正常终结目前进程的执行并且进入内核做一些清理工作，并把参数status返回给父进程，而进程所有的缓冲区数据会自动写回并关闭未关闭的文件。
----进程的退出状态是一个８位的无符号整数，其取值是０～255
----exit(0)应该和return 0 一样,未返回任何信息，表示正常结束
返回值  
 
范例  参考wait（）
 
