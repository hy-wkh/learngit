     
     #include<netdb.h>
       struct servent *getservbyname(const char*service,const char *protoname);
     
     ----该函数用于根据给定名字查找相应网络服务。(在程序代码中通过其名字而不是其端口号来指定一个服务，而且从名字到端口号的映射关系保存在一个文件中。)
     ----返回：成功返回非空指针，出错则返回NULL,但不置错误原因
     ----service:指定服务名，如果同时指定了协议(protoname参数为非空指针)，那么指定服务必须有匹配的协议。
     	protoname:具体的协议名
	
	例如：
		struct servent *sptr;
		sptr=getservbyname("ftp","tcp");//ftp using tcp
	
	DESCRIPTION
       The getservent() function reads the next entry  from  the
       services database (see services(5)) and returns a servent
       structure  containing  the  broken-out  fields  from  the
       entry.   A connection is opened to the database if neces‐
       sary.

       The getservbyname() function returns a servent  structure
       for  the entry from the database that matches the service
       name using protocol proto.  If proto is NULL, any  proto‐
       col will be matched.  A connection is opened to the data‐
       base if necessary.

		   struct servent {
               char  *s_name;       /* official service name */
               char **s_aliases;    /* alias list */
               int    s_port;       /* port number */
               char  *s_proto;      /* protocol to use */
           }
       The members of the servent structure are:
       s_name The official name of the service.

       s_aliases
              A  NULL-terminated  list  of alternative names for
              the service.

       s_port The port number for the service given  in  network
              byte order.

       s_proto
              The name of the protocol to use with this service.








