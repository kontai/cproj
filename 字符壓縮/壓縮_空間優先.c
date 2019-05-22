/*
2019/05/05 10:11:41
zip_unzip.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* szip(char* p)
{
	char* p1 = p;			//orginal string (temp)
	char* cur_ch = p1;		//讽玡才(ノゑ耕)
	char* newP = p1;		 //ノ蛮皐,玂溃罽才﹃
	int len = 1;
	p++;		//┕玡˙
	while (1)  //筂菌才﹃
	{

		if (*cur_ch == *p)  //单,才
		{
			len++;
			p++;
		}
		else
		{
			if (len > 1)  //狡Ω计
			{
				*p1++ = len + '0';
				*p1++ = *cur_ch;
				cur_ch = cur_ch + len ;
				len = 1;
			}
			else
			{
				*p1++ = *cur_ch;
				cur_ch++;
			}
			p++;
		}
		if (*(p - 1) == '\0')
			break;

	}
	*p1 = '\0';

	return newP;
}

char* sunzip(char* str)
{
}


void main() {

	char str[1024] = "aaaabbbbcdefffgghhhhhhhhhiiiiiii";			//4a4bcde3f2g10h
	printf("%s\n", str);
	char* abc = szip(str);
	printf("%s\n", abc);
	//	printf("%s\n", sunzip(abc));


	system("pause");
}