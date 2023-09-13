#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
/*
*file:return_ele.c
*Date:2023/09/09
*Description:
*/
#define N 20

int* find_middle(int arr[], int size);
int main(void) {
	int arr[N] = { 0 }, i;
	int* p;
	srand((unsigned int)time(NULL));


	for (i = 0; i < N; i++) {
		arr[i] = rand() % 101;
		printf("%d ", arr[i]);
	}
	putchar('\n');
	p = find_middle(arr, N);

	printf("middle of array is %d\n", *p);

	return 0;
}

int* find_middle(int arr[], int size) {
	return &arr[size / 2];
}
