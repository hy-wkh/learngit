/*
运行时限制可调用下面这三个函数之一获得：
#include<unistd.h>
long sysconf(int name);
long pathconf(const char *pathname,int name);
long fpathconf(int fd,int name);
*/

http://www.kernel.org/doc/man-pages/.
sysconf (get configuration information at run time)
#include <unistd.h>
long sysconf(int name);
----使用 sysconf() 函数确定可配置的系统变量的值。
----sysconf() 返回选项 (变量) 的当前值，这个值可配置的但也是受系统限制的。在成功完成的情况下，sysconf() 返回变量的当前值。该值受到的限制将少于编译时 <limits.h>， <unistd.h> 或 <time.h> 中可用的对应值。大多数这些变量的值在调用进程的生存时间内不变。

如果出错，那么函数返回 -1 ，并适当地设置 errno 。当没有错误发生时， -1 也是一个合法的返回值。因此，程序要检查错误，应该在调用 sysconf() 之前将 errno 设置为 0 ，然后，如果返回 -1，则检验到错误。

参数 name 指定我们感兴趣的运行时限制的名字，它必须是以值中之一(除非另有说明，否则返回值都是整数)：

    引用
    _SC_2_C_BIND  :  一个布尔值，指出是否支持 POSIX C 语言绑定。返回值是 _POSIX2_C_BIND 。

    _SC_2_C_DEV  :  一个布尔值，指出是否支持 POSIX C 语言开发使用工具选项。返回值是 _POSIX2_C_DEV 。

    _SC_2_C_VERSION :  它指出支持哪一个 ISO POSIX.2 标准 (命令) 的版本。返回值是 _POSIX2_C_VERSION 。

    _SC_2_CHAR_TERM :  一个布尔值，指出是否至少支持一个终端。返回值是 _POSIX2_CHAR_TERM 。

    _SC_2_FORT_DEV  :  一个布尔值，指出是否支持 FORTRAN 开发使用工具选项。返回值是 POSIX2_FORT_DEV 。



... .... 待补充 ... ...

使用 sysconf() 函数时，必须注意：

1、CLK_TCK 的值是可变的，因此，不应该假设它是一个编译时间常量。

2、调用 setrlimit 会使 OPEN_MAX 的值发生改变。

3、 通过将 sysconf (_SC_PHYS_PAGES) 和 sysconf (_SC_PAGESIZE) 相乘，来确定物理内存的总量 (以字节为单位) 可以返回一个值，该值超出 32 位进程中 long 或 unsigned long 可表示的最大值。同样适用于通过将 sysconf (_SC_PAGESIZE) 和 sysconf (_SC_AVPHYS_PAGES) 想乘，来确定未使用的物理内存的总量 (以字节为单位)。这个问题有两个工作区。第 1 个工作区将程序作为 64 位的进程进行编译 (从而使 long 足够大到可以容纳乘法运算的结果) ，但是，这样做的缺点是得到的程序只能在 64 位的内核中运行。第 2 个工作区是用来将得到的乘法运算结果存储在一个 64 位的量中，如 longlong_t  (Solaris OS 类型) 或 long long (linux)。它的有点是可以在 32 位和 64 位的内核中正确工作。
相关资料：

    linux｜Linux与网卡相关的几个命名
    linux｜Android Binder设计与实现 – 设计篇
    linux｜Linux Shell之常用快捷键
    linux｜sysconf()函数应用举例:查看CPU及内存信息
    linux｜redhat as 5配置本地yum源
    linux｜S3C2440 ---UART的使用浅解
    linux｜perl 输入到某文件

sysconf()函数应用举例:查看CPU及内存信息来源网络

#include <stdio.h>
#include <unistd.h>

#define ONE_MB (1024 * 1024)

