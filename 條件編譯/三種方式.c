/*
2020/05/02 9:42:04
�T�ؤ覡.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#if 0

#define ID 6666

void main() {

//	(1) ���զs�b
#ifdef ID
	printf("ID=%d\n", ID);
#else
puts("not exist..........\n");
#endif

//	(2) ���դ��s�b
#ifndef ID2
puts("ID2 not exist!");
#else
puts("not exist..........\n");
#endif

//	(3) �ھڪ�F���w�q
#if i
puts("true\n");
#else
puts("false\n");
#endif

	system("pause");
}

#endif