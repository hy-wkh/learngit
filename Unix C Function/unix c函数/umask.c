/*umask（设置建立新文件时的权限遮罩）  
相关函数  creat，open

#include<sys/stat.h>
mode_t umask(mode_t mask);
----功能：（在进程创建一个新文件或新目录时）该函数为进程设置文件模式创建屏蔽字，并返回之前的值
----在文件模式创建屏蔽字中为１的位，在文件mode中的相应位一定被关闭

---参数mask表示一个新的屏蔽字，其类型为mode_t.
	该函数设置创建文件时使用的权限掩码。mode_t类型也是一个位向量，对应９个权限标致位。哪一位的屏蔽位为１，说明用户在创建文件时所指定的权限标致无效，新文件不具有该权限；为０则相反，是否具有该权限，取决于用户的权限字

---- umask()会将系统umask值设成参数mask&0777后的值，然后将先前的umask值返回。在使用open()建立新文件时，该参数mode并非真正建立文件的权限，而是(mode&~umask)的权限值。例如，在建立文件时指定文件权限为0666，通常umask值默认为022，则该文件的真正权限则为0666&～022＝0644，也就是rw-r--r--返回值此调用不会有错误值返回。返回值为原先系统的umask值。
----该函数在更改进程环境下的创建文件时使用的权限掩码并不影响父进程
*/

#include<stdio.h>
#include<sys/stat.h>
//#define RWRWRW (S_IRUSR | S_IWUSR)
#define RWRWRW (S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IWOTH | S_IROTH)

int main(){
	umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);//(只有所有者没有被设置，因此没有被屏蔽)
	if(creat("bar",RWRWRW)<0)perror("fail to creat2");
	return 0;
}
/*
hy@hy-K53BE:~/桌面$ ls -l bar
-rw------- 1 hy hy 0  1月  9 16:10 bar  
	(1.因为RWRWRW没有设置执行权限，所以都没有执行权限)
	(2.umask被设置的位表示新文件不该具有此权限)


*/

