/*(p204)
#include<termios.h>
int tcsetattr(int filedes,int optional_actions,
			  const struct termios *termios_p);
----termios_p指向的struct termios结构来设置终端的参数
----终端由打开的文件描述符filedes引用
----optional_actions可以用来控制修改生效的点

*/










