#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main2() {
	char path[40] = "c:\\w.txt";
	// 如果文件不存在,則會創建文件
	//如果文件存在,則文件長度清零,即該文件內容會消失
	//w模式 只能寫,不能讀
	//w+模式 既能寫,亦能讀
	//wb -讀取二進制文件
	//wt - 讀取一般文件
	FILE *pf = fopen(path, "w");
	if (pf == NULL) {
		printf("文件創見失敗");
	}
	else {
		printf("文件創建成功");

		char ch = fputs("test text", pf);
		fflush(pf);
		int res = fgetc(pf);
		printf("\n%d", res);
		fclose(pf);
	}

	system("pause");
}