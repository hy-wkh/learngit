
 
write（将数据写入已打开的文件内）  
相关函数  open，read，fcntl，close，lseek，sync，fsync，fwrite
 
表头文件  #include<unistd.h>
 
定义函数  ssize_t write (int fd,const void * buf,size_t count);
 
函数说明  write()会把参数buf所指的内存写入count个字节到参数fd所指的文件内。当然，文件读写位置也会随之移动。
 
返回值  如果顺利write()会返回实际写入的字节数。当有错误发生时则返回-1，错误代码存入errno中。
 
错误代码  EINTR 此调用被信号所中断。
EAGAIN 当使用不可阻断I/O 时（O_NONBLOCK），若无数据可读取则返回此值。
EADF 参数fd非有效的文件描述词，或该文件已关闭。
 
范例  请参考open（）。
文件内容操作篇
clearerr（清除文件流的错误旗标）  
相关函数  feof
 
表头文件  #include<stdio.h>
 
定义函数  void clearerr(FILE * stream);
 
函数说明  clearerr（）清除参数stream指定的文件流所使用的错误旗标。
 
返回值  
