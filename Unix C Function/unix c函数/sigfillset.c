/*
sigfillset（将所有信号加入至信号集）  
 #include<signal.h>
 int sigfillset(sigset_t * set);
----用来将参数set信号集初始化，然后把所有的信号加入到此信号集里 (sigset_t类型是一个位向量，sigfillset函数将参数set所表示的信号集填充，即将该向量的每一个位设置为１)(注：设置为１或加入到信号集中是表示屏蔽该信号)
----执行成功则返回0，如果有错误则返回-1。 
----附加说明 :EFAULT 参数set指针地址无法存取
*/










