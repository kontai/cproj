#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//�_�w�ƧǪk:�۾F�⤸�����,�ŦX����N���洫,�g�L(�Ʋժ���-1)�����ƫ�N����

#if 0
#define MAX_SIZE 20
void main() {

	//�H���ƺؤl
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