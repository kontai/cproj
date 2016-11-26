// 指針.cpp : 定義主控台應用程式的進入點。
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"

void change(int *, int *);          // declare two int pointer

void main1() {
	int a=200, b=300;
	int *pa=&a, *pb=&b;

	printf("before\na=%d,b=%d\n\n", *pa, *pb);

	change(pa,pb);
	
	printf("after change\n a=%d,b=%d\n\n", *pa, *pb);

	printf("after \na=%d,b=%d\n\n", *pa, *pb);
	system("pause");

}

void change(int *pta, int *ptb)
{
	*pta = 10;
	*ptb = 20;
	printf("changing\n(a)=%d.change(b)=%d\n\n", *pta, *ptb);

}
