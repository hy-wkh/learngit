//线程有两个属性并没有包含在pthread_attr_t结构中，它们是可取消状态（PTHREAD_CANCEL_ENABLE和PTHREAD_CANCEL_DISABLE）和可取消类型，这两个属性影响着pthread_cancel函数调用时所呈现的类型
#include <pthread.h>
int pthread_setcancelstate(int state, int *oldstate);
----state说明要设置的新状态
	oldstate指向一个整数的指针，这个整数中装载了以前的状态
----该函数用来修改调用线程的取消状态
---返回：成功返回０，否则返回一个非０的错误码

int pthread_testcancel();
----该函数用来在程序中添加自己的取消点

int pthread_setcanceltype(int type, int *oldtype);
----功能：根据type参数指定的值来修改线程的取消类型。
----oldtype:指向一个位置，该位置保存了以前的取消类型
---返回：成功返回０，否则返回一个非０的错误码











