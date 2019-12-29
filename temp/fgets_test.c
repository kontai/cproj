/*
2019/12/08 19:22:11
fgets_test.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void main() {
	FILE* fp = fopen("../show.txt", "w");
	char* str[] = { "aaa","bbb","ccc" };
	int i=0;
	int len = 3;

	if (!fp)
	{
		perror("file can't open");
		return -1;
	}
	else if(ferror(fp))
	{
		perror("file is damaged");
		return -1;
	}

	for (i = 0; i < len; i++)
	{
		fputs(str[i], fp);
		fflush(fp);
		printf("%s", str[i]);
	}

	fclose(fp);


	system("pause");
}