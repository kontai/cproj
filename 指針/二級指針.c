#include "stdafx.h"


void main2() {
	int a[3][5] = { 0 };
	int sum = 0;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 5;j++) {
		a[i][j] = sum;
		sum++;
		printf("%d,%x\t", a[i][j],&a[i]+j);
		}
	printf("\n");
	}

	printf("\n\n");

	printf("%x,%x\n", a, *a);
	printf("%d,%d,%d\n", sizeof(a), sizeof(&a), sizeof(*a));
	printf("\n\n");
	printf("%d,%x\n", *(*a+2), (*(a+1)+1));
	printf("\n\n");
	printf("%d,%x\n",*(*a+2),a+2);

	system("pause");
}

