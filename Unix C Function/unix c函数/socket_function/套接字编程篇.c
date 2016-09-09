面向连接的套接字建立流程：
	(1) 首先要启动服务器，通过调用socket()建立一个套接字
	(2) 然后调用bind()，将该套接字和本地网络地址联系在一起；
	(3) 再调用listen()，使套接字做好侦听的准备，并规定其请求队列的长度；
	(4) 最后调用accept()来接收连接。
	(5) 客户在建立套接字后就可以调用connect()，与服务器建立连接。
	(6) 连接一旦建立，客户机和服务器之间就通过调用read()和write()接收和发送数据。
	(7) 数据传送结束，双方调用close()关闭套接字。
     
面向无连接套接字建立流程：
	(1)首先启动服务器，通过调用socket()建立一个套接字
	(2)然后调用bind()，将该套接字和本地网络地址联系在一起
	(3)调用recvfrom函数，该函数允许调用方指明从一个无连接的套接字上输入数据

连接：read,write
无连接：readfrom,sendto,recvfrom



       //#include <sys/types.h>          /* See NOTES */
       //#include <sys/socket.h>
       int socket(int domain, int type, int protocol);
       ----domain:The domain argument specifies a communication domain; 
       			　　ipv4 PF_INET
				  ipv6 PF_INET6
				  unix文件系统 PF_UNIX
		   type:指明要求的通信类型
		   		SOCK_DGRAM 数据报
		   	　　　　SOCK_STREAM 可靠数据流交付服务
		   	　　　　SOCK_RAW 网络接口的原始类型(允许有特权的程序访问底层协议或网络接口)
		   protocol:选择一个具体的协议(如果在协议族中只有一种能够提供某种type类型的协议，这时可把第三个参数设置为0)



       //#include <sys/types.h>          /* See NOTES */
       //#include <sys/socket.h>
       int bind(int sockfd, const struct sockaddr *addr,
                socklen_t addrlen);
                
           ----函数功能：将协议地址绑定到一个套接字；其中协议地址包含IP地址和端口号；  
           ----该函数为套接字建立一个本地地址.应用程序并不关心它们使用的本地地址，而是很愿意让协议软件来填写计算机的ip地址，并选择一个端口号。但是在某个熟知端口上操作的服务进程必须为系统指明端口。如果一个客户没有调用bind，操作系统会自动分配一个端口号
           	　　　sockfd:是要绑定的描述符
           	　　　addr:是一个指定套接字要绑定的本地地址的结构
           	　　　addrlen:是一个指定地址长度
           ----sockaddr是一个通用结构。当该结构中的地址族字段值为２，则意味着其余８位组中包含的是一个tcp/ip地址。每个协议族都规定了如何使用地址族字段中的８位组。对于tcp/ip地址，套接字地址称为sockaddr_in,它包括一个ip地址和一个协议端口号
           
           ----	当socket函数返回一个描述符时，只是存在于其协议族的空间中，并没有分配一个具体的协议地址（这里指IPv4/IPv6和端口号的组合），对于 TCP 协议，调用 bind 函数可以指定一个端口号，或指定一个 IP 地址，也可以两者都指定，还可以都不指定。若 TCP 客户端或服务器端不调用bind 函数绑定一个端口号，当调用connect 或 listen 函数时，内核会为相应的套接字选择一个临时端口号。一般 TCP 客户端使用内核为其选择一个临时的端口号，而服务器端通过调用bind 函数将端口号与相应的套接字绑定。进程可以把一个特定的 IP 地址捆绑到它的套接字上，但是这个 IP 地址必须属于其所在主机的网络接口之一。对于 TCP 客户端，这就为在套接字上发送的 IP 数据报指派了源 IP 地址。对于 TCP 服务器端，这就限定该套接字只接收那些目的地为这个 IP 地址的客户端连接。TCP 客户端一般不把 IP 地址捆绑到它的套接字上。当连接套接字时，内核将根据所用外出网络接口来选择源 IP 地址，而所用外出接口则取决于到达服务器端所需的路径。若 TCP 服务器端没有把 IP 地址捆绑到它的套接字上，内核就把客户端发送的 SYN 的目的 IP 地址作为服务器端的源 IP 地址。一般只有套接字端点能够与地址绑定，尽管有些协议允许多重绑定;
　
		   为了统一地址结构的表示方法，统一接口函数，使得不同的地址结构可以被bind()、connect()、recvfrom()、sendto()等函数调用。但一般的编程中并不直接对此数据结构进行操作，而使用另一个与之等价的数据结构sockaddr_in。

	       通常服务器在启动的时候都会绑定一个众所周知的协议地址，用于提供服务，客户就可以通过它来接连服务器；而客户端可以指定IP或端口也可以都不指定，未分配则系统自动分配。这就是为什么通常服务器端在listen之前会调用bind()，而客户端就不会调用，而是在connect()时由系统随机生成一个。
		   对于因特网域，如果指定ip地址为INADDR_ANY(<netinet/in.h>中定义,如果不是INADDR_ANY，可以用inet_addr("192.168.0.234");)，套接字端点可以绑定到所有的系统网络接口上，这意味着可以接受这个系统所安装的任何一个网卡的数据包。
		   可以调用getsockname函数来发现绑定到套接字上的地址


       //#include <sys/types.h>          /* See NOTES */
       //#include <sys/socket.h>
       int listen(int sockfd, int backlog);
       ----在编写服务器程序时需要使用监听函数 listen 。服务器进程不知道要与谁连接，因此，它不会主动地要求与某个进程连接，只是一直监听是否有其他客户进程与之连接，然后响应该连接请求，并对它做出处理，一个服务进程可以同时处理多个客户进程的连接。
       
       ----listen 函数仅由 TCP 服务器调用，它有以下两种作用：
		   当 socket 函数创建一个套接字时，若它被假设为一个主动套接字，即它是一个将调用connect 发起连接的客户端套接字。listen 函数把一个未连接的套接字转换成一个被动套接字，指示内核应该接受指向该套接字的连接请求;
	       listen 函数的第二个参数规定内核应该为相应套接字排队的最大连接个数;listen 函数一般应该在调用socket 和bind 这两个函数之后，并在调用 accept 函数之前调用。 内核为任何一个给定监听套接字维护两个队列：
		   未完成连接队列，每个这样的 SYN 报文段对应其中一项：已由某个客户端发出并到达服务器，而服务器正在等待完成相应的 TCP 三次握手过程。这些套接字处于 SYN_REVD 状态;
		   已完成连接队列，每个已完成 TCP 三次握手过程的客户端对应其中一项。这些套接字处于 ESTABLISHED 状态;


       //#include <sys/socket.h>
       int accept(int socket, struct sockaddr *restrict address,
              socklen_t *restrict address_len);
       ----函数功能：从已完成连接队列队头返回下一个已完成连接；若已完成连接队列为空，则进程进入睡眠；  
       ----accept 函数由 TCP 服务器调用，用于从已完成连接队列队头返回下一个已完成连接。如果已完成连接队列为空，那么进程被投入睡眠。该函数的返回值是一个新的套接字描述符，返回值是表示已连接的套接字描述符，而第一个参数是服务器监听套接字描述符。*****一个服务器通常仅仅创建一个监听套接字*****，它在该服务器的生命周期内一直存在。内核为每个由服务器进程接受的客户连接创建一个已连接套接字(表示 TCP 三次握手已完成)，当服务器完成对某个给定客户的服务时，相应的已连接套接字就会被关闭。
       
       -----参数 address 和 address_len 用来返回已连接的对端（客户端）的协议地址；address_len是值-结果参数：调用前，我们将由 *addrlen所指的整数值置为由cliaddr所指的套接口地址结构长度，返回时，此整数值即为由内核存在此套接口地址结构内的准确字节数。
       ----如果函数accept执行成功，则返回值是由内核自动生成的一个全新描述字，代表与客户的TCP连接。当我们讨论accept函数时，常把它的第一个参数称为监听套接字(由函数socket生成的描述符，用作函数bind和listen的第一个参数)，把它的返回值称为已连接的套接字描述符。把这两个套接字描述符区分开很重要，一个给定的服务器常常是只生成一个监听套接自而且一直存在，直到该服务器关闭。内核为每个被接受的客户连接创建了一个已连接的套接字（也就是内核已经为它完成tcp的三路握手过程）。当服务器完成某客户的服务时，关闭已连结的套接字
       
       
	   ----该函数返回套接字描述符，该描述符连接到调用connect函数的客户端；这个新的套接字描述符和原始的套接字描述符sockfd具有相同的套接字类型和地址族，而传给accept函数的套接字描述符sockfd没有关联到这个链接，而是继续保持可用状态并接受其他连接请求；  
 	   ----若不关心客户端协议地址，可将address和address_len参数设置为NULL，否则，在调用accept之前，应将参数address设为足够大的缓冲区来存放地址，并且将address_len设为指向代表这个缓冲区大小的整数指针；  
 	   ----accept函数返回时，会在缓冲区填充客户端的地址并更新address_len所指向的整数为该地址的实际大小；若没有连接请求等待处理，accept会阻塞直到一个请求到来；  

       //#include <sys/types.h>          /* See NOTES */
       //#include <sys/socket.h>
       int connect(int sockfd, const struct sockaddr *addr,
                   socklen_t addrlen);
	   
	   ---- 通过此函数建立于TCP服务器的连接，实际是发起三次握手过程，仅在连接成功或失败后返回。参数sockfd是本地描述符，addr为服务器地址，addrlen是socket地址长度。

	   ----UDP的connect函数，结果与tcp调用不相同，没有三次握手过程。内核只是记录对方的ip和端口号，他们包含在传递给connect的套接口地址结构中，并立即返回给调用进程。



       //#include <unistd.h>
       ssize_t read(int fd, void *buf, size_t count);
       ssize_t write(int fildes, const void *buf, size_t nbyte);


       //#include <sys/uio.h>
       ssize_t readv(int fd, const struct iovec *iov, int iovcnt);
       ssize_t writev(int fd, const struct iovec *iov, int iovcnt);

       //#include <sys/types.h>
       //#include <sys/socket.h>
       ssize_t send(int sockfd, const void *buf, size_t len, int flags);
       
       ----sockfd:发送端套接字描述符(非监听描述符)
       	   buf：应用要发送数据的缓存
       	　　　len：实际要发送的数据长度
      	 　　flags：一般设置为0
      	 　　
       ----每个TCP套接口都有一个发送缓冲区，它的大小可以用SO_SNDBUF这个选项来改变。调用send函数的过程，实际是内核将用户数据拷贝至TCP套接口的发送缓冲区的过程：若len大于发送缓冲区大小，则返回-1；否则，查看缓冲区剩余空间是否容纳得下要发送的len长度，若不够，则拷贝一部分，并返回拷贝长度（指的是非阻塞send，若为阻塞send，则一定等待所有数据拷贝至缓冲区才返回，因此阻塞send返回值必定与len相等）；若缓冲区满，则等待发送，有剩余空间后拷贝至缓冲区；若在拷贝过程出现错误，则返回-1。关于错误的原因，查看errno的值。

       如果send在等待协议发送数据时出现网络断开的情况，则会返回-1。注意：send成功返回并不代表对方已接收到数据，如果后续的协议传输过程中出现网络错误，下一个send便会返回-1发送错误。TCP给对方的数据必须在对方给予确认时，方可删除发送缓冲区的数据。否则，会一直缓存在缓冲区直至发送成功（TCP可靠数据传输决定的）。

	 　　
       ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
                      const struct sockaddr *dest_addr, socklen_t addrlen);
                      
       ----通常用于UDP套接口，用数据报方式进行数据传输。由于无连接的数据报模式下，没有建立连接，需指明目的地址，addrlen通常为sizeof(sockaddr)的长度。成功时返回发送的字节数，失败返回-1。

       当本地与不同目的地址通信时，只需指定目的地址，可使用同一个UDP套接口描述符sockfd，而TCP要预先建立连接，每个连接都会产生不同的套接口描述符，体现在：客户端要使用不同的fd进行connect，服务端每次accept产生不同的fd。

       因为UDP没有真正的发送缓冲区，因为是不可靠连接，不必保存应用进程的数据拷贝，应用进程中的数据在沿协议栈向下传递时，以某种形式拷贝到内核缓冲区，当数据链路层把数据传出后就把内核缓冲区中数据拷贝删除。因此它不需要一个发送缓冲区。写UDP套接口的sendto/write返回表示应用程序的数据或数据分片已经进入链路层的输出队列，如果输出队列没有足够的空间存放数据，将返回错误ENOBUFS.

	   每一个TCP套接口有一个发送缓冲区，我们可以用SO_SNDBUF套接口选项来改变这个缓冲区的大小。当应用程序调用write时，内核从应用程序进程的缓冲区中拷贝所有数据到套接口的发送缓冲区。如果套接口的发送缓冲区容不下应用程序的所有数据（或是应用程序的缓冲区大于套接口发送缓冲区，或是套接口发送缓冲区还有其他数据），应用进程将被挂起（睡眠）。这里假设套接口是阻塞的，它是通常的缺省设置（还有非阻塞的套接口）。内核将不从write系统调用返回，直到应用程序缓冲区中的所有数据都拷贝到套接口发送缓冲区。因此从写一个TCP套接口的write调用成功返回仅仅表示我们可以重新使用应用进程的缓冲区。它并不告诉我们对端的TCP或应用程序已接收到数据。

