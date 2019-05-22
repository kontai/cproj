/*
2019/05/19 19:49:59
結構體與結構體數組副本機制.c
*/

#include<stdio.h>
#include<stdlib.h>

struct MyStruct
{
	int a[10];
	int length;
};

void change(struct MyStruct s1)
{
	printf("\nchange %p ", s1.a);
	for (int i = 0; i < s1.length; i++)
	{
		s1.a[i] = i * 3;
		printf("%d ", s1.a[i]);
	}
}

void main() {
	struct MyStruct a = { {1,2,3,4,5,6,7,8,9,10},10 };
	change(a);

	printf("\nmain %p ", a.a);
	for (int i = 0; i < a.length; i++)
	{
		printf("%d ", a.a[i]);
	}

	system("pause");
}