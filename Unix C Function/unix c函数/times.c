/*
#include<sys/times.h>
clock_t times(struct tms *buf);
----times函数用时间账单信息来填充它的参数buf指向的struct tms结构。
----返回：成功返回时钟滴答计数表示的实际耗费的时间，这个时间是从过去任意一点开始计算的，比如可以从系统或进程的起始时间开始计算，失败返回（clock_t）-1并设置errno

struct tms {
     clock_t tms_utime;  / user time /
     clock_t tms_stime;  / system time /
     clock_t tms_cutime; / user time of children /
	 clock_t tms_cstime; / system time of children /
};

时钟滴答（clock tick） 请问时间的嘀嗒数是根据什么来设定的
有必要明确一些Linux内核时钟驱动中的基本概念。
（1）时钟周期（clock cycle）的频率：8253／8254 PIT的本质就是对由晶体振荡器产生的时钟周期进行计数，晶体振荡器在1秒时间内产生的时钟脉冲个数就是时钟周期的频率。Linux用宏 CLOCK_TICK_RATE来表示8254 PIT的输入时钟脉冲的频率（在PC机中这个值通常是1193180HZ），该宏定义在include/asm-i386/timex.h头文件中：
#define CLOCK_TICK_RATE 1193180 // Underlying HZ 
（2）时钟滴答（clock tick）：我们知道，当PIT通道0的计数器减到0值时，它就在IRQ0上产生一次时钟中断，也即一次时钟滴答。PIT通道0的计数器的初始值决定了要过多少时钟周期才产生一次时钟中断，因此也就决定了一次时钟滴答的时间间隔长度。
（3）时钟滴答的频率（HZ）：也即1秒时间内PIT所产生的时钟滴答次数。类似地，这个值也是由PIT通道0的计数器初值决定的（反过来说，确定了时钟滴答的频率值后也就可以确定8254 PIT通道0的计数器初值）。Linux内核用宏HZ来表示时钟滴答的频率，而且在不同的平台上HZ有不同的定义值。对于ALPHA和IA62平台HZ的值是1024，对于SPARC、MIPS、ARM和i386等平台HZ的值都是100。该宏在i386平台上的定义如下（include/asm- i386/param.h）：
#ifndef HZ
#define HZ 100
#endif
根据HZ的值，我们也可以知道一次时钟滴答的具体时间间隔应该是（1000ms／HZ）＝10ms。

times函数使用不适用于线程上取执行时间间隔。一般的时间精度为10ms，比gettimeofday低的。

 

==times tms_utime HandControlProcess=== 0.000000
==times tms_stime HandControlProcess=== 0.000000
==times tms_cutime HandControlProcess=== 0.000000
==times tms_cstime HandControlProcess=== 0.000000
==times tms_cstime HandControlProcess times_2-times_1=== 2000.000000
HZ=100
20.000000

 

#include <stdio.h>

#include <linux/time.h>
#include<sys/times.h>
#include <unistd.h>
#define CLOCKS_PER_SEC 1l

//#define _SC_CLK_TCK 100l


int main()
{
  struct tms tmp;
        struct tms tmp1, tmp2;
     clock_t times_1, times_2;
  clock_t begin = times(&tmp);
  times_1 = times(&tmp1);
  // your code 
  sleep(20);
  times_2 = times(&tmp2);
  printf("==times tms_utime HandControlProcess=== %lf\n", (double)(tmp2.tms_utime-tmp1.tms_utime)/1);
  printf("==times tms_stime HandControlProcess=== %lf\n", (double)(tmp2.tms_stime-tmp1.tms_stime)/1);
  printf("==times tms_cutime HandControlProcess=== %lf\n", (double)(tmp2.tms_cutime-tmp1.tms_cutime)/1);
  printf("==times tms_cstime HandControlProcess=== %lf\n", (double)(tmp2.tms_cstime-tmp1.tms_cstime)/1);
  printf("==times tms_cstime HandControlProcess times_2-times_1=== %lf\n", (double)(times_2-times_1)/1);
  clock_t end = times(&tmp);
  unsigned long HZ = sysconf( _SC_CLK_TCK );


  printf("HZ=%ld\n", HZ);
  printf("%lf\n", (double)(end-begin)/HZ );


}



 linux 函数库之 times
标签： linuxsystemuser任务struct
2012-04-18 16:05 6461人阅读 评论(1) 收藏 举报
分类：
c/c++（14）

函数名： times
头文件： #include<sys/times>
函数声明： clock_t times(struct tms *buf);
man帮助查看: man 2 times
参数介绍：
1. clock_t
typedef long int clock_t
2. tms
struct tms {
    clock_t tms_utime; /* user time */
    clock_t tms_stime; /* system time */
    clock_t tms_cutime; /* user time of children */
    clock_t tms_cstime; /* system time of children */
};
概念：
1.实际时间（real time）：从命令行执行到运行终止的消逝时间

2.用户CPU时间（user CPU time）：命令执行完成花费的系统CPU时间，即命令在用户态中执行时的总和

3.系统CPU时间（system CPU time）：命令执行完成花费的系统CPU时间，即命令在核心态中执行时间的总和。

4.cutime是用户CPU时间+子进程用户CPU时间。cstime同理。

    用户CPU时间和系统CPU时间之和为CPU时间，即命令占用CPU执行的时间总和。实际时间要大于CPU时间，因为Linux是多任务操作系统，往往在执行一条命令时，系统还要处理其他任务。另一个需要注意的问题是即使每次执行相同的命令，所花费的时间也不一定相同，因为其花费的时间与系统运行相关。
    由于tms结构没有提供实际时间，所以times函数返回“实际时间”。事实上，如果想获得某段程序运行的时间，可以由以下代码获得

struct tms tmp;
clock_t begin = times(&tmp);
/* your code */
clock_t end = times(&tmp);
printf("%lf\n", (double) (end-begin)/CLOCKS_PER_SEC );

这个是获得程序的实际运行时间（秒)

其中，CLOCKS_PER_SEC是个宏，定义在bits/time.h，可以这么理解

const long long CLOCKS_PER_SEC = 1000000L;

# define CLOCKS_PER_SEC 1000000

