#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

union info
{
	int prince;
	double db;
	char str[9];
}a,b,c;

void main()
{
	a.prince = 2;
	strcpy(a.str, "abc");

//�@����ؤo:�ھڦ�����,�r�`�Ƴ̤j��

//�e��:����Q�̤p�����㰣 (�r�`���)
//exp:int=4,char [9]=9;�N����R�줸	�N�ؤo��R�� 12 (��9/4 =>   12/4)

	printf("%d\n", sizeof(union info)); 

	//�@����--����u��ϥγ�Ӧ����ܼ�(�̫�w�q��)
	printf("%d,%s", a.prince, a.str); 

	system("pause");
}

