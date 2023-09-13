#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

/*
*file:max_min.c
*Date:2023/09/09
*Description:
*/

#define N 10

void max_min(int arr[], int arr_qt, int* min, int* mas);
int main_max_min(void) {
	int arr[N], i, small, big;

	printf("Enter %d number: ", N);
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	max_min(arr, N, &small, &big);
	printf("min=%d, max=%d\n", small, big);


	return 0;
}

void max_min(int array[], int n, int* min, int* max) {
	*min = *max = array[0];
	for (int i = 0; i < N; i++) {
		if (*max < array[i]) {
			*max = array[i];
		}
		else if (*min > array[i]) {
			*min = array[i];
		}
	}
}
