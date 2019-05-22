/*
2018/11/04 15:49:08
str_reverse.c
*/

#include<stdio.h>
#include<stdlib.h>

void revStr(char[]);

void main() {
	char ch[] = "abcdefg";
	printf("%s\n", ch);
	revStr(ch);


	system("pause");
}

void revStr(char str[]) {
	static int i = 0;
	if (str[i] != '\0')
	{
		i++;
		revStr(str);
	}
	putchar(str[--i]);
}