/*
2018/09/08 14:16:11
多線程查找.c
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<Windows.h>

struct FindNum {
	int id;   //執行序
	int *pstart;	//執行起始位置
	int findNum;	//要尋找的數字
	int lenth;		//各執行序長度
	int row;		//行位置
};

void findFun(void*p) {
	struct FindNum *ini = p;
	//printf("\n線程%d 開始查找....\n", ini->id);
	for (int *ps = ini->pstart; ps != ini->pstart + ini->lenth; ps++) {
		if (*ps == ini->findNum)
			printf("在第%d行,第%d列找到 %d\n", ini->row + 1, ps - ini->pstart + 1, ini->findNum);
	}
	//printf("\n線程%d 結束查找....\n", ini->id);

}

void main() {
	//堆 配置動態內存 存放數字
	int ran_num = 0;
	printf("請輸入要產生多少數字=>");
	scanf("%d", &ran_num);
	int *num = malloc(sizeof(int)*ran_num);

	int  len = 0;

	printf("\n請輸入需要調用線程數(CPU核心數)=>");
	scanf("%d", &len);

	int proc_div = ran_num / (len - 1);  //執行序處理數量 (-1 用來保存殘餘個數)
	int proc_mod = ran_num % len;	//(數量/核心數) 最後殘餘數量


	//產生隨機數
	time_t r_time;
	unsigned  int t_tmp = time(&r_time);
	srand(t_tmp);

	for (int i = 0; i < ran_num; i++) {
		*(num + i) = malloc(sizeof(int));
		*(num + i) = rand() % 100;

		printf("%4d", *(num+i));
		if ((i + 1) % proc_div == 0)
			putchar('\n');
	}

	int val = 0;

	printf("\n請輸入需要查找的數字=>");
	scanf("%d", &val);
		struct FindNum fn[10];


	for (int i = 0; i < len; i++) {
		fn[i].pstart = num + proc_div * i;
		fn[i].id = i;
		fn[i].findNum = val;
		fn[i].row = i;

		if (i == len - 1)
			fn[i].lenth = proc_mod;
		else
			fn[i].lenth = proc_div;

		 _beginthread(findFun, 0, &fn[i]);
		//HANDLE hdl = _beginthread(findFun, 0, &fn[i]);
		//		WaitForSingleObject(hdl, INFINITE); 
	}



	system("pause");
}