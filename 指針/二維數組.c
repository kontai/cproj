/*
2018/10/31 13:04:47
二維數組.c
*/

#include<stdio.h>
#include<stdlib.h>

void main2a() {
	int a[3][5];
	//a,&a,*a大小
	printf("a=%d,&a=%d.*a=%d,**a=%d", sizeof(a), sizeof(&a), sizeof(*a), sizeof(**a));
	putchar('\n');
	//for (int *p = &(a[0][0]); p < *a+15; p++) {
	for (int *p = a[0]; p < a[0] + 15; p++) {
		//for (int *p = &(a[0][0]); p < &(a[0][0])+15; p++) {
		*p = 1;
		printf("%d,%p\n", *p, p);
	}

	{
		int b[3][4] = { 1,3,5,7,9,11,13,15,17,19,21,23 };
		printf("%d,%d\n", b, *b);
		printf("%d,%d\n", b[1], *(b+1));
		printf("%d,%d\n", &b[1], b+1);
		printf("%d,%d\n", &b[1]+1,*(b[1]+1) );

	}
	

	system("pause");
}