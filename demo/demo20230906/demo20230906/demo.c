#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

/*
*file:demo.c
*Date:2023/09/05
*Description:
*/

void print_pub() {}

int try_func();
int main(void) {
	int i = try_func();
	printf("function returns values=%d\n", i);
	return 0;
}
int try_func() {
	;
}
