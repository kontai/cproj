// �r��.cpp : �w�q�D���x���ε{�����i�J�I�C
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "�r�Ŧ�.h"

//initial string and string size
void init(tai_string *str)
{
	str->p = NULL;
	str->truestr = 0;
}


void init_strwid(tai_string *str, int len)
{
	str->p = (char*)calloc(str, strlen(str));
	str->truestr += strlen(str);
}
void init_strstr(tai_string *str, char *cpstr)
{
	str->p = (char*)calloc(str, strlen(cpstr));
	strcpy(str->p, cpstr);
	str->truestr += strlen(cpstr);
}

void print_str(tai_string *str)
{
	printf("String=%s\n", str->p);
	printf("Width=%d", str->truestr);
}
