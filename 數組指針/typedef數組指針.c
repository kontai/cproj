/*
2019/11/04 17:21:40
typedef數組指針.cpp
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void mainI(){
	int a[10] = { 1,2,3 };
	typedef int A[10];	//A:數組類型
	A b;	//int b[10],數組類型變量，普通變量。
	A* p1=NULL;	//數組類型定義數組指針變量。
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

	typedef int(*P)[10];	//數組指針類型
	P p2;	//數組指針變量

	system("pause");
}