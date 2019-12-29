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

	//��^��
	int ret = 0;

	//Ū�g�覡���}�A�p�G��󤣦s�b�A���}���ѡC
	fp = fopen(path, "wb+");
	if (fp == NULL)
	{
		perror("my_fwrite error");
		return;
	}
	//�����覡�g���
	//stu:�g�J��󤺮e�����s���a�}
	//sizeof(Stu):���ƾڪ��j�p(�HStu�ƾڤj�p�g�J)
	//3:���� ;  �g�J���ƾڪ��j�p=sizeof(Stu)*3�A
	//fp:�����w
	//��^��:���\�g�J��󪺶��ƥ�
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

	//��^��
	int ret = 0;
	int i = 0;

	//Ū�g�覡���}�A�p�G��󤣦s�b�A���}���ѡC
	fp = fopen(path, "rb+");
	if (fp == NULL)
	{
		perror("my_fread error");
		return;
	}

	//�����覡Ū���
	//stu:Ū����󤺮e�����s���a�}
	//sizeof(Stu):���ƾڪ��j�p
	//3:���� ;  Ū�����ƾڪ��j�p=sizeof(Stu)*3�A
	//fp:�����w
	//��^��:���\Ū����󪺶��ƥ�
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