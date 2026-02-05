#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

/*
*file:Pinter_adv_1.c
*Date:2025/08/07
*Description:
*/

//二級指針作為輸入特性

void print_ptr(int** p, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printf("%d\n", *p[i]);
	}
}

void mainz()
{
	int** p = malloc(sizeof(int*) * 5);
	//int n1=100;
	//int n2=200;
	//int n3=300;
	//int n4=400;
	//int n5=500;

	//p[0]=&n1;
	//p[1] = &n2;
	//p[2] = &n3;
	//p[3] = &n4;
	//p[4] = &n5;

	int n[] = { 100, 200, 300, 400, 500 };

	if (p != NULL)
	{
		for (int i = 0; i < 5; i++)
		{
			int j = i * 100;
			*(p + i) = n + i;
		}
	}
	print_ptr(p, 5);
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	return;
}
