#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<locale.h>


int count(FILE* );

void mainu()
{
	FILE *pf;
	pf = fopen("d:\\1.txt", "r");

	printf("total %d character\n", count(pf));  //ftell=>FILE pointer at begin

	if (pf == NULL) {
		printf("文件讀取失敗");
	}
	else {
		while (!feof(pf)) {			//判斷文件是否讀取結束
			wchar_t ch =  fgetc(pf);   //讀取字符
			if(ch=='8')
			{
			printf("\n找到'8',在第%d個字的位置\n", ftell(pf)); //利用ftell 尋找文件中字符
			}
			 putchar(ch);
		}

	}

	printf("*************************\n");

	printf("total %d character\n", count(pf));  //ftell=>FILE pointer at end of file 

	printf("*************************\n");

	fclose(pf);
	system("pause");
}

int count(FILE* cnt)
{
	return ftell(cnt);    //ftell 返回目前為止(檔案指標所指位置)字符數
}