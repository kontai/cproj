/*
2018/09/08 14:16:11
�h�u�{�d��.c
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<Windows.h>

struct FindNum {
	int id;   //�����
	int *pstart;	//����_�l��m
	int findNum;	//�n�M�䪺�Ʀr
	int lenth;		//�U����Ǫ���
	int row;		//���m
};

void findFun(void*p) {
	struct FindNum *ini = p;
	//printf("\n�u�{%d �}�l�d��....\n", ini->id);
	for (int *ps = ini->pstart; ps != ini->pstart + ini->lenth; ps++) {
		if (*ps == ini->findNum)
			printf("�b��%d��,��%d�C��� %d\n", ini->row + 1, ps - ini->pstart + 1, ini->findNum);
	}
	//printf("\n�u�{%d �����d��....\n", ini->id);

}

void main() {
	//�� �t�m�ʺA���s �s��Ʀr
	int ran_num = 0;
	printf("�п�J�n���ͦh�ּƦr=>");
	scanf("%d", &ran_num);
	int *num = malloc(sizeof(int)*ran_num);

	int  len = 0;

	printf("\n�п�J�ݭn�եνu�{��(CPU�֤߼�)=>");
	scanf("%d", &len);

	int proc_div = ran_num / (len - 1);  //����ǳB�z�ƶq (-1 �ΨӫO�s�ݾl�Ӽ�)
	int proc_mod = ran_num % len;	//(�ƶq/�֤߼�) �̫�ݾl�ƶq


	//�����H����
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

	printf("\n�п�J�ݭn�d�䪺�Ʀr=>");
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