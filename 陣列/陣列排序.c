// 陣列.cpp : 定義主控台應用程式的進入點。
//
#define  _CRT_SECURE_NO_WARNINGS 

#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define N 90 


void max_min(int[]);
void sort(int[]);


void main() {
	int num[N];
	int tmp = 0;
	srand((unsigned)time(NULL));

	while (tmp < N) {
		num[tmp] = rand() % 100;
		if (!(tmp % 10))
			putchar('\n');
		printf("num[%2d]=%2d ", tmp, num[tmp]);
		tmp++;
	}

	max_min(num);
	sort(num);
	system("pause");

}

void max_min(int num[]) {
	int  max = 0, min = num[0], i = 0;

	for (;i < N;i++) {
		if (num[i] < min) {
			min = num[i];
		}
		if (num[i] > max) {
			max = num[i];
		}
	}

	printf("min=%d\nmax=%d\n", min, max);

}

void sort(int num[]) {
	for (int i = 0;i < N - 1;i++) {
		for (int min = i + 1;min < N;min++) {
			if (num[i] > num[min]) {
				int tmp;
				tmp = num[i];
				num[i] = num[min];
				num[min] = tmp;
			}

		}
	}

	for (int b = 0;b < N;b++) {
		if (!(b % 10))
			putchar('\n');

		printf("%2d  ", num[b]);
	}


}
