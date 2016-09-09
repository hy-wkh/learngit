/*#include<unistd.h>
int access(const char *pathname,int mode);
----参数pathname表示测试文件的路径，mode表示测试的模式
----该函数进行访问权限的测试，测试调用者进程是否有访问文件的权限
----该函数使用进程的实际用户ID和实际组ID与文件的所有者ID和组ID进行比较：
	如果进程的实际用户ID和文件的所有者ID相等，则使用参数mode指定权限与文件的所有者权限进行比较
	如果进程的实际用户ID和文件的所有者ID不相等，且进程的实际组ID和文件的组ID相等，则使用参数mode指定权限与文件的组权限进行比较
	上述条件都不成立，则使用参数mode指定的权限与文件的其他用户权限进行比较

int faccessat(int fd,const char *pathname,int mode,int flag);

----返回：成功返回０，否则返回-1
----
       access()  checks  whether  the calling process can access
       the file pathname.  If pathname is a symbolic(adj.符号的) link, it is
       dereferenced（n.摒弃，解除参照）.

       The  mode specifies（vt.详细说明，规定） the accessibility（n.可以得到，易接近）
	   check(s) to be performed（v.执行，表演）, and is either the value F_OK, or a mask  
	   consisting  of  the bitwise（n.按位） OR of one or more of R_OK, W_OK, and
       X_OK.  F_OK tests for the existence of the  file.   R_OK,
       W_OK,  and  X_OK  test whether the file exists and grants
       read, write, and execute permissions, respectively.

       The check is done using the calling  process's  real  UID
       and  GID,  rather  than the effective IDs as is done when
       actually attempting an operation (e.g., open(2))  on  the
       file.   This allows set-user-ID programs to easily deter‐
       mine（v.决定） the invoking user's authority.

       If the calling process is privileged (i.e., its real  UID
       is  zero), then an X_OK check is successful for a regular
       file if execute permission is enabled for any of the file
       owner, group, or other.

----
  	   The  faccessat() system call operates in exactly the same
       way as access(), except  for  the  differences  described
       here.

       If the pathname given in pathname is relative, then it is
       interpreted（vt.说明，解释） relative to the directory referred to（参考，适用于）
	   by  the　file  descriptor  dirfd (rather than relative to the current
	　 working directory of the calling process, as is done
       by access() for a relative pathname).

       If  pathname  is  relative and dirfd is the special value
       AT_FDCWD, then pathname is interpreted  relative  to  the
       current  working  directory  of the calling process (like
       access()).

       If pathname is absolute, then dirfd is ignored.

       flags is constructed by ORing together zero  or  more  of
       the following values:

*/
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(int argc,char *argv[]){
	if(argc!=2)perror("Usage....");
	if(access(argv[1],R_OK)<0)perror("accesss error!");
	else perror("read access ok");
	if(open(argv[1],O_RDONLY)<0)perror("open error");
	else perror("open for reading");
	return 0;
}










