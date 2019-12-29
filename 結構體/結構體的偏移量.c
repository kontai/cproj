/*
2019/12/01 17:12:54
結構體的偏移量.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Teacher
{
	char name[64];
	int age;
	int id;
}Teacher;

int mainOffset(void)
{
	Teacher t1;
	Teacher* p = NULL;
	p = &t1;

	int n1 = (int)(&p->age) - (int)p;	//p相對於結構體首地址
	printf("n1=%d\n", n1);

	int n2 = (int) & ((Teacher*)0)->age;
	printf("n2=%d\n", n2);
	printf("%p\n", p);
	printf("Teacher *=%p , (Teacher*)->age=%p\n", (Teacher*)0, &((Teacher*)0)->age);

	

	system("pause");
}