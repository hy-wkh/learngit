字符串：
	<1>string line;
	   getline(cin,line);
	   1.getline从输入流的下一行读取，并保存读取内容到string中，但不读入换行符
	   2.getline遇到换行符返回，哪怕第一个字符就是换行符也是
	   3.getline将string参数作为返回值，可以用该返回值用作判断条件

	<2> cin读取string时：（除了返回值以外，其他和scanf一样）
	    1.cin读取并忽略开头遇到的所有的空白字符
	    2.读取字符直到再次遇到空白符，读取终止
	    例如:cin>>"hello world!",则输出的是"hello"

	<3> char *fgets(char *str,int size,FILE *stream);
		1.----函数说明: fgets()用来从参数stream所指的文件内读入字符并存到参数str所指的内存空间，直到出现换行字符、读到文件尾或是已读了size-1个字符为止，最后会加上NULL作为字符串结束。

	<4> char *gets(char *s);
		----函数说明: gets()用来从标准设备读入字符并存到参数s所指的内存空间，直到出现换行字符或读到文件尾为止，最后加上NULL作为字符串结束。
		----附加说明  由于gets()无法知道字符串s的大小，必须遇到换行字符或文件尾才会结束输入，因此容易造成缓冲溢出的安全性问题。建议使用fgets()取代。

	<5> int fgetc(FILE *stream);
		1.----函数说明: fgetc()从参数stream所指的文件中读取一个字符并以unsigned char 形式返回。若读到文件尾而无数据时便返回EOF。该函数会返回读取到的字符，若返回EOF则表示到了文件尾

	<6> int getc(FILE *stream);
		1.----函数说明: getc()用来从参数stream所指的文件中读取一个字符。若读到文件尾而无数据时便返回EOF。虽然getc()与fgetc()作用相同，/*但getc()为宏定义*/，非真正的函数调用。getc()会返回读取到的字符，若返回EOF则表示到了文件尾。

	<7> int getchar(void);
		----函数说明: getchar()用来从标准输入设备中读取一个字符。然后将该字符从unsigned char转换成int后返回。
		----返回值: getchar()会返回读取到的字符，若返回EOF则表示有错误发生。getchar()非真正函数，/*而是getc(stdin)宏定义*/。

	<8> scanf:(除了返回值以外，和cin一样的)
		1.从标准输入读取字符串，读取并忽略开头遇到的所有的空白字符，直到再次遇到空格或回车为止
		2.返回值: 成功则返回参数数目，失败则返回-1，错误原因存于errno中。








