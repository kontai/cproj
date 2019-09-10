#ifndef __DATAARRAY_H
#define __DATAARRAY_H

#include<stdio.h>
#include<stdlib.h>

struct DATAST
{
	struct Data* data;
	int length;
};

void init(struct DATAST* p);
void initWithArray(struct DATAST* p, char* str);
void showAll(struct DATAST* p);
void delAll(struct DATAST* p);
void FindQQ(struct DATAST* p, long long QQ);
void FindQQAll(struct DATAST* p, long long QQ);
void FindPass(struct DATAST* p, char* str);
void FindPassAll(struct DATAST* p, char* str);

#endif
