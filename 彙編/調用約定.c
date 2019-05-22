/*
2019/02/26 0:45:59
調用約定.c
*/

#include<stdio.h>
#include<stdlib.h>

int __cdecl fun1() {
	return 0;
}

int __stdcall fun2() {

	return 0;
}

int _fastcall fun3(int x,int y,int z) {
	int a=2;
	int b=3;
	int c=4;
	return x+y+z+a+b;
}

void main2(){
	fun3(1, 2, 3);

	system("pause");
}