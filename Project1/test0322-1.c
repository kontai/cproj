/*
2020/03/22 15:53:59
test0322-1.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


#if 0


#define LEN 10

int show(char(*ch)[LEN], int count)
{
	for (int i = 0; i < 30; i++)
	{
		if (*(*ch + i) == '\0')
		{
			count = i;
			break;
		}
		//printf("%c ", *(*ch + i));
		printf("%c ", *(*(ch + i / 10) + i % 10));
		if ((i + 1) % 10 == 0)
			putchar('\n');
	}
	putchar('\n');

	printf("count=%d\n", count);
	return count;
}

const int  p = 101;

void main() {

	char ch[3][10];
	for (int i = 0; i < 30; i++)
	{
		if (i > 25)
		{
			ch[i / 10][i % 10] = 0;
			continue;
		}
		ch[i / 10][i % 10] = 'a' + i;
	}

	printf("ch size=%d , ch address= %p,ch+1=%c \n", sizeof(ch), ch, ch[2][6]);
	int count = 0;
	count=show(ch, count);
	

	system("pause");
}


#endif
