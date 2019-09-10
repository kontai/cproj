#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<memory.h>
#include<string.h>

struct stringA
{
	char* p;
	int memlen;
};

struct stringW
{
	wchar_t * p;
	int memlen;
};


typedef struct stringA stringa;
typedef struct stringW stringw;

void init(void* p, char ch);	//ch=a (char)   ch=w (wchar_t)
void initwithstring(void* p, char ch, const void* pstr);
void show(const void* p, char ch);
