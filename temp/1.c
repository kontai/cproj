/*
2019/05/05 8:02:00
1.c
*/

#include<stdio.h>
#include<stdlib.h>

union pc
{
	int num;
	char ch[100];
	int* p;
}pc1 = { .num = 1000 };

typedef union pc PC;
void main() {
	PC pc1 = { 100 };
	PC pc2[] = { { 100 },{ 100 },{ 100 } };
	PC *pc3 = (PC[]){ { 100 },{ 100 },{ 100 } };
	pc1.p = NULL;
	printf("%d\n", pc1.num);
	system("pause");
//	free(pc1.p) ;
	system("pause");
}