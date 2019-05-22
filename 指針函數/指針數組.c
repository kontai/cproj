// 指針函數.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define row 3
#define  columm 5
#define score 59
#define really_suck 29

void get_rand(int(*)[columm]); //get random number
void avg(int(*)[columm]); //make  average
void sucks(int(*)[columm]);

void main1() {
	int a[row][columm] = { 0 };
	get_rand(a);
	avg(a);
	sucks(a);

	system("pause");
}

void get_rand(int(*pr)[columm]) {
	time_t time_1;
	srand((unsigned)time(&time_1));

	for (int i = 0;i < row;i++) {
		for (int j = 0;j < columm;j++) {
			pr[i][j] = rand() % 101;
			printf("%d\t", pr[i][j]);
		}
		putchar('\n');
	}
}

void avg(int(*pa)[columm]) {
	double sum = 0;
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < columm;j++) {
			sum += pa[i][j];
		}
	}
	printf("average = %f\n", sum / (row*columm));
}

void sucks(int(*psuck)[columm]) {
	printf("(lower score)\n");
	for (int i = 0;i < row;i++) {
		int flag = 1, sflag = 1;
		for (int j = 0;j < columm;j++) {
			if (psuck[i][j] <= score) {
				flag = 0;
				if (psuck[i][j] <= really_suck) {
					sflag = 0;
				}
				break;
			}
		}
		if (flag == 0) {
			for (int f = 0;f < columm;f++) {
				printf("%d\t", psuck[i][f]);
			}
		}
		if (sflag == 0) {
			printf("<===really??");
		}

		putchar('\n');
	}
}