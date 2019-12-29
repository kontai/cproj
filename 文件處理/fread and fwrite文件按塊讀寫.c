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

void my_fwrite(Stu stu[3],char* path)
{
	FILE* fp = NULL;

	//返回值
	int ret = 0;

	//讀寫方式打開，如果文件不存在，打開失敗。
	fp = fopen(path, "wb+");
	if (fp == NULL)
	{
		perror("my_fwrite error");
		return;
	}
	//按塊方式寫文件
	//stu:寫入文件內容的內存首地址
	//sizeof(Stu):塊數據的大小(以Stu數據大小寫入)
	//3:塊數 ;  寫入文件數據的大小=sizeof(Stu)*3，
	//fp:文件指針
	//返回值:成功寫入文件的塊數目
	ret=fwrite(stu, sizeof(Stu), 3, fp);
	printf("ret=%d\n", ret);

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}
void my_fread(char* path)
{
	FILE* fp = NULL;
	Stu s[3];

	//返回值
	int ret = 0;
	int i = 0;

	//讀寫方式打開，如果文件不存在，打開失敗。
	fp = fopen(path, "rb+");
	if (fp == NULL)
	{
		perror("my_fread error");
		return;
	}

	//按塊方式讀文件
	//stu:讀取文件內容的內存首地址
	//sizeof(Stu):塊數據的大小
	//3:塊數 ;  讀取文件數據的大小=sizeof(Stu)*3，
	//fp:文件指針
	//返回值:成功讀取文件的塊數目
	ret=fread(s, sizeof(Stu), 3, fp);

	for (i = 0; i < 3; i++)
	{
		printf("s=%s,%d\n", s[i].name, s[i].id);
	}
	
	printf("ret=%d\n", ret);

	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
}

void main_frw() {
	Stu stu[3];
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		char str[30] = { 0 };
		sprintf(str, "stu%c%c%c", i+'0', i+'0', i+'0' );
		strcpy(stu[i].name, str);
		stu[i].id = i+1;
	}

	my_fwrite(stu,"./05.txt");
	my_fread("./05.txt");


	system("pause");
}