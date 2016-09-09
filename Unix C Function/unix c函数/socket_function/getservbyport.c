#include<netdb.h>
struct servent *getservbyport(int port,char *protoname);

----该函数用于给定端口号和可选协议查找相应网络服务，port参数的值必须为网络字节序；
	
	struct servent *sptr;
	sptr=getservbyport(htons(21),"tcp");//ftp　using tcp
	sptr=getservbyport(htons(21),NULL);//ftp using tcp








