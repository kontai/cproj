/*
2018/11/10 8:18:38
�ʺA���t.c
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
		printf("ERROR: �ӽФ��s����");
		return -1;
	}

	else
		printf("���s���a�}%4p\n", p);
	for (int i = 0; i < n; i++)
	{
		p[i] = i;
		printf("%d\t", *(p + i));
	}
	putchar('\n');

	free(p);
	printf("�����,���s�a�}%4p\n", p);	    //���s�����,���w�٬O���V�Ӥ��s,�����i��Ӥ��s�i��ާ@
	

	p = NULL;
	printf("���w�k�s��,���s�a�}%4p\n", p);		//�N���w�k�s
	free(p);

	system("pause");
}