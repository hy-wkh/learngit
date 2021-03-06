#include <unistd.h>
int getopt(int argc, 
		   char * const argv[],
           const char *optstring);
           
    extern char *optarg;
    extern int optind, opterr, optopt;
              

----功能：getopt()用来分析命令行参数
----参数说明：
	argc和argv分别代表参数个数和内容，跟main（）函数的命令行参数是一样的。参数 
	optstring为欲处理的字符串， 告知 getopt()可以处理哪个选项以及哪个选项需要参数，如果选项字符串里的字母后接着冒号“:”，则表示还有相关的参数，全域变量optarg 即会指向此额外参数。如果在处理期间遇到了不符合optstring指定的其他选项getopt()将显示一个错误消息，并将全域变量optarg设为“?”字符，如果不希望getopt()打印出错信息，则只要将全域变量opterr设为0即可。

----此函数会返回在argv 中下一个的选项字母，此字母会对应参数optstring 中的字母,并设置一些全局变量。使用相同的参数再次调用该函数时，它将返回下一个选项，并设置相应的全局变量。如果不再有可识别的选项，将返回 -1，此任务就完成了。

----getopt()所设置的全局变量包括：
	1.char *optarg——指向当前选项参数（如果有）的指针。 
	2.int optind——argv的当前索引值。当getopt()在while循环中使用时，循环结束后，剩下的字串视为操作数，在argv[optind]至argv[argc-1]中可以找到。
	3.int opterr——这个变量非零时，getopt()函数为“无效选项”和“缺少参数选项，并输出其错误信息。
	4.int optopt——当发现无效选项字符之时，getopt()函数或返回'?'字符，或返回':'字符，并且optopt包含了所发现的无效选项字符。
	
----optstring中的指定的内容的意义（例如getopt(argc, argv, "ab:c:de::");）
	1.单个字符，表示选项，（如上例中的abcde各为一个选项）
	2.单个字符后接一个冒号：表示该s选项后必须跟一个参数。参数紧跟在选项后或者以空格隔开。该参数的指针赋给optarg。（如上例中的b:c:）
	3.单个字符后跟两个冒号，表示该选项后可以跟一个参数，也可以不跟。如果跟一个参数，参数必须紧跟在选项后不能以空格隔开。该参数的指针赋给optarg。(如上例中的e::，如果没有跟参数，则optarg = NULL)
	
----短参数的定义：
        getopt()使用optstring所指的字串作为短参数列表，象"1ac:d::"就是一个短参数列表。短参数的定义是一个'-'后面跟一个字母或数字，象-a, -b就是一个短参数。每个数字或字母定义一个参数。 
　其中短参数在getopt定义里分为三种：
　　1. 不带值的参数，它的定义即是参数本身。
　　2. 必须带值的参数，它的定义是在参数本身后面再加一个冒号。
　　3. 可选值的参数，它的定义是在参数本身后面加两个冒号 。
　　在这里拿上面的"1ac:d::"作为样例进行说明，其中的1,a就是不带值的参数，c是必须带值的参数，d是可选值的参数。
　　在实际调用中，'-1 -a -c cvalue -d', '-1 -a -c cvalue -ddvalue', '-1a -ddvalue -c cvalue'都是合法的。这里需要注意三点：
　　1. 不带值的参数可以连写，象1和a是不带值的参数，它们可以-1 -a分开写，也可以-1a或-a1连写。
　　2. 参数不分先后顺序，'-1a -c cvalue -ddvalue'和'-d -c cvalue -a1'的解析结果是一样的。
　　3. 要注意/*可选值的参数的值与参数之间不能有空格，必须写成-ddvalue这样的格式*/，如果写成-d dvalue这样的格式就会解析错误。

----返回值:
　   getopt()每次调用会逐次返回命令行传入的参数。
　   当没有参数的最后的一次调用时，getopt()将返回-1。
　   当解析到一个不在optstring里面的参数，或者一个必选值参数不带值时，返回'?'。
　   当optstring是以':'开头时，缺值参数的情况下会返回':'，而不是'?' 。

#include <stdio.h>  
#include <unistd.h>  
 
