// ���c��.cpp : �w�q�D���x���ε{�����i�J�I�C
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>


struct mydata
{
	int num;
	char str[100];
};

void changeA(int *p1)
{
	*p1 = 23;
}

void main1()
{
	struct mydata m1;
	struct mydata *p = &m1;


	sprintf((*p).str, "abc");
	printf("%s\n", p->str);

	changeA(p);
	printf("%d", p->num);


	system("pause");
}

