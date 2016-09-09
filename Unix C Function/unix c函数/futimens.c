/*apue-101
#include<sys/stat.h>
int futimens(int fd,struct timespec times[2]);
int utimenstat(int fd,
			   const char *path,
			   const struct timespc times[2],
			   int flag);
----这两个函数可以指定纳秒级精度的时间戳，futimens函数需要打开文件来更改它的时间，utimenstat函数提供了一种使用文件名更改文件时间的方法
----times数组参数的第一个元素包含访问时间，第二个元素包含修改时间

int utimes(const char *pathname,const struct timeval times[2]);
----该函数对路径名进行操作
		struct utimbuf {
               time_t actime;       // access time 
               time_t modtime;      // modification time 
           };

utimensat()  and  futimens()  update  the timestamps(n.时间戳) of a
       file with nanosecond（n.纳秒） precision.  This contrasts with  the
       historical utime(2) and utimes(2), which permit only sec‐
       ond and microsecond precision, respectively, when setting
       file timestamps.

       With  utimensat()  the file is specified via（prep.通过） 
	   the pathname given in pathname.  With futimens() the file 
	   whose  timestamps  are  to  be updated is specified via 
	   an open file descriptor, fd.

       For both calls, the new file timestamps are specified  in
       the  array times: times[0] specifies the new "last access
       time" (atime); times[1] specifies the new "last modifica‐
       tion time" (mtime).  Each of the elements of times speci‐
       fies a time as the  number  of  seconds  and  nanoseconds
       since  the  Epoch, 1970-01-01 00:00:00 +0000 (UTC).  This
       information is conveyed in a structure of  the  following
       form:
		 struct timespec {
               time_t tv_sec;        // seconds 
               long   tv_nsec;       // nanoseconds 
           };

       Updated  file  timestamps  are  set to the greatest value
       supported by the filesystem that is not greater than  the
       specified time.

       If  the  tv_nsec  field of one of the timespec structures
       has the special value UTIME_NOW, then  the  corresponding
       file  timestamp  is  set  to  the  current  time.  If the
       tv_nsec field of one of the timespec structures  has  the
       special  value  UTIME_OMIT,  then  the corresponding file
       timestamp is left unchanged.  In both of these cases, the
       value of the corresponding tv_sec field is ignored.

       If  times  is  NULL,  then both timestamps are set to the
       current time.
*/

#include<stdio.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
	int i,fd;
	struct stat statbuf;
	struct timespec times[2];
		for(i=1;i<argc;++i){
			if(stat(argv[i],&statbuf)<0){
				printf("stat %d error...\n",i);
			    continue;
			}
			if((fd=open(argv[i],O_RDWR|O_TRUNC))<0){
				perror("fail to open...");
				continue;
			}
		times[0]=statbuf.st_atim;
		times[1]=statbuf.st_mtim;
		futimens(fd,times);
		close(fd);
		}
	return 0;
}






