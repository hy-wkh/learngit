/*
sigemptyset（初始化信号集）  
#include<signal.h> 
int sigemptyset(sigset_t *set); 
----segset_t是一个位向量，set是一个信号集数据。
----sigemptyset()用来将参数set信号集清空（即每一位设置为０）。 
----返回值: 执行成功则返回0，如果有错误则返回-1。 
----错误代码: EFAULT 参数set指针地址无法存取
*/
