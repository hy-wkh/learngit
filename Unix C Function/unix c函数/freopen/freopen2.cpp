//1 3 5 7 9 100
#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	freopen("/home/file1","w",stdout);
	int a;
	while(1){
		cin>>a;
		cout<<a<<" ";//这个地方之前没写，光cin>>a不能写到file1，因为cin不是stdout；
		if(a==100){
			fclose(stdout);//不是fclose（“/home/file1”）;
			break;
		}
	}
	freopen("/home/file1","r",stdin);
	freopen("/home/file2","w",stdout);
	while(1){
		cin>>a;
		a+=1;
		cout<<a<<" ";//如果没输出“ ”，那么文件里的数据不会有空格；
		if(a==10){
			fclose(stdin);
			fclose(stdin);//关闭流并不会终止循环，所以break不可少; 
			break;
		}
	}
	return 0;
}:
