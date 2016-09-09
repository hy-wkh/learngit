/*
#include<stdio.h>
FILE *freopen(const char *path,const char *mode,FILE *stream);
----path为文件的指定路径
	mode为打开模式
	stream为一打开的流文件指针
----返回：执行成功则返回流文件指针，失败则返回NULL并设置errno
----函数在执行时会先关闭参数stream指定的文件，并作相应的清理工作，然后以mode模式打开path指定的文件。返回该文件的流指针
*/
#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	string s;
	FILE *stream;
	if(freopen("/home/file2","w",stdout)==NULL)
		fprintf(stderr,"ERROR");
	if(freopen("/home/file1","r",stdin)==NULL)
		fprintf(stderr,"ERROR2");
	while(1){
		cin>>s;
		if(s=="change")
			freopen("/dev/tty","w",stdout);//恢复原来的流
		if(s=="END")break;
		cout<<s<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
xf bu zhi dao ni change zui jin guo de hao ma? wxn! END
*/

