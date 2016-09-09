#include <pthread.h>
void pthread_testcancel(void);
----在代码中特定的位置上设置一个cancel点，当类型为PTHREAD_CANCEL_DEFERRED的线程到达这样一个取消点时，就接受挂起的cancel请求
----没有返回值




