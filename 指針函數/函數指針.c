/*
2020/04/19 17:49:09
��ƫ��w.c
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
	//��ƫ��w,���V��ƪ����w�C

	//�w�q��ƫ��w�ܶq���T�ؤ覡�G

	//	1.���w�q��������A�ھ������w�q���w�ܶq
	//		��typedef������.�S�����ܬO�ܶq�C

	typedef int FUN(int a);	//FUN�������
	FUN* p1 = NULL;	//��ƫ��w�ܶq
	//p1=&fun;
	p1 = fun;
	p1(6);

	//	2.���w�q��ƫ��w����,�ھ������w�q���w�ܶq�]�`�Ρ^

	typedef int(*PFUN)(int a);	//PFUN,��ƫ��w����
	PFUN p2 = fun;	//p2���Vfun
	p2(7);

	//	3.�����w�q��ƫ��w�]�`�Ρ^

	int (*p3)(int a) = fun;
	p3(8);

	int (*p4)(int a);
	p4 = fun;
	p4(9);

	system("pause");
}
#endif