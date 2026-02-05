#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include"foo.h"

/*
*file:demo.c
*Date:2023/09/15
*Description:
*/
#define PRING_1(k,n) printf("The " a##k "is %d\n",n);

int main(void) {
	extern int a[];
	int i = 0;
	for (; i < 5; i++) {
		PRING_1(i, a[i]);
	}
	return 0;
}
