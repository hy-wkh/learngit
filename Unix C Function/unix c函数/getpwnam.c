getpwnam（从密码文件中取得指定账号的数据）  
相关函数  getpw，fgetpwent，getpwent，getpwuid
 
#include<pwd.h>
#include<sys/types.h>
struct passwd * getpwnam(const char * name);
 
----getpwnam()用来逐一搜索参数name 指定的账号名称，找到时便将该用户的数据以passwd结构返回。passwd结构请参考getpwent()。
 
----返回passwd 结构数据，如果返回NULL 则表示已无数据，或有错误发生。
 
struct passwd {
               char   *pw_name;       /* username */
               char   *pw_passwd;     /* user password */
               uid_t   pw_uid;        /* user ID */
               gid_t   pw_gid;        /* group ID */
               char   *pw_gecos;      /* user information */
               char   *pw_dir;        /* home directory */
               char   *pw_shell;      /* shell program */
           };

/*取得root账号的识别码和根目录*/
#include<pwd.h>
#include<sys/types.h>
main()
{
struct passwd *user;
user = getpwnam(“root”);
printf(“name:%s\n”,user->pw_name);
printf(“uid:%d\n”,user->pw_uid);
printf(“home:%s\n”,user->pw_dir);
}
 
执行  name:root
uid:0
home:/root
 
　 

