SYNOPSIS
       #include <libgen.h>

       char *dirname(char *path);

       char *basename(char *path);

DESCRIPTION
       Warning: there are two different functions
       basename() - see below.

       The  functions  dirname()  and  basename()
       break a  null-terminated  pathname  string
       into  directory  and  filename components.
       In the usual case, dirname()  returns  the
       string up to, but not including, the final
       '/', and basename() returns the  component
       following  the  final  '/'.   Trailing '/'
       characters are not counted as part of  the
       pathname.

       The following list of examples (taken from
       SUSv2)   shows  the  strings  returned  by
       dirname()  and  basename()  for  different
       paths:

       path       dirname   basename
       /usr/lib   /usr      lib
       /usr/      /         usr

       usr        .         usr
       /          /         /
       .          .         .
       ..         .         ..

也就是说dirname返回上一层目录，basename返回文件
