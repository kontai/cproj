
/*
2018/09/08 14:16:11
多線程查找.c
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<Windows.h>
#include<time.h>

struct FindNum {
	int id;   //執行序
	int *pstart;	//執行起始位置
	int findNum;	//要尋找的數字
	int lenth;		//各執行序長度
	int row;		//行位置
};

void findFun(void*p) {
	struct FindNum *ini = (FindNum*)p;
	//printf("\n線程%d 開始查找....\n", ini->id);
	for (int *ps = ini->pstart; ps != ini->pstart + ini->lenth; ps++) {
		if (*ps == ini->findNum)
			printf("在第%d行,第%d列找到 %d\n", ini->row + 1, ps - ini->pstart + 1, ini->findNum);
	}
	//printf("\n線程%d 結束查找....\n", ini->id);

}

void mainFind() {

	int a[1000] = { 0 };
	time_t r_time;
	unsigned  int t_tmp = time(&r_time);
	srand(t_tmp);

	for (int i = 0; i < 1000; i++) {
		a[i] = rand() % 100;
		printf("%4d", a[i]);
		if ((i + 1) % 10 == 0)
			putchar('\n');
	}

	int val = 0, len = 0;
	printf("請輸入需要查找的數字=>");
	scanf("%d", &val);
	//printf("請輸入需要調用線程數=>");
	//scanf("%d", &len);

	struct FindNum fn[10];

	for (int i = 0; i < 10; i++) {
		fn[i].pstart = a + 100 * i;
		fn[i].id = i;
		fn[i].findNum = val;
		fn[i].lenth = 100;
		fn[i].row = i;
		HANDLE hdl = (HANDLE)_beginthread(findFun, 0, &fn[i]);
		//		WaitForSingleObject(hdl, INFINITE); 
	}



	system("pause");
}
