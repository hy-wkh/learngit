/*
getpwuid（从密码文件中取得指定uid 的数据）  
相关函数  getpw，fgetpwent，getpwent，getpwnam
 
#include<pwd.h>
#include<sys/types.h>
struct passwd * getpwuid(uid_t uid);
----uid为指定的用户标识符
----功能：函数根据参数指定的uid在文件/etc/passwd中寻找该用户的信息，如果找到则取出该信息缓存在一个静态定义的passwd结构中，然后返回该结构体的指针类型，如果没有找到目标数据则返回NULL,passwd 结构请参考getpwent()。
----返回值：返回passwd结构类型的指针，成功则返回该uid指定的用户信息，如果返回NULL则表示已无数据，或者有错误发生。
----注：函数返回的结构体指针指向的是一个静态定义的passwd结构，所以在下一次调用该函数之前如果想保存上一次的查找结果，应该使用passwd结构的实例来保存信息。再调用该函数。
*/
#include<pwd.h>
#include<sys/types.h>
int main(){
	struct passwd *user;
	user= getpwuid(6);
	printf(“name:%s\n”,user->pw_name);
	printf(“uid:%d\n”,user->pw_uid);
	printf(“home:%s\n”,user->pw_dir);
}
执行:
name:shutdown
uid:6
home:/sbin

