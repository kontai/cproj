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

void mainyo() {
	struct MyStruct a = { {1,2,3,4,5,6,7,8,9,10},10 };
	struct MyStruct b = a;
	struct MyStruct* c = &a;

	change(a);

	printf("\nmain %p ", a.a);
	for (int i = 0; i < a.length; i++)
	{
		printf("%d ", a.a[i]);
	}

	for (int i = 0; i < b.length; i++)
	{
		b.a[i] = i * 3;
	}

	printf("\nb %p ", b.a);
	for (int i = 0; i < b.length; i++)
	{
		printf("%d ", b.a[i]);
	}

	printf("\nc %p ", c->a);
	for (int i = 0; i < c->length; i++)
	{
		c->a[i] = i * 3;
	}
	
	for (int i = 0; i < a.length; i++)
	{
		printf("%d ", a.a[i]);
	}
	system("pause");
}