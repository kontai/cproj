/*
2019/05/05 10:11:41
zip_unzip.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* zip(char* p)
{
	int length = strlen(p);
	char* curp = p;
	char* new_p = calloc(length + 1, 1);
	int str_rep = 0;
	char* newp = new_p;
	while (*curp != '\0')
	{
		if (*curp == *(curp + 1))
		{
			curp++;
			str_rep += 1;
		}
		else
		{
			if (str_rep != 0)
			{
				*newp += str_rep+'0' ;
				*++newp += *curp;
				str_rep = 0;
			}
			else
				*newp = *curp;
		curp++;
		newp++;
		}
	}
	length = strlen(new_p);
	new_p = _recalloc(new_p, length + 1,1);
	
	return new_p;
}

char* unzip(char* str)
{
	char* new_p = calloc(1000, 1);
	char* newp = new_p;
	char* cur = str;

	while (*cur != '\0')
	{
		if (*cur - '0' > 0 && *cur - '0' <= 9)
		{
			int len = *cur - '0'+1;
			char temp = *++cur;
			for (int i = 0; i < len; i++)
			{
				*newp++ += temp;
			}
		}
		else
				*newp++ = *cur++;
	}
		int length = strlen(new_p) ;
		new_p = _recalloc(new_p, length+1, 1);
		return new_p;
}



void main_times() {

	char str[1024] = "aaaabbbbcdefffgghhhhhhhhhh";			//4a4bcde3f2g10h
	printf("%s\n", str);
	char* abc = zip(str);
	printf("%s\n", abc);
	printf("%s\n", unzip(abc));


	system("pause");
}