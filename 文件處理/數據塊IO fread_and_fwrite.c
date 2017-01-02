#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void mainWriteInt() {
	int ch[100];
	char path[20] = "c:\\秈.txt";
	for (int i = 0;i < 100;i++)
	{
		ch[i] = i;
	}

	FILE *pt;
	pt = fopen(path, "wb");
	if(pt==NULL)
	{
		printf("ゅン秨币ア毖");
	}
	else
	{

		printf("ゅン秨币Θ");
		int res=0;   //纗ゅン糶计秖
		res = fwrite(ch, sizeof(int), 100, pt);
		if(res!=100)
		{
			printf("error");
		}
		//fwrite
			//材把计:ㄓ方计沮
			//材把计:计沮
			//材把计:计秖
			//材把计:璶糶ヘ夹ゅン
		fclose(pt);
	}



	system("pause");
}

void mainReadInt() {
	int ch[100];
	char path[20] = "c:\\秈.txt";
	FILE *pt;
	pt = fopen(path, "rb");
	if (pt == NULL) {
		printf("ゅン秨币ア毖");
	}
	else {

		printf("ゅン秨币Θ");
		int res = 0;   //纗ゅン糶计秖
		res = fread(ch, sizeof(int), 100, pt);
		if (res != 100) {
			printf("error");
		}
		for (int i = 0;i < 100;i++) {

			printf("ch[%d]=%d\n", i, ch[i]);
		}
	}
	system("pause");
}