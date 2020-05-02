/*
2018/09/02 7:20:55
stdafx.cpp
*/

#include<stdio.h>
#include<stdlib.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int divv(int a, int b) { return a / b; }
int mod(int a, int b) { return a % b; }

void mainfuncP(){
	int(*p)(int, int)=add;
	printf("a+b=%d\n",p(2, 3));

	int(*pa[])(int, int) = { add,sub,mul,divv,mod };
	size_t size= sizeof(pa) / sizeof(int(*));
	printf("size=%d\n", size);
	for (size_t i = 0; i < size; i++)
		//printf("%d\t", (*(pa + i))(2, 3));
		printf("%d\t", (pa[i])(2, 3));

//	int(**pp)(int, int) = (int (*[]))(int,int) { add, sub, mul, divv, mod };
//	for (size_t i = 0; i < size; i++)
//		printf("%d\t", pp[i](100, 10));

}

void mainJ() {
	int(**p)(int, int) = (int(**)(int, int))malloc(sizeof(int(*)(int, int)) * 4);
	*p = add;
	*(p + 1) = sub;
	*(p + 2) = mul;
	*(p + 3) = divv;
	*(p + 4) = mod;
	size_t size = 5;

	for (size_t i = 0; i < size; i++)
		//printf("%d\t", (*(pa + i))(2, 3));
		printf("%d\t", (p[i])(2, 3));
}

void mainL() {
	mainJ();


	system("pause");
}