int main(int argc, char *argv[])  {  
    int ch;  
    opterr = 0;  
    while ((ch = getopt(argc,argv,"a:b::cde"))!=-1){  
        switch(ch){  
            case 'a':  
                printf("option a:'%s'\n",optarg);  
                break;
            case 'b':  
                printf("option b :'%s'\n",optarg);  
                break;  
            default:  
                printf("other option :%c\n",ch);  
        }
    }
    printf("optopt +%c\n",optopt);  
    return 0;
}  

hy@hy-K53BE:~/桌面$ g++ -o ff tmp.cpp
hy@hy-K53BE:~/桌面$ ./ff -a a -b -c (也可以写成-aa -b -c)
option a:'a'
option b :'(null)'
other option :c
optopt +

$ ./getopt -a  
other option :?  
optopt +a  
$ ./getopt -b  
option b :b  
optopt +  
$ ./getopt -c  
other option :c  
optopt +  
$ ./getopt -d  
other option :d  
optopt +  
$ ./getopt -abcd  
option a:'bcd' 
optopt +  
$ ./getopt -bcd  
option b :b  
other option :c  
other option :d  
optopt +  
$ ./getopt -bcde  
option b :b  
other option :c  
other option :d  
other option :e  
optopt +  
$ ./getopt -bcdef  
option b :b  
other option :c  
other option :d  
other option :e  
other option :?  
optopt +f  


----改变getopt()对错误命令行参数信息的输出行为
不正确的调用程序在所难免，这种错误要么是命令行选项无效，要么是缺少选项参数。正常情况下，getopt()会为这两种情况输出自己的出错信息，并且返回'?'。为了验证此事，可以修改一下上面的清单2中的代码。
清单3：
#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv)
{
    int oc;                     /*选项字符 */
    char *b_opt_arg;            /*选项参数字串 */

    while((oc = getopt(argc, argv, "ngl:")) != -1)
    {
        switch(oc)
        {
            case 'n':
                printf("My name is Lyong.\n");
                break;
             case 'g':
                printf("Her name is Xxiong.\n");
                break;
            case 'l':
                b_opt_arg = optarg;
                printf("Our love is %s\n", optarg);
                break;
            case '?':
                printf("arguments error!\n");
                break;
        }
    }
    return 0;
}
输入一个错误的命令行，结果如下：
$ ./opt_parse_demo -l
./opt_parse_demo: option requires an argument -- l
arguments error!
如果不希望输出任何错误信息，或更希望输出自定义的错误信息。可以采用以下两种方法来更改getopt()函数的出错信息输出行为：

    在调用getopt()之前，将opterr设置为0，这样就可以在getopt()函数发现错误的时候强制它不输出任何消息。
    如果optstring参数的第一个字符是冒号，那么getopt()函数就会保持沉默，并根据错误情况返回不同字符，如下：
        “无效选项” —— getopt()返回'?'，并且optopt包含了无效选项字符（这是正常的行为）。
        “缺少选项参数” —— getopt()返回':'，如果optstring的第一个字符不是冒号，那么getopt()返回'?'，这会使得这种情况不能与无效选项的情况区分开。

清单4：
#include <stdio.h>
#include <unistd.h>

int main (int argc, char **argv)
{
    int oc;                     /*选项字符 */
    char ec;                             /*无效的选项字符*/
    char *b_opt_arg;            /*选项参数字串 */

    while((oc = getopt(argc, argv, ":ngl:")) != -1)
    {
        switch(oc)
        {
            case 'n':
                printf("My name is Lyong.\n");
                break;
             case 'g':
                printf("Her name is Xxiong.\n");
                break;
            case 'l':
                b_opt_arg = optarg;
                printf("Our love is %s\n", optarg);
                break;
            case '?':
                ec = (char)optopt;
                printf("无效的选项字符 \' %c \'!\n", ec);
                break;
            case ':':
                printf("缺少选项参数！\n");
                break;
        }
    }
    return 0;
}
测试结果：
$ ./opt_parse_demo -a
无效的选项字符 ' a '!
$ ./opt_parse_demo -l
缺少选项参数！




