/*
2019/11/17 10:54:42
結構體套一級指針.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

/*
實現
//1
Teacher t;
strcpy(t.name,"lily");

//2
Teacher *p=NULL;
strcpy((p->name,"lily");

//3
Teacher *q=NULL;
Teacher q[3]

*/

typedef struct Teacher
{
	char* name;
	int age;
}Teacher;
void main() {
#pragma region Number1
	//1
	Teacher t;
	t.name = (char*)malloc(sizeof(char) * 30);
	if (t.name == NULL)
		return -1;
	strcpy(t.name, "lily");
	printf("t.name = %s\n", t.name);
	free(t.name);
#pragma endregion 1

#pragma region Number2
	Teacher* p = NULL;
	p = (Teacher*)malloc(sizeof(Teacher));
	if (p == NULL)
		return -2;
	p->name = (char*)malloc(sizeof(char) * 30);
	if (p->name == NULL)
		return -3;

	strcpy(p->name, "lily");
	printf("p->name = %s\n", p->name);
	free(p->name);
	free(p);
	p = NULL;
#pragma endregion  Number2

#pragma region Number3

	int i = 0;
	Teacher* q = NULL;

	q = (Teacher*)malloc(sizeof(Teacher) * 3);
	if (q == NULL)
		return -3;
	for (i = 0; i < 3; i++)
	{
		(q + i)->name = (char*)malloc(sizeof(char) * 30);
		if ((q + i)->name == NULL)
			return -3;
		char ch[30] ;
		sprintf(ch, "lily %d", i);
		strcpy((q + i)->name, ch);
	}
	for (i = 0; i < 3; i++)
	{
		printf("%s , %p , %p \n", (q + i)->name,q+i,q[i] );
	}

	for (i = 0; i < 3; i++)
	{
		//free(q[i].name);
		free((*(q+i)).name);
		free(q[i].name=NULL);
	}
	free(q);
	q = NULL;

#pragma endregion Number3
	system("pause");
}