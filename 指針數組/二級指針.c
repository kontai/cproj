/*
2018/11/10 20:11:14
二級指針.c
*/

#include<stdio.h>
#include<stdlib.h>

void main(){
	int **pp = calloc(3, 4);                  //分配指針數組
	for (int i = 0; i < 3; i++) {
		*(pp + i) = malloc(4 * sizeof(int));  //每個指針分配內存
			printf("%10p", *(pp + i) );       //動態分配,位址不連續
	}
	putchar('\n');

	int(*pa)[10] = (int[3][10]) { 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++)
			printf("%10p", *(pa + i) + j);
	}


	system("pause");
}