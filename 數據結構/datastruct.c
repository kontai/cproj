#define _CRT_SECURE_NO_WARNINGS
#include"datastruct.h"
#include"dataarray.h"
#include<string.h>

void initWithString(struct DATAST* p, char* str,int len)
{
	struct Data* pdata = &p->data[len];
	char* ch = strstr(str, "----");
	*ch = '\0';
	pdata->length = strlen(ch + 4);
	sscanf(str, "%lld", &pdata->QQ);

	pdata->pstr = malloc(sizeof(char) * (pdata->length + 1));
	if (pdata->pstr == NULL)
		printf("error\n");
	strcpy(pdata->pstr, ch + 4);
//	printf("%lld<=====>%s\n",pdata->QQ, pdata->pstr);
}


void showData(struct Data* p)
{
		printf("%lld -- %s\n", p->QQ, p->pstr);
}
