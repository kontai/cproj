/*
2018/11/04 16:23:55
�����ϥΤ覡.c
*/

#include<stdio.h>
#include<stdlib.h>

#define max(A,B) A>B?A:B
#define swap(A,B) B,A
#define dprint(expr) printf(#expr" = %g\n",expr) //�Ÿ�#�i�N�޼ƴ������r��
#define paste(A,B) A##B
void main(){
	printf("%d\n", max(2, 3));
	printf("%d,%d\n", swap(2, 3));
	dprint(34.4 / 2);
	printf("%s\n", paste("number, 3"));
	

	system("pause");
}