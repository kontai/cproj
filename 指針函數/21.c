/*
2018/11/11 8:41:30
21.c
*/
#if 0

#include<stdio.h>
#include<stdlib.h>
int addF(int a, int b) {
	return a + b;
}

int subF(int a, int b) {
	return a - b;
}

int divF(int a, int b) {
	return a / b;
}

int pwrF(int a, int b) {
	int num=a;
	
	while (b--) {
		a *=  a;
	}
	return num;
}



void main(){
	int(*pf[])(int a, int b) = { addF,subF,divF,pwrF };
	for (int i = 0; i < 4; i++)
		printf("%4d\n", (pf[i])(2,4));

	system("pause");
}
#endif

