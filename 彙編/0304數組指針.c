/*
2019/03/28 10:38:58
0304�Ʋի��w.c
*/

/*
1�B*() �P []�O�i�H�������A�]�N�O���G

*(*(p+1)+2) �۷�P p[1][2]

��*(p+1)[2] �O�_�@�w����p[1][2]�O�H �q�L�ϷJ�s�i����ҡC

2�B�ϥΰ}�C���йM���@�Ӥ@���}�C.

*/
#include<stdio.h>
#include<stdlib.h>

void main0304() {
	char arr[] = { 1,2,3,4,5,6,7,8,9 };
	char(*p)[2] = (char(*)[2])arr;
	char tmp = (*p)[2];
	//	printf("%d\n", tmp);
	tmp = (*(p+1))[2];
	printf("%d\n", tmp);
	tmp = *(*(p)+1);
	printf("%d\n", tmp);
	//	char tmp2 = p[1][2];

	system("pause");
}