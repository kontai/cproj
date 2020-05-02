/*
2020/04/26 17:54:38
count.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int recurse(int);

void main() {
	unsigned long long int a = 1000L;
	printf("%ld\n",recurse(a));


	system("pause");
}

int recurse(int num)
{
	if (num > 0)
	{
		return num + recurse(num - 1);
	}
	else
		return num;
}