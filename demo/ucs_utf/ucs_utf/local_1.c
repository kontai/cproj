#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include <locale.h>

/*
*file:local_1.c
*Date:2023/10/14
*Description:
*/

int main(void) {
	char* p;
	//p = setlocale(LC_ALL, "");
	//printf("%d\n", *p);
	struct lconv* loc = localeconv();
	if (loc == NULL) {
		fprintf(stderr, "Error,localerconv error.");
		exit(EXIT_FAILURE);
	}


	return 0;
}
