/*
2019/11/04 17:21:40
typedef�Ʋի��w.cpp
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void mainI(){
	int a[10] = { 1,2,3 };
	typedef int A[10];	//A:�Ʋ�����
	A b;	//int b[10],�Ʋ������ܶq�A���q�ܶq�C
	A* p1=NULL;	//�Ʋ������w�q�Ʋի��w�ܶq�C
	printf("A* p1=%p,p1+1=%p\n", p1, p1 + 1);



	A* p = NULL;
	p = &a;
	for (int i = 0; i < 10; i++)
	{
		//(*p)[i] = i + 1;
		*(*p+i) = i + 1;
	}
	for (int i = 0; i < 10; i++)
		printf("%d ", (*p)[i]);

	typedef int(*P)[10];	//�Ʋի��w����
	P p2;	//�Ʋի��w�ܶq

	system("pause");
}