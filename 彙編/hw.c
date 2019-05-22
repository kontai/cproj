/*
2019/03/01 0:16:29
hw.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

void main() {
	setlocale(LC_ALL, "");
	wchar_t *a = L"hello•x∆W123";
	printf("%S\n", a);
//	printf("%ls\n", a);
	printf("len=%d", wcslen(a));
	printf("a[3]=%ls", a[2]);



	system("pause");
}