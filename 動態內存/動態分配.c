/*
2018/11/10 8:18:38
動態分配.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void main2() {
	int n;
	scanf("%d", &n);
	int *p = malloc(sizeof(int)*n);
	if (!p)
	{
		printf("ERROR: 申請內存失敗");
		return -1;
	}

	else
		printf("內存首地址%4p\n", p);
	for (int i = 0; i < n; i++)
	{
		p[i] = i;
		printf("%d\t", *(p + i));
	}
	putchar('\n');

	free(p);
	printf("釋放後,內存地址%4p\n", p);	    //內存釋放後,指針還是指向該內存,但不可對該內存進行操作
	

	p = NULL;
	printf("指針歸零後,內存地址%4p\n", p);		//將指針歸零
	free(p);

	system("pause");
}