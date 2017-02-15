#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//ferror : 判斷文件處理執行狀態是否有誤
//perror : if error 印出錯誤狀態原因(如果有錯誤)
//clearerr : 清除錯誤狀態(如未清除.錯誤狀態會一直保持)
//
//文件長度:
//二進制文件:文件長度就是總字符長度
//
//windows 文本文件,會在每行末尾加上兩字符/r/n
//Linux  文本文件,會在末尾加上換行字符/n,並在文件結束加上一個結束字符EOF

void mainFerror() {
	char ch[20] = "c:\\ftext.txt";
	int num = 0;

	FILE *pfe = fopen(ch, "r");

	if (pfe == NULL) {
		printf("文件開啟失敗\n"); //當指針為空(文件開啟失敗),會觸發中斷點,須強制返回(return)
		//return;
	}
	else {
		printf("文件開啟成功\n");
	}

	if (!ferror(pfe)) {
		printf("執行成功\n");
	}
	else {
		printf("執行失敗\n");
	}

	fwrite("嘗試寫入文字", sizeof(wchar_t), 6, pfe);  //fopen Read mode 無法寫入
	//fputs("嘗試寫入文字", pfe);

	if (!ferror(pfe))   //ferror返回非0,表示產生錯誤(不使用ferror,錯誤並不提示)
	{
		printf("執行成功\n");
	}
	else {
		printf("執行失敗\n");
		perror("文件操作有問題歐.因為");  //perror 螢幕輸出錯誤訊息
		clearerr(pfe);		//清除文件失敗狀態(如未清除,接著的文處理狀態會保持錯誤!)
	}

	////  clearerr後 再試一次
	if (!ferror(pfe)) {
		printf("after clearerr,執行成功\n");
	}
	else {
		printf("after clearerr,執行失敗\n");
		perror("文件操作有問題歐.因為");
	}

	fclose(pfe);   //關閉文件(如文件指針為空(開啟失敗),也就不需要拉~

	system("pause");
}