int main (void)
{
    long num_procs;
    long page_size;
    long num_pages;
    long free_pages;
    long long  mem;
    long long  free_mem;

    num_procs = sysconf (_SC_NPROCESSORS_CONF);
    printf ("CPU 个数为: %ld 个\n", num_procs);

    page_size = sysconf (_SC_PAGESIZE);
    printf ("系统页面的大小为: %ld K\n", page_size / 1024 );

    num_pages = sysconf (_SC_PHYS_PAGES);
    printf ("系统中物理页数个数: %ld 个\n", num_pages);

    free_pages = sysconf (_SC_AVPHYS_PAGES);
    printf ("系统中可用的页面个数为: %ld 个\n", free_pages);

    mem = (long long) ((long long)num_pages * (long long)page_size);
    mem /= ONE_MB;

    free_mem = (long long)free_pages * (long long)page_size;
    free_mem /= ONE_MB;

    printf ("总共有 %lld MB 的物理内存, 空闲的物理内存有: %lld MB\n", mem, free_mem);
    return (0);
}

===================================================================

了解系统的线程资源限制是使得应用程序恰当地管理它们的关键。前面已经讨论了利用系统资源的示例。当设置线程的栈大小时，最小值为PTHREAD_MIN_STACK。栈大小不应当低于由pthread_attr_getstacksize( )返回的默认栈大小的最小值。每个进程的最大线程数决定了能够为每个进程创建的worker线程的上限。函数sysconf( )用于返回可配置系统限制或选项的当前值。系统中定义了同线程、进程和信号量相关的多个变量和常量。在表6-8中，列出了部分变量和常量。

变    量 	名字值(Name Value)	描    述

_SC_THREADS 	_POSIX_THREADS 		支持线程

_SC_THREAD_ATTR_STACKADDR 	_POSIX_THREAD_ATTR_STACKADDR 	支持线程栈地址属性

_SC_THREAD_ATTR_STACKSIZE 	_POSIX_THREAD_ATTR_STACKSIZE 	支持线程栈大小属性

_SC_THREAD_STACK_MIN 		PTHREAD_STACK_MIN 		线程栈存储区的最小大小，以字节为单位

_SC_THREAD_THREADS_MAX 		PTHREAD_THREADS_MAX 		每个进程的最大线程数

_SC_THREAD_KEYS_MAX 		PTHREAD_KEYS_MAX 		每个进程关键字的最大数目

_SC_THREAD_PRIO_INHERIT 	_POSIX_THREAD_PRIO_INHERIT 	支持优先级继承选项

_SC_THREAD_PRIO 		_POSIX_THREAD_PRIO_ 		支持线程优先级选项

_SC_THREAD_PRIORITY_SCHEDULING 	_POSIX_THREAD_PRIORITY_SCHEDULING 支持线程优先级调度选项

_SC_THREAD_PROCESS_SHARED 	_POSIX_THREAD_PROCESS_SHARED 	支持进程共享同步

_SC_THREAD_SAFE_FUNCTIONS   _POSIX_THREAD_SAFE_FUNCTIONS  支持线程安全函数

_SC_THREAD_DESTRUCTOR_ITERATIONS 	_PTHREAD_THREAD_DESTRUCTOR_ITERATIONS 	决定在线程退出时尝试销毁线程特定数据的尝试次数

_SC_CHILD_MAX 		CHILD_MAX 		每个UID允许的最大进程数目

_SC_PRIORITY_SCHEDULING 	_POSIX_PRIORITY_SCHEDULING 	支持进程调度

_SC_REALTIME_SIGNALS 	_POSIX_REALTIME_SIGNALS 	支持实时信号

_SC_XOPEN_REALTIME_THREADS 	_XOPEN_REALTIME_THREADS 	支持X/Open POSIX实时线程特性组

_SC_STREAM_MAX 	STREAM_MAX 	决定进程能够打开的流的数目

_SC_SEMAPHORES 	_POSIX_SEMAPHORES 	支持信号量

_SC_SEM_NSEMS_MAX 	SEM_NSEMS_MAX 	决定线程能够拥有的信号量的最大数目

_SC_SEM_VALUE_MAX 	SEM_VALUE_MAX 	决定信号量的最大值

_SC_SHARED_MEMORY_OBJECTS 	_POSIX_SHARED_MEMORY_OBJECTS 	支持共享内存对象

