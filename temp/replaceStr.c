/*
2019/10/27 16:41:17
replaceStr.c
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
str="1122ccabc2233ddabcd3344efabc"
sub="aaa"

*/

void replacement(char const* p, char* tmp, char* str, char const* new_str, int dest_len)
{
	char* start = p;
	int cnt = 0;  //總數
	char* alloc = NULL;

	while (alloc = strstr(start, str))
	{
		int len = (alloc - start) + 1;
		if ((dest_len -= len + strlen(new_str) + 1) > 0)
		{
			strncat(tmp, start, len);
			strcat(tmp, new_str);  //strstr會自動在結尾添加結束符'\0'
			start += len;
			cnt++;
			alloc = strstr(start, str);
		}
		else
		{
			printf("目標沒空間存放!\n");
			return -1;
		}
	}

	if (cnt == 0)
	{
		printf("找不到%s字串\n", new_str);
		return;
	}
}

void replacementP(char const* p, char** bak, char* str, char const* new_str)
{
	char* start = p;
	int cnt = 0;  //總數
	char* alloc = NULL;
	char tmp[512] = { 0 };

	while (alloc = strstr(start, str))
	{
		int len = (alloc - start) + 1;
		strncat(tmp, start, len);
		strcat(tmp, new_str);  		
		start += len;
		cnt++;
		alloc = strstr(start, str);
	}

	if (cnt == 0)
	{
		printf("找不到%s字串\n", new_str);
		return;
	}
	*bak = (char*)malloc(strlen(tmp) + 1);
	strcpy(*bak, tmp);
}

void freeP(char* p)
{
	if (p != NULL)
		free(p);
}

void mainRep() {
	char* str = "1122ccabc2233ddabcd3344efabc";
	char* new_sub = "aaaaa";
	
	char bak[510] = { 0 };
	int dest_len = sizeof(bak) / sizeof(*bak);
	//replacement(str, bak, "abc", new_sub, dest_len);
	//printf("%s\n", bak);

	char* tmp = NULL;
	replacementP(str, &tmp, "abc", new_sub);
	printf("%s\n", tmp);

	freeP(tmp);

	tmp = NULL;

	system("pause");
	exit(0);
}