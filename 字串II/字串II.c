#define _CRT_SECURE_NO_WARNINGS
// �r��II.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int str_len(char *);
void str_copy(char *,char*); //�ƻs�r��
void str_cat(char*, char*);//�ƻs�r��ܥt�@�r��r��


void main()
{
	char a[18] = "dark black";
	char b[10] = "rev 2.0";
	char c[30];
	printf("size of array a=%d\n", str_len(a));
	printf("size of array b=%d\n", str_len(b));
	str_copy(c, a);
	printf("%s\n", c);
	str_cat(c, b);
	printf("%s", c);






	system("pause");
}
int  str_len(char *str)
{
	int len=0;
	while(*str)
	{
		len++;
		str++;
	}
	return len;


}

void str_copy(char *dest,char *source)
{

	if(dest == NULL||source==NULL)
	{
		return ;
	}
	while(*source)
	{
		*dest++ = *source++;
	}
	dest[0] = '\0';

}

void str_cat(char *dest,char*source)
{
	if(dest == NULL||source==NULL)
	{
		return ;
	}

	int len = str_len(dest);

	/*
	if (len + str_len(source) > sizeof(dest)) {
		(char*)realloc(dest,  len + str_len(source)-sizeof(dest) );
		dest += len;
	}
	else
		dest += len;

*/
		dest += len;
	for (;*source;)
{
		*dest = *source;
		dest++, source++;
}
	*dest = '\0';


}