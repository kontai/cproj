
/*
2018/09/08 14:16:11
�h�u�{�d��.c
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<Windows.h>
#include<time.h>

struct FindNum {
	int id;   //�����
	int *pstart;	//����_�l��m
	int findNum;	//�n�M�䪺�Ʀr
	int lenth;		//�U����Ǫ���
	int row;		//���m
};

void findFun(void*p) {
	struct FindNum *ini = (FindNum*)p;
	//printf("\n�u�{%d �}�l�d��....\n", ini->id);
	for (int *ps = ini->pstart; ps != ini->pstart + ini->lenth; ps++) {
		if (*ps == ini->findNum)
			printf("�b��%d��,��%d�C��� %d\n", ini->row + 1, ps - ini->pstart + 1, ini->findNum);
	}
	//printf("\n�u�{%d �����d��....\n", ini->id);

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
	printf("�п�J�ݭn�d�䪺�Ʀr=>");
	scanf("%d", &val);
	//printf("�п�J�ݭn�եνu�{��=>");
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
