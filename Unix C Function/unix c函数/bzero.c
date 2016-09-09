bzero（将一段内存内容全清为零）  
相关函数  memset，swab
 
#include<string.h>
void bzero(void *s,int n)；
 
----函数说明: bzero()会将参数s所指的内存区域前n个字节，全部设为零值。相当于调用memset((void*)s,0,size_tn);
 
返回值: 无
 
附加说明  建议使用memset取代
 
范例  参考memset()。
 
　 
