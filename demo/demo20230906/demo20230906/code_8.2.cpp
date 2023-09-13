#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

/*
*file:code_8.2.cpp
*Date:2023/09/06
*Description:
*/

int main_code82(void) {
	int arr[10] = { 0 };
	char ch;
	printf("Enter a number: ");

	while ((ch = getchar()) != '\n') {
		if (ch >= '0' && ch <= '9') {
			++arr[ch - '0'];
		}
	}

	for (int i = 0; i < 10; i++) {
		printf("%3d", i);
	}

	putchar('\n');

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%3d", arr[i]);
	}

	putchar('\n');

	return 0;
}
