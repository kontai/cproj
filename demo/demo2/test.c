#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <Windows.h>

void call_exe() {
	ShellExecuteA(0, "open", "c:\\AiOLog.txt", 0, 0, 1);
}

#if 0
void main() {
	int a = 10;
	printf("%p", &a);

	getchar();
}


void main() {
	int a = 5;
	int b = 10;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a=%d,b=%d", a, b);
}

#endif

void main() {
	char a = 'A';
	printf("%d,%d\n", sizeof(a), sizeof('A'));
	printf("%lc\n", L'§A¦n');
}
