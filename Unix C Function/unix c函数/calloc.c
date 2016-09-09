/*
#include<stdlib.h>
void *calloc(size_t num,size_t size);
----num为所要分配的元素数；
----size为元素的大小（以字节为标记），返回的内存空间大小为num*size(byte),并将分配的内存初始化为０；
----返回值：calloc返回的为已分配内存空间的数组首地址，如果失败则返回NULL；
----功能：函数在堆中分配一段大小为num*size字节的内存，并将该内存初始化为０，返回相应的首地址。
----注:因为函数返回的是void类型的指针，所以在程序中，使用之前应强制转换成所需要操作的数据类型指针。
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
	int *p;
	p=(int)calloc(10,sizeof(int));
	if(p==NULL){
		perror("fail to calloc");
		return 1;
	}
	int i;
	for (i=0;i<10;++i){//注：i不可以从０开始
		p[i]=i;
		printf("%d",p[i]);
	}
	printf("\n");
	free(p);
	return 0;
}




