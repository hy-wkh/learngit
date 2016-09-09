

 
tanh（取双曲线正切函数值）  
相关函数  cosh，sinh
 
表头文件  #include<math.h>
 
定义函数  double tanh(double x);
 
函数说明  tanh()用来计算参数x的双曲线正切值，然后将结果返回。数学定义式为:sinh(x)/cosh(x)。
 
返回值  返回参数x的双曲线正切值。
 
附加说明  使用GCC编译时请加入-lm。
 
范例  #include<math.h>
main()
{
double answer = tanh(0.5);
printf("tanh(0.5) = %f\n",answer);
}
 
执行  tanh(0.5) = 0.462117
用户组篇
endgrent（关闭组文件）  
相关函数  getgrent，setgrent
 
表头文件  #include<grp.h>
#include<sys/types.h>
 
定义函数  void endgrent(void);
 
函数说明  endgrent()用来关闭由getgrent()所打开的密码文件。
 
返回值  
 
附加说明  
 
范例  请参考getgrent()与setgrent()。
 
　 

 
