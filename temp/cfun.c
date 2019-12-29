/*
2019/10/20 17:46:07
cfun.c
*/

#if 0

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

void **getmem(int len) {
	int n = 5,i=0;
	char** obj = NULL;
	obj = (char**)malloc(len * sizeof(char*));
	if (obj == NULL)
		return -1;


	for (; i < len; i++) {
		*(obj + i) = (char*)malloc(n * sizeof(char));
		if (*(obj + i) == NULL)
			return -1;
		char a = 'a' + i;
		char b[5] = { 0 };
		for (int j = 0; j < 4; j++)
			b[j] = a;
		b[4] = 0;
		strcpy(*(obj + i), b);
	}
	for (int k = 0; k < len; k++)
		printf("%p,%s\n", obj + k,*(obj+k));
	return obj;
}
void getmemB(char ***obj,int len) {
	int n = 5,i=0;

	for (; i < len; i++) {
		*(obj + i) = (char*)malloc(n * sizeof(char));
		if (*(obj + i) == NULL)
			return -1;
		char a = 'a' + i;
		char b[5] = { 0 };
		for (int j = 0; j < 4; j++)
			b[j] = a;
		b[4] = 0;
		strcpy(*(obj + i), b);
	}
	for (int k = 0; k < len; k++)
		printf("%p,%s\n", obj + k,*(obj+k));
}

void mainCfun(){
	int len = 3;
	char** a=getmem(len);
	char*b1[3] ;
	getmemB(&b1, len);
	putchar('\n');
	/*
	for (int i = 0; i < len; i++)
		printf("%s\n", *(a + i));
	*/

	system("pause");
}

#endif