/*
2019/12/15 8:41:11
fread and fwrite.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef struct Stu
{
	char name[30];
	int id;
}Stu;

void my_fprintf(Stu stu[3], char* path)
{
	FILE* fp = NULL;
	int i = 0;
	//讀寫方式打開，如果文件不存在，打開失敗。
	fp = fopen(path, "w+");
	if (fp == NULL)
	{
		perror("my_fwrite error");
		return;
	}

	for (i = 0; i < 3; i++)
	{
		fprintf(fp, "%s\n", stu[i].name);
	}

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}
void my_fscanf(char* path)
{
	FILE* fp = NULL;
	Stu s[3];

	int i = 0;
	int a, b, c;

	//讀寫方式打開，如果文件不存在，打開失敗。
	fp = fopen(path, "r+");
	if (fp == NULL)
	{
		perror("my_fread error");
		return;
	}
	for (i = 0; i < 3; i++)
	{
		fscanf(fp,"stu%c%c%c\n",&a,&b,&c);
		printf("a=%c,b=%c,c=%c\n", a, b, c);
	}


	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void main() {
	Stu stu[3];
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		char str[30] = { 0 };
		sprintf(str, "stu%c%c%c", i + '0', i + '0', i + '0');
		strcpy(stu[i].name, str);
		stu[i].id = i + 1;
	}

	my_fprintf(stu, "./06.txt");
	my_fscanf("./06.txt");

	system("pause");
}