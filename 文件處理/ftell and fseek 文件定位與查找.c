#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int count(FILE* );

void mainFtell()
{
	FILE *pf;
	pf = fopen("d:\\1.txt", "r");

	printf("total %d character\n", count(pf));  //ftell=>FILE pointer at begin

	if (pf == NULL) {
		printf("���Ū������");
	}
	else {
		while (!feof(pf)) {			//�P�_���O�_Ū������
			char ch = fgetc(pf);   //Ū���r��
			if(ch=='8')
			{
			printf("\n���'8',�b��%d�Ӧr����m\n", ftell(pf)); //�Q��ftell �M���󤤦r��
			}
			putchar(ch);
		}

	}

	printf("*************************\n");

	printf("total %d character\n", count(pf));  //ftell=>FILE pointer at end of file 

	printf("*************************\n");

	fclose(pf);
	system("pause");
}

int count(FILE* cnt)
{
	return ftell(cnt);    //ftell ��^�ثe����(�ɮ׫��Щҫ���m)�r�ż�
}