/*
2018/11/04 16:23:55
巨集使用方式.c
*/

#include<stdio.h>
#include<stdlib.h>

#if 0
#define max(A,B) A>B?A:B
#define swap(A,B) B,A
#define dprint(expr) printf(#expr" = %g\n",expr) //使用#把宏参数变为一个字符串
#define paste(A,B) A##B	//我们用##把两个宏参数贴合在一起
void main(){
	printf("%d\n", max(2, 3));
	printf("%d,%d\n", swap(2, 3));
	dprint(34.4 / 2);
	printf("%s\n", paste("number, 3"));
	

	system("pause");
}
#endif