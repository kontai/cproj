#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//冒泡排序法:相鄰兩元素比較,符合條件就做交換,經過(數組長度-1)的次數後就完成

#if 0
#define MAX_SIZE 20
void main() {

	//隨機數種子
	time_t start_t = NULL;
	srand((unsigned)start_t);

	int a[MAX_SIZE] = { 0 };
	int *p[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		a[i] = rand(start_t) % 20;
		*(p + i) = *(a + i);
		printf("%d ", *(p + i));
	}
	for (int i = 0; i <= MAX_SIZE - 1; i++) {
		for (int j = i; j <= MAX_SIZE - 1; j++) {
			if (*(p + i) > *(p + j))
			{
				int temp = *(p + i);
				p[i] = p[j];
				*(p + j) = temp;
			}
		}
	}

	puts("\n\n\n");
	for (int i = 0; i < MAX_SIZE; i++)
		printf("%d ", *(p + i));

	system("pause");
}
#endif