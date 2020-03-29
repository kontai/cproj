/*
2019/11/09 9:58:02
c提高day04作業.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

//字符比較(大則返回1,小則返回-1)
int Mystrcmp(const char* a, const char* b)
{
	int i = 0;
	while ((*a + i) != '\0' || (*b + i) != '\0')
	{
		printf("%c %c ", (*a + i), (*b + i));
		if (*a + i > * b + i)
			return 1;
		if (*a + i < *b + i)
			return -1;

		i++;
	}
	return -1;
}

int sort(char** array1, int num1, char(*array2)[30], int num2, char*** myp3 /*out*/, int* num3)
{
	int i = 0;
	int j = 0;

	int lenth = num1 + num2;

	//動態申請內存 (*buf)[30]==buf[6][30])
	char** buf = (char**)malloc(sizeof(char*) * (lenth));
	if (buf == NULL)
	{
		printf("*buf malloc fail");
		return -1;
	}

	for (i = 0; i < lenth; i++)
	{
		if (i < num2)
		{
			buf[i] = (char*)malloc(sizeof(char) * (strlen(*(array1 + i)) + 1));
			if ((buf + i) == NULL)
			{
				printf("*buf malloc fail");
				return -1;
			}
			strcpy(*(buf + i), *(array1 + i));
			//printf("%s\n", *(buf + i));
		}
		else
		{
			buf[i] = (char*)malloc(sizeof(char) * (strlen(*(array2 + i - 3)) + 1));
			if ((buf + i) == NULL)
			{
				printf("*buf malloc fail");
				return -1;
			}
			strcpy(*(buf + i), *(array2 + i - 3));
			//printf("%s\n", *(buf + i));
		}
	}

	/* important */
	for (i = 0; i < lenth - 1; i++)
	{
		for (j = 1; i + j < lenth; j++)
		{
			//printf("%s , %s\n", *(buf + i) , *(buf + i + j));
			if (Mystrcmp(*(buf + i), *(buf + i + j)) > 0)
			{
				char* tmp = *(buf + i);
				*(buf + i) = *(buf + i + j);
				*(buf + i + j) = tmp;
			}
			printf("%s , %s\n", *(buf + i), *(buf + i + j));
		}
	}
	/*
	for (i = 0; i < 6; i++)
	{
		printf("%s\n", *(buf + i));
	}
*/
	*myp3 = buf;
	*num3 = lenth;

	return 0;
}

void free_buf(char*** p3, int len)
{
	if (p3 == NULL)
		return;

	char** tmp = *p3;
	int i = 0;
	for (i = 0; i < len; i++)
	{
		if (tmp[i] != NULL)
		{
			free(tmp[i]);
			tmp[i] = NULL;
		}
	}

	if (tmp != NULL)
	{
		free(tmp);
		*p3 = NULL;
	}
}

void main() {
	int ret = 0;
	char* p1[] = { "aa","ccccccc","bbbbbb" };
	char buf2[10][30] = { "111111","3333333","222222" };
	char** p3 = NULL;
	int len1, len2, len3, i = 0;

	len1 = sizeof(p1) / sizeof(*p1);
	len2 = 3;

	ret = sort(p1, len1, buf2, len2, &p3, &len3);
	if (ret != 0)
	{
		printf("Error!");
		exit(-1);
	}

	for (i = 0; i < len3; i++)
	{
		printf("%s\n", *(p3 + i));
	}

	for (i = 0; i < len3; i++)
	{
		if (*(p3 + i) != NULL)
			free(*(p3 + i));
	}

	if (p3 != NULL)
		free(p3);
	system("pause");
}