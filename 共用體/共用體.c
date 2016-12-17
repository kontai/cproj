#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

union info {
	int prince;
	double db;
	char str[9];
}a, b;// c = { 12,2.3,"aee" };
//不能在定義共用體時初始化

void main() {
	a.prince = 2;
	strcpy(a.str, "abc");
	/*
	*共用體尺寸:根據成員裡,字節數最大者
	*限制:共用體大小必須包含最大成員數據,並可以 整除最小的成員數據,能夠被最小成員整除 (字節對齊)
	*exp:int=4,char [9]=9;將有填充位元	將尺寸填充至 12 (原9/4 =>   12/4)
	*/

	printf("%d\n", sizeof(union info));
//共用體共用體只能同時存在一個變亮
	//共用體--限制只能使用單個成員變數(最後存放的)
	printf("%d,%s\n", a.prince, a.str);

	//大括號初始化的時候,只能初始化第一個
	union info test = { 2 }; 

	union info *p = &test;
	printf("%d\n", p->prince);//   p->prince  同等於  (*p).prince 
	printf("%d\n", (*p).prince);

	system("pause");
}