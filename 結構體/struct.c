// 結構體.cpp : 定義主控台應用程式的進入點。
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct  tt1 
{
	int num;
	char str[10];
	float fl;
	struct fuse
	{
		int a1;
		char c1[100];

	}A1;
	struct fuse B1;
};


void main()
{
	struct tt1 m1 = { 2,"test",2.3 };
	printf("%f\n", m1.fl);
	m1.B1.a1 = 100;
	printf("%d", m1.B1.a1);



	system("pause");

}