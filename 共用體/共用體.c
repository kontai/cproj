#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

union info
{
	int prince;
	double db;
	char str[9];
}a,b,c;

void main()
{
	a.prince = 2;
	strcpy(a.str, "abc");

//共用體尺寸:根據成員裡,字節數最大者

//前提:能夠被最小成員整除 (字節對齊)
//exp:int=4,char [9]=9;將有填充位元	將尺寸填充至 12 (原9/4 =>   12/4)

	printf("%d\n", sizeof(union info)); 

	//共用體--限制只能使用單個成員變數(最後定義的)
	printf("%d,%s", a.prince, a.str); 

	system("pause");
}

