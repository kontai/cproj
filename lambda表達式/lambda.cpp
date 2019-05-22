/*
2019/05/19 8:27:01
lambda.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

void main() {
	[]() {printf("test"); }();
	[]() {
		int* p = (int*)malloc(1000 * sizeof(int));
		for (int i = 0; i < 1000; i++)
		{
			*(p + i) = i;
			printf("%6d", *(p + i));
			if (!(i % 10))
				putchar('\n');
		}
	}();

	putchar('\n');

	char a[] = { 'a','b','c','d' };

	//編譯時，需要設定取消一致性(屬性/語言/一致性(/permissive))
	for each (char ch in a)
	{
		printf("%c\n", ch);
	}

	for (char ch : a) {
		printf("%c\n", ch);
	}
	system("pause");
}