gettimeofday（取得目前的时间）  
相关函数  time，ctime，ftime，settimeofday
#include <sys/time.h>
int gettimeofday ( struct timeval * tv , struct timezone * tz );
----tv以毫秒为单位的系统时间，tz为时区信息结构类型指针
----gettimeofday()会把目前的时间有tv所指的结构返回，当地时区的信息则放到tz所指的结构中。
----返回：成功返回０，否则返回-1并设置errno;
----功能：函数会取得系统当前的时间变量的值，并存储到tv指向的结构体中，timeval为精确到毫秒级的时间值。函数同时取得当前系统的时区信息，并存储到tz所指向的结构中
timeval结构定义为:
struct timeval{
	time_t tv_sec; //秒
	time_t tv_usec; //微秒
};
timezone 结构定义为:
struct timezone{
	int tz_minuteswest; //和Greenwich 时间差了多少分钟
	int tz_dsttime; //日光节约时间的状态
};
上述两个结构都定义在/usr/include/sys/time.h。tz_dsttime 所代表的状态如下
DST_NONE /*不使用*/
DST_USA /*美国*/
DST_AUST /*澳洲*/
DST_WET /*西欧*/
DST_MET /*中欧*/
DST_EET /*东欧*/
DST_CAN /*加拿大*/
DST_GB /*大不列颠*/
DST_RUM /*罗马尼亚*/
DST_TUR /*土耳其*/
DST_AUSTALT /*澳洲（1986年以后）*/
 
附加说明EFAULT指针tv和tz所指的内存空间超出存取权限。

范例  
#include<sys/time.h>
#include<unistd.h>
int main(){
	struct timeval tv;
	struct timezone tz;
	gettimeofday (&tv , &tz);
	printf(“tv_sec; %d\n”, tv,.tv_sec) ;
	printf(“tv_usec; %d\n”,tv.tv_usec);
	printf(“tz_minuteswest; %d\n”, tz.tz_minuteswest);
	printf(“tz_dsttime, %d\n”,tz.tz_dsttime);
	return 0;
}
 
执行  
tv_sec: 974857339
tv_usec:136996
tz_minuteswest:-540
tz_dsttime:0
