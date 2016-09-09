#include<sys/sem.h>
int semctl(int semid,int semnum,int cmd,...);
----信号量集中的每个元素在使用之前，都应该用该函数进行初始化。该函数为信号量集semid的semnum个元素提供了控制操作，参数cmd提供了操作类型，第四个参数arg是可选的，这取决于cmd
----成功返回一个非负值，否则返回-1并设置errno
----


