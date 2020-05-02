/*
2020/03/21 19:05:03
Pointer01.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <cassert>
#include<string.h>
#include<memory.h>

#if 0
int trimSpace(char* inbuf, char* outbuf)
{
	int i = 0, j = 0;
	int count = 0;
	char* tmp = outbuf;
	char* dest = (char*)malloc(sizeof(char) * 1024);
	//printf("dest所申請位置=%p\n", dest);
	if (dest == NULL)
	{
		perror("pointer initialize fail!");
		return -1;
	}

	memset(dest, '\0', 1023);

	for (i = 0, j = 0; *(tmp + i) != '\0'; i++)
	{
		if (*(tmp + i) != ' ')
		{
			*(dest + j) = *(tmp + i);
			j++, count++;
		}
	}

	strcpy(inbuf, dest);
	free(dest);
	if (count)
	{
		return count;
	}
	else
	{
		assert(!"The method or operation is not implemented.");
		return -1;
	}
}

void main() {
	char outbuf[1024] = { "   abcdefgddd      " };
	char inbuf[1024] = { 0 };
	//printf("In main...%p\n", inbuf);
	int count = trimSpace(inbuf, outbuf);
	if (count == -1)
	{
		printf("無空白格\n");
	}
	else
		printf("共有%d個空白被移除!\n", count);
	printf("%s\n", inbuf);

	system("pause");
}

#endif 0