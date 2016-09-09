/*#include <getopt.h>
int getopt_long(int argc, char * const argv[],
         const char *shortopts,
         const struct option *longopts, int *longindex);

----argc、argv是main函数的两个同名的参数。
	shortopts一般为一个字符串常量，代表所有的短选项，就是一般以“-”开头的选项，如果选项后带参数，则必须在相应的字符后面加“：”，如“ab:cde:”。
	longindex参数如果没有设置为NULL，那么它就指向一个变量，这个变量会被赋值为寻找到的长选项在longopts中的索引值，这可以用于错误诊断。
	longopts是一个struct option结构体的数组，option结构体的定义如下：
struct option{
         const char *name;
         int has_arg;
         int *flag;
         int val;
};
		name是长选项的名字，
		has_arg值为0、1、2，分别表示没有参数、有参数、参数可选，
		flag如果为NULL，函数返回val的值，否则将val的值写入flag指向的变量中，一般情况下，如果flag为NULL，则val的值为该长选项对应的短选项。如
const struct option long_options[] = {
     { "help",                0, NULL, 'h' },
     { "output",            1, NULL, 'o' },
     { "version",         0, NULL, 'v' },
     { NULL,            0, NULL, 0   }
};
 
----该函数的几种返回值:
	0  getopt_long()设置一个标志，它的值与option结构中的val字段的值一样    
	1     每碰到一个命令行参数，optarg都会记录它    
	'?'    无效选项    
	':'    缺少选项参数    
	'x'    选项字符'x'    
	-1    选项解析结束    

一般的用法为while(getopt_long() != -1){}，可以通过switch语句来对该函数不同的返回值（即不同的短选项）调用不同的处理函数。
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <getopt.h>
int main(int argc,char *argv[]){
  int opt;
  struct option longopts[] = {
    {"initialize",0,NULL,'1'},
    {"file",1,NULL,'f'},
    {"list",0,NULL,'1'},
    {"restart",0,NULL,'r'},
    {0,0,0,0}
  };
  while((opt = getopt_long(argc, argv, "if:lr", longopts, NULL)) != -1){
    switch(opt){
    case 'i':
    case 'l':
    case 'r':
      printf("option: %c\n",opt);
      break;//上面３个case共用这一个printf
    case 'f':
      printf("filename: %s\n",optarg);
      break;
    case ':':
      printf("option needs a value\n");
      break;
    case '?':
      printf("unknown option: %c\n",optopt);
      break;
  }
    for(; optind < argc; optind++){
      printf("argument: %s\n",argv[optind]);
    }
  }
      exit(0);
}

/*
hy@hy-K53BE:~/桌面$ ./ff -l -f 1 -r -i
option: l
argument: -f
argument: 1
argument: -r
argument: -i


*/


