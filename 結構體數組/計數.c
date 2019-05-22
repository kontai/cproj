/*
2019/05/19 13:45:41
計數.c
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct csdn {
	int id;
	int num;
};

void main(){
	int num;
	scanf("%d", &num);

	struct csdn* p1 = malloc(num * sizeof(struct csdn));  //堆上
	struct csdn* p2 = alloca(num * sizeof(struct csdn));  //棧上
	
	memset(p1, 0, sizeof(struct csdn)*num);
	memset(p2, 0, sizeof(struct csdn)*num);

	for (int i = 0; i < num; i++)
	{
		p1[i].id = i;
		p2[i].id = i;
		printf("%d,%d\t%d,%d\n", p1[i].id, p1[i].num, p2[i].id, p2[i].num);
	}
	for (int i = 0; i < 10; i++)
	{
		int id;
		scanf("%d", &id);
		for (int j = 0; j < num; j++)
		{
if (p1[j].id==id)
{
	p1[j].num++;
	p2[j].num++;
	break;
}
		}
	}

	for (int i = 0; i < num; i++)
	{
		printf("%d,%d\t%d,%d\n", p1[i].id, p1[i].num, p2[i].id, p2[i].num);
	}


	free(p1);
	system("pause");
}