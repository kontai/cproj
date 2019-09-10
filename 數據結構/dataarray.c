#define _CRT_SECURE_NO_WARNINGS

#include "dataarray.h"
#include "datastruct.h"
#include <string.h>

void init(struct DATAST* p)
{
	p->data = NULL;
	p->length = 0;
}

void initWithArray(struct DATAST* p, char* str)
{
	init(p);					//初始化
	int len = getline(str);		//行數
	int testLine = 0;
	p->data = malloc(sizeof(struct Data) * len);	//分配內存
	p->length = len;

	int allLeng = strlen(str);	//字符總數
//	for (char* p = str; p < str + strlen(str); p++)
//	{
//		if (*p == ' ')
//		{
//			*p = '\0';
//		}
//	}

	for (char* p = strstr(str, " "); p != NULL; p = strstr(p + 1, " "))
	{
		*p = '\0';
	}

	for (char* px = str; px < str + allLeng; px += strlen(px)+1 )
	{
		char* pnew = malloc(sizeof(char) * (strlen(px) + 1));
		strcpy(pnew, px);
		initWithString(p, pnew,testLine);
		testLine++;

//		printf("-%s-\n", pnew);
	}
/*
	for (int i = 0; i < testLine; i++)
	{
	printf("%lld<=====>%s\n",p->data[i].QQ,p->data[i].pstr);
	}
	*/
}

void showAll(struct DATAST* p)
{
	for (int i = 0; i < p->length; i++)
	{
		showData(p->data + i);
	}
		printf("\n\n");
}


void delAll(struct DATAST* p)
{
	for (int i = 0; i < p->length; i++)
	{
		free(p->data[i].pstr);
		p->data[i].pstr = NULL;
	}
	p->data = NULL;
	p->length = 0;
}


void FindQQ(struct DATAST* p, long long QQ)
{
	int flag = 0;
	for (int i = 0; i < p->length; i++)
	{
		if (QQ == p->data[i].QQ)
		{
			flag = 1;
			showData(p->data + i);
			break;
		}
	}

	if (!flag)
	{
		printf("沒找到\n");
	}
}
void FindQQAll(struct DATAST* p, long long QQ)
{
	int flag = 0;
	for (int i = 0; i < p->length; i++)
	{
		if (QQ == p->data[i].QQ)
		{
			flag = 1;
			showData(p->data + i);
		}
	}

	if (!flag)
	{
		printf("沒找到\n");
	}
}

void FindPass(struct DATAST* p, char* str)
{
	char* pfind = NULL;
	for (int i = 0; i < p->length; i++)
	{
		pfind = strstr(p->data[i].pstr, str);
		if (pfind != NULL)
		{
			showData(p->data + i);
			break;
		}
	}
	if (pfind == NULL)
	{
		printf("沒找到");
	}
}
void FindPassAll(struct DATAST* p, char* str)
{
	char* pfind = NULL;
	for (int i = 0; i < p->length; i++)
	{
		pfind = strstr(p->data[i].pstr, str);
		if (pfind != NULL)
		{
			showData(p->data + i);
		}
	}
	if (pfind == NULL)
	{
		printf("沒找到");
	}
}
