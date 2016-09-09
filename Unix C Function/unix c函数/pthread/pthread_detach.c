#include <pthread.h>
int pthread_detach(pthread_t thread);
----thread是要分离的线程的线程ID
----除非是分离一个线程，否则在线程退出时，它是不会释放它的资源的。该函数的功能就是将线程分离。
----分离线程退出时不会报告它们的状态。没有分离的线程是不可接合的，而且在另一个线程为它们调用pthread_join或者整个进程退出之前，这些线程不会释放它们所有的资源





