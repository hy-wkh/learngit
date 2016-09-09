**********************************
1.由于pthread库不是linux系统默认的库，连接时需要使用库libpthread.a，所以在使用pthread_create创建线程时，在编译中要加入lpthread参数
例如：cc -o pthread -lpthread pthread.c

gcc -o ff -lpthread graph11-4.c -pthread


