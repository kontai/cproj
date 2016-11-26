// 字串.cpp : 定義主控台應用程式的進入點。
//

#define _CRT_SECURE_NO_WARNINGS

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

//random color

void main() {

	char *p = "abcd";
	char *c = NULL;
	char a[10] = { 0 };
	c = p;
	for(int i=0;*c!=0;i++,c++)
	{
		a[i] = *c;
	}
	printf("%s",_strupr(a));
	





	system("pause");
}

