/*
2018/11/10 14:47:41
���w�Ʋ�.c
*/

#include<stdio.h>
#include<stdlib.h>

void main3(){
	int num = 10;
	int a[10];
	//int b[num];  //�̤W�ʺA�Ʋ�.gcc�~�A��
	//a = (int[12]) { 0 };a�O�`�q

	int(*p)[10]; //�ʺA���t���s,�t�Τ��|�۰ʦ^���Ŷ�
	int *pc = (int[]) { [1] = 34 }; //pc�O�ܶq,��sĶ�ɴ̤W�R�A���t���s,
	pc = (int[20]) { 0 };  //���s�ᤩ�Ʋ�,�ª����s�Ŷ��N���i�A�ϥ�

	int (*p2)[4] = (int[][4]) { 0 };
	int (*p3)[][4] = (int[][4]) { 0 };


	system("pause");
}