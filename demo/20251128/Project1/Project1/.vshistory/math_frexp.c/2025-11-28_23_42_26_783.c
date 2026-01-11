#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
*2025/11/28
*AuTHOR:kontai
*
*/

int main() {
	double d = 1024, fraction;
	fraction = frexp(d, &exponent);
	printf("%lf = %lf * 2 ^ %d\n", d, fraction, exponent);)
	return EXIT_SUCCESS;
}