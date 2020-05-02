/*
2020/05/02 9:42:04
三種方式.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#if 0

#define ID 6666

void main() {

//	(1) 測試存在
#ifdef ID
	printf("ID=%d\n", ID);
#else
puts("not exist..........\n");
#endif

//	(2) 測試不存在
#ifndef ID2
puts("ID2 not exist!");
#else
puts("not exist..........\n");
#endif

//	(3) 根據表達式定義
#if i
puts("true\n");
#else
puts("false\n");
#endif

	system("pause");
}

#endif