下面是调用sysconf( )的示例：

    if(PTHREAD_STACK_MIN == (sysconf(_SC_THREAD_STACK_MIN))){  
       //...  
    } 


===================================================================================
 每一个系统对资源分配和使用不是随意的，都有限制。如对登录名的最大长度，系统存储页长度，每个实际用户ID的最大进程数等的限制。
可也用以下三个函数来查看这些限制。
long sysconf(int name)  对系统资源限制进行查看
long pathcongf(char *pathname,int name)  对一个文件资源限制进行查看，pathname为一个文件路径
long fpathconf(int fd,int name)          对一个打开的文件的资源限制进行查看，fd为一个文件描述符
具体限制参数（name）请看 APUE P33

#include
#include

int main()

{

long max;

max=sysconf(_SC_CHILD_MAX);

printf("HILD_MAX=%ld\n",max);

 

max=sysconf(_SC_LINE_MAX);

printf("LINE_MAX=%ld\n",max);

return 0;

}

结果：
HILD_MAX=1024
LINE_MAX=2048


#include

#include

int main()

{

long max;

max=pathconf("/etc/passwd",_PC_LINK_MAX);

printf("LINK_MAX=%ld\n",max);

 

max=pathconf("/etc/passwd",_PC_MAX_CANON);

printf("MAX_CANON=%ld\n",max);

return 0;
}

 

   同样，对于每一个进程都有一组资源限制，其中一些可以用getrlimit和setrlimit查询和更改。
int getrlimit(int resource,struct rlimit *ptr)
int setrlimit(int resource,struct rlimit *prt)

struct rlimit{
rlim_t rlim_cur;  //soft limit
rlim_t rlim_max;  //hard limit
};
资源限制：RLIMIT_NOFILE,这是对每个进程能打开的最大文件数进行限制。
具体还哪些资源限制有那些请看APUE P165

#include
#include
#include
#include
#include
#include
#include
int main(void)
 {
 struct rlimit r;
 if(getrlimit(RLIMIT_NOFILE,&r)<0)
 {
 perror("getrlimit error");
 exit(1);
 }
 printf("RLIMIT_NOFILE cur:%d\n",r.rlim_cur);
 printf("RLIMIT_NOFILE max:%d\n",r.rlim_max);
 

 r.rlim_cur=100;
 r.rlim_max=200;
 if (setrlimit(RLIMIT_NOFILE,&r)<0)
 {
 fprintf(stderr,"setrlimit error\n");
 exit(1);
 }
 
 if(getrlimit(RLIMIT_NOFILE,&r)<0)
 {
 fprintf(stderr,"getrlimit error\n");
 exit(1);
 }
 printf("RLIMIT_NOFILE cur:%d\n",r.rlim_cur);
 printf("RLIMIT_NOFILE max:%d\n",r.rlim_max);
 return 0;
 }
 

===================================================
    #include <stdio.h>  
    #include <stdlib.h>  
    #include <unistd.h>  
      
    int main()  
    {  
        printf("Size of a page in bytes:%ld\n",sysconf(_SC_PAGESIZE));  
        printf("Max length of a  hostname:%ld\n",sysconf(_SC_HOST_NAME_MAX));  
        printf(" The maximum number of files that a process can have open at any time.:%ld\n",sysconf(_SC_OPEN_MAX));  
        printf("  The  number  of  clock  ticks  per  second.:%ld\n",sysconf(_SC_CLK_TCK));   
        printf("The number of processors currently online .:%ld\n",sysconf(_SC_NPROCESSORS_ONLN));   
        printf("The number of processors configured..:%ld\n",sysconf(_SC_NPROCESSORS_CONF));   
        return 0;  
    }  

输出信息：


[cpp] view plaincopy

    Size of a page in bytes:4096  
    Max length of a  hostname:64  
     The maximum number of files that a process can have open at any time.:1024  
      The  number  of  clock  ticks  per  second.:100  
    The number of processors currently online .:1  
    The number of processors configured..:1  
