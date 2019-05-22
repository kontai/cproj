/*
2019/03/16 18:11:42
0227指針2.c
*/

#include<stdio.h>
#include<stdlib.h>

void Test_addr() {
	char a = 10;
	short b = 20;
	int c = 30;

	char* pa = &a;
	short* pb = &b;
	int* pc = &c;

	char** ppa = &pa;
	short** ppb = &pb;
	int** ppc = &pc;
}

void Test_addr2() {
	int p = 10;

	int* p1;
	int** p2;
	int*** p3;
	int**** p4;
	int***** p5;
	int****** p6;
	int******* p7;

	p1 = &p;
	p2 = &p1;
	p3 = &p2;
	p4 = &p3;
	p5 = &p4;
	p6 = &p5;
	p7 = &p6;


}

void Funct() {
	//使用指針,將數組的值倒置

	int arr[5] = { 1,2,3,4,5 };
	int* p = arr;
	int lenth = sizeof(arr) / sizeof(*arr);
	for (int i = 0; i < lenth / 2; i++) {
		int temp;

		/*
		temp = *(arr + i);
		*(arr + i) = *(arr + lenth-1 - i);
		*(arr + lenth-1 - i) = temp;
		*/
		temp = arr[i];
		arr[i] = arr[lenth - 1 - i];
		arr[lenth - 1 - i]=temp;

		
	}

	for (int k = 0; k < 5; k++) {
		printf("%d\t", *(arr + k));
	}

}

void main0227(){
	//Test_addr();
	//Test_addr2();
	Funct();

	system("pause");
}