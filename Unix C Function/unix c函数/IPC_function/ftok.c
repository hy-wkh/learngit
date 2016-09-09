#include<sys/ipc/h>
key_t ftok(const char *path,int id);
----该函数允许独立的进程根据一个已知的路径名导出相同的键，path和id的组合唯一地标识了IPC键（对象）
----path为文件名，参数id允许几个相同类型的IPC对象从一个路径名中生成键值
----返回：成功返回一个键值，否则返回（key_t）-1 并设置errno