TCP取套接口发送缓冲区的数据并把它发送给对端TCP，其过程基于TCP数据传送的所有规则。对端TCP必需确认收到数据，只有收到对端的ACK，本端TCP才能删除套接口发送缓冲区中已确认的数据。TCP必需保留数据拷贝直到对端确认为止。

TCP以MSS大小的或更小的块把数据传递给IP，同时给每个数据块安上一个TCP头部以构成TCP分节，其中的MSS是由对端通告的，当对端未通告时就用536这个值（IPv4的最小重组缓冲区字节数576减去IPv4头部字节20和TCP头部字节数20）。IP给每个TCP分节安上IP头部以构成IP数据报，查找其宿IP地址的路由表项以确定外出接口，然后把数据报传递给相应的数据链路。IP可能在把数据报传递给数据链路之前将其分片，不过我们已经谈到MSS选项的目的之一就是试图避免分片，而较新的实现又使用了路径MTU发现功能。每个数据链路都有一个输出队列，如果该队列已满，那么新到的分组将被丢弃，并沿协议栈向上返回一个错误，从链路层到IP层，再从IP层到TCP层。TCP将注意到这个错误，并在以后某个时刻重传相应分片。应用进程并不知道这种暂时情况。

	   		这一次我们展示的套接口发送缓冲区用虚线框，因为它并不存在。UDP套接口有发送缓冲区大小（我们可以用SO_SNDBUF套接口选项修改），不过它仅仅是写到套接口的UDP数据报的大小上限。如果应用进程写一个大于套接口发送缓冲区大小的数据包，内核将返回一个EMSGSIZE错误。既然UDP是不可靠的，它不必保存应用程序的数据拷贝，因此无需一个真正的发送缓冲区。（应用进程的数据在沿协议向下传递时，以某种形式拷贝到内核的缓冲区，然而数据链路层在送出这些数据后将丢弃该拷贝）

