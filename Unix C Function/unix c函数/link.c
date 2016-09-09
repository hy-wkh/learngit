/*
//创建一个现有文件的链接
#include<unistd.h>
int link(const char *path,const char *newpath);
----path是一个现有的文件路径
----newpath是一个新的文件名
----返回：成功返回０，失败返回-1
----功能：该函数创建一个新的目录项，这个目录项使用newpath所表示的路径的最末端作为文件的文件名
----LINUX并不允许普通用户创建一个链接到目录的硬链接，因为这样可能导致文件系统的目录树形结构中出现回路。根用户可以创建链接到目录的硬链接，但这种操作应该杜绝
----一个文件可以对应多个目录项，也就是有多个文件名，因为他们都对应同一个从磁盘文件。当一个磁盘文件没有目录项对应时，这个文件将不能被系统所引用。因此，当该文件不再处于打开状态时，系统将删除该文件。

int linkat(int efd,
		   const char *existingpath,
		   int nfd,
		   cnost char *newpath,
		   int flag);
----现有文件是通过第一个和第二个参数指定的，新的路径名是通过第３个和第４个参数指定的，flag参数设置了AT_SYMLINK_FOLLOW标致，就创建指向符号链接目标的链接，如果这个标致被清除了，则创建一个指向符号链接本身的链接


*/
#include<unistd.h>

int main(){
	link("test.c","test_link.c");
	return 0;
}






