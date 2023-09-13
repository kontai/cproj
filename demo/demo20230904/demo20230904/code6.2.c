#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

/*
*file:code6.2.cpp
*Date:2023/09/04
*Description: 求最大公約數
*/

int main_code62(void) {
	int n, m, r;
	printf("Enter two numbers: ");
	scanf("%d %d", &n, &m);
	while (n != 0) {
		r = m % n;
		m = n;
		n = r;
	}
	printf("GCD is %d\n", m);
	//return 0;
}