UDP简单地给用户数据报安上它的8个字节的头部以构成UDP数据报，然后传递给IP。IPv4或IPv6给UDP数据报安上相应的IP头部以构成IP数据报，执行路由操作确定外出接口，然后直接把数据包加入数据链路层输出队列（如果适合于MTU），或者分片后再把每个片加入数据链路层的输出队列。如果某个UDP应用进程发送大数据报，那么它比TCP应用进程更有可能分片，因为TCP会把应用数据划分成MSS大小的块，而UDP却没有对等的手段。

从写UDP套接口的write调用成功地返回表示用户写入的数据报或其所有片段已被加入数据链路层的输出队列。如果该队列没有足够的空间存放该数据报或它的某个片段，内核通常将给应用程序返回一个ENOBUFS错误。
 

       ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flags);


       //#include <sys/types.h>
       //#include <sys/socket.h>
       ssize_t recv(int sockfd, void *buf, size_t len, int flags);
       
        ----sockfd：接收端套接字描述符；
			buf：指定缓冲区地址，用于存储接收数据；
			len：指定的用于接收数据的缓冲区长度；
			flags：一般指定为0
       ----表示从接收缓冲区拷贝数据。成功时，返回拷贝的字节数，失败返回-1。阻塞模式下，recv/recvfrom将会阻塞到缓冲区里至少有一个字节(TCP)/至少有一个完整的UDP数据报才返回，没有数据时处于休眠状态。若非阻塞，则立即返回，有数据则返回拷贝的数据大小，否则返回错误-1，置错误码为EWOULDBLOCK。
       
       ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                        struct sockaddr *src_addr, socklen_t *addrlen);

		----sockfd：接收端套接字描述
       		buf：用于接收数据的应用缓冲区地址
      	 	len：指名缓冲区大小
       		flags：通常为0
       		src_addr：数据来源端的地址
       		addrlen：src_addr地址的长度
		----注意后两个参数是输出参数，其中addrlen既是输入又是输出参数，即值-结果参数，需要在调用时，指明src_addr的长度。另外，如果不关心数据发送端的地址，可以将后两者均设置为NULL。

       ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags);


       //#include <sys/socket.h>
       int getpeername(int  sockfd,  struct  sockaddr  *addr,  socklen_t *addrlen);
       int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);




















