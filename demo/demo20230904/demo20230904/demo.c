#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

/*
*file:demo.c
*Date:2023/09/05
*Description:
*/

int main(void) {
	long n, sum = 0;
	printf("Enter number , 0 stop:");
	scanf("%ld", &n);
	while (n != 0) {
		sum += n;
		scanf("%ld", &n);
	}
	printf("sum= %ld\n", sum);
}
