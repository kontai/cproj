#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

union info {
	int prince;
	double db;
	char str[9];
}a, b;// c = { 12,2.3,"aee" };
//����b�w�q�@����ɪ�l��

void main() {
	a.prince = 2;
	strcpy(a.str, "abc");
	/*
	*�@����ؤo:�ھڦ�����,�r�`�Ƴ̤j��
	*����:�@����j�p�����]�t�̤j�����ƾ�,�åi�H �㰣�̤p�������ƾ�,����Q�̤p�����㰣 (�r�`���)
	*exp:int=4,char [9]=9;�N����R�줸	�N�ؤo��R�� 12 (��9/4 =>   12/4)
	*/

	printf("%d\n", sizeof(union info));
//�@����@����u��P�ɦs�b�@���ܫG
	//�@����--����u��ϥγ�Ӧ����ܼ�(�̫�s��)
	printf("%d,%s\n", a.prince, a.str);

	//�j�A����l�ƪ��ɭ�,�u���l�ƲĤ@��
	union info test = { 2 }; 

	union info *p = &test;
	printf("%d\n", p->prince);//   p->prince  �P����  (*p).prince 
	printf("%d\n", (*p).prince);

	system("pause");
}