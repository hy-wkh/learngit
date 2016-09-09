
snprintf(格式化字符串输入)
#include<stdio.h>
int snprintf(char *restrict buf,
			 size_t num,
			 const char *restrict format...);
----buf为目标字符数组，num指定buf数组的长度，其他参数为输入数据
----函数执行成功返回str的长度，失败返回-1
----功能：函数根据format中的格式信息，将参数中的数据打印到str指向的内存中，最多打印（num-1）个字符到str中，当需要打印的串多于num个字符时，则截取（num-1）个字符。函数执行完后，在str末尾加上'\0'

#include<stdio.h>
#define BUF_SIZE 1024
int main(){
	char str[BUF_SIZE];
	int year,month,day;
	scanf("%d %d %d",&year,&month,&day);
	if((snprintf(str,BUF_SIZE,"year:%d--month:%d--day:%d",year,month,day))==-1){
		perror("fail to sprintf");
		return 1;
	}
	printf("date is %s\n",str);
	return 0;
}









