// cproj.cpp : 定義主控台應用程式的進入點。
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include<stdlib.h>
#include <stdarg.h>
#include <string.h>

char add(int num,...)
{
	va_list arg ;
	va_start(arg, num);
	for (int i = 0;i < num;i++)
	{
		char temp[50] ;
		strcpy(temp , va_arg(arg, char *));
		printf("%s\n", temp);
	}

}


void main2()
{
	add(3, "skdfji","weopiw","skldjfhw");

	system("pause");
}
