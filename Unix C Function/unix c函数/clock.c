/*
#include<time.h>
clock_t clock(void);
----返回的为clock_t类型值，说明的是近似于程序当前运行时间值
----功能：函数运行时，会取得程序从运行到当前的时间值，这个返回时间值的单位与系统中的时钟单位相同，在linux下是100ms为一个单位。
----函数所取的值为一个近似值，是程序运行到上一次时钟为止。在系统中会定义一个CLOCKS_PER_SEC常量，来说明系统时钟与秒的转换比值
*/
#include<time.h>
#include<stdio.h>
//#include<fcntl.h>
int main(){
	int a,b;
	b=0;
	for(a=0;a<0x10000000;++a)//增加函数运行时间
		b+=a;
	printf("%u\n",clock()/CLOCKS_PER_SEC);
	return 0;
}


