/*
2019/03/05 9:28:23
0202ªð¦^­È.c
*/

#include<stdio.h>
#include<stdlib.h>
__int64 fun() {
	__int64 x = 0x1234567890;
	return x;
}

int Arr() {
	/*char arr[3] = { 1,2,3 };
	char arr2[4] = { 1,2,3,4 };*/
	char x[59] = { 0 };
	return 0;
}

void Function()
{
	char x = 1;
	char a[2] = { 0 };
	int y = 2;
	int r;
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	r = arr[1];
	r = arr[x];
	r = arr[x + y];
	r = arr[x * 2 + y];
	
}

void mainAA() {
	//fun();
	//Arr();
	Function();

	system("pause");
}