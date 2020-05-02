/*
2020/04/19 17:49:09
函數指針.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#if 0

int fun(int a) {
	printf("%d\n", a);
	return 0;
}

void main() {
	//函數指針,指向函數的指針。

	//定義函數指針變量有三種方式：

	//	1.先定義函數類型，根據類型定義指針變量
	//		有typedef使類型.沒有的話是變量。

	typedef int FUN(int a);	//FUN函數類型
	FUN* p1 = NULL;	//函數指針變量
	//p1=&fun;
	p1 = fun;
	p1(6);

	//	2.先定義函數指針類型,根據類型定義指針變量（常用）

	typedef int(*PFUN)(int a);	//PFUN,函數指針類型
	PFUN p2 = fun;	//p2指向fun
	p2(7);

	//	3.直接定義函數指針（常用）

	int (*p3)(int a) = fun;
	p3(8);

	int (*p4)(int a);
	p4 = fun;
	p4(9);

	system("pause");
}
#endif