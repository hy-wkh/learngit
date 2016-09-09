#include <pthread.h>
int pthread_cancel(pthread_t thread);
----thread就是要取消的目标线程的线程ID
----线程可以通过取消机制迫使其他线程返回，线程可以调用该函数来取消另一个线程，结果由目标线程的类型和取消状态决定
----返回：成功返回０，否则返回一个非０的错误码
----在默认情况下，该函数会使pthread标识的线程的行为表现为如同调用了参数为PTHREAD_CANCELED的pthread_exit函数。注：该函数并不等待线程终止，它仅仅提出请求






