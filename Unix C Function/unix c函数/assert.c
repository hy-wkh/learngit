       #include <assert.h>
       void assert(scalar expression);
       
       ----assert是assert.h头文件中的一个宏定义，如果expression返回"为真，则继续往下执行，如果为假，则报错退出程序。"
       ----如果在assert.h之前定义一个NDEBUG宏，则可以禁用assert.h中的assert宏定义，这样，所有的代码中的所有assert测试都将不起作用了。
       ----在编译命令行中加上-DNDEBUG选项就相当于在源文件开头定义了NDEBUG宏
       
       assert.h的一种实现：
       #undef assert
       #ifdef NDEBUG
           #define assert(test) ((void)0)
       #else
           void _Assert(char *);
           #define _STR(x) _VAL(x)
           #define _VAL(x) #x
           #define assert(test) ((test)?(void)0:_Assert(__FILE__":"_STR(__LINE__)" "#test))
       #endif


#define NDEBUG
#include<iostream>
#include<assert.h>
//#define NDEBUG  //一定要在<assert.h>之前定义，否则不管用
#define sign 0
using namespace std;

int main(int argc,char *argv[]){
	assert(sign);
	cout<<"hy"<<endl;
	return 0;
}





