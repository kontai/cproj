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
	char* cur_ch = p1;		//��e�r��(�Ω���)
	char* newP = p1;		 //�Q�������w,�O�s���Y��r�Ŧ�C
	int len = 1;
	p++;		//�����e�@�B
	while (1)  //�M���r�Ŧ�
	{

		if (*cur_ch == *p)  //�۵�,���V�U�@�r��
		{
			len++;
			p++;
		}
		else
		{
			if (len > 1)  //���Ʀ���
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