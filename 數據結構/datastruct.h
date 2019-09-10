#ifndef __ARRLIST_H
#define __ARRLIST_H
#include<stdio.h>

struct Data
{
	long long QQ;
	char* pstr;
	unsigned char length;
};

void initWithString(struct DATAST* data, char* str);
void showData(struct Data* p);
#endif