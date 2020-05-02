/*
2020/04/12 10:11:24
structDemo.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#if 0

typedef struct Teacher
{
	char* name;
	int age;
}Teacher;

void main() {
	//1
	Teacher t;
	int i = 0;
	t.name = (char*)malloc(sizeof(char) * 30);
	strcpy(t.name, "tai");
	printf("t.name=%s\n", t.name);
	free(t.name);

	//2
	Teacher* p = NULL;
	p = (Teacher*)malloc(sizeof(Teacher));
	if (p == NULL)
	{
		printf("p initial fail!\n");
		exit(-1);
	}
	p->name = (char*)malloc(sizeof(char) * 30);
	strcpy(p->name, "tai2");
	printf("p.name=%s\n", p->name);
	free(p->name);
	free(p);

	//3
	Teacher* q = NULL;
	//Teacher q[3]
	q = (Teacher*)malloc(sizeof(Teacher) * 3);
	if (q == NULL)
	{
		printf("q initial fail!\n");
		exit(-1);
	}
	for (i = 0; i < 3; i++)
	{
		(q + i)->name = (char*)malloc(sizeof(char) * 30);
		if ((q + i)->name == NULL)
		{
			printf("(q+%d)->name initialize fail!\n", i);
			exit(-1);
		}
		sprintf((q + i)->name, "tai%d", i);
	}

	for (i = 0; i < 3; i++)
	{
		printf("(q+%d)->name=%s\n", i, (q + i)->name);
	}

	for (i = 0; i < 3; i++)
	{
		if (((q + i)->name) != NULL)
		{
			free((q + i)->name);
			(q + i)->name = NULL;
		}
	}

	free(q);

	system("pause");
}
#endif