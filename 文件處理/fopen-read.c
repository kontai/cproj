#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//r模式,該文件必須存在,不存在-打開失敗
//r模式 只能寫,不能寫
//r+模式 既能寫,亦能讀
//rb - 寫入二進制文件
//rt - 寫入一般文件
void main1() {
	char path[40] = "c:\\X.txt";
	FILE *pf = fopen(path, "r");
	if (pf == NULL) {
		printf("the file not available");
	}
	else {
		printf("%s\n", path);
		while (!feof(pf))	//判斷文件是否讀取完畢
		{
			char ch = fgetc(pf);  //從文件讀取一個字符,保存到ch
			putchar(ch);
		}
		int res = fputc('A', pf); //寫入可正常編譯,但是寫入會失敗
		printf("%d", res);

		fclose(pf);
	}

	system("pause");
}