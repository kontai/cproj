/*
2018/11/10 20:11:14
�G�ū��w.c
*/

#include<stdio.h>
#include<stdlib.h>

void main(){
	int **pp = calloc(3, 4);                  //���t���w�Ʋ�
	for (int i = 0; i < 3; i++) {
		*(pp + i) = malloc(4 * sizeof(int));  //�C�ӫ��w���t���s
			printf("%10p", *(pp + i) );       //�ʺA���t,��}���s��
	}
	putchar('\n');

	int(*pa)[10] = (int[3][10]) { 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 10; j++)
			printf("%10p", *(pa + i) + j);
	}


	system("pause");
}