#define _CRT_SECURE_NO_WARNINGS //關閉安全檢查
#include<stdio.h>
#include <stdlib.h>

void mainRewind() {
	FILE *pf;
	pf = fopen("d:\\1.txt", "r");
	if (pf == NULL) {
		printf("文件讀取失敗");
	}
	else {
		while (!feof(pf)) {			//判斷文件是否讀取結束
			char ch = fgetc(pf);   //讀取字符
			putchar(ch);
		}
	}
	//此時文件指針已到結尾
    //rewind 將文件位置指針回到文件開頭,才可再繼續讀取//

	rewind(pf);

	char str[100] = { 0 };
	while ((fgets(str, 100, pf)) != NULL) {
		printf("%s", str);
	}
		

	fclose(pf);

	system("pause");
}