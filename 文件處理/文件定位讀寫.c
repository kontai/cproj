#define _CRT_SECURE_NO_WARNINGS //�����w���ˬd
#include<stdio.h>
#include <stdlib.h>

void mainRewind() {
	FILE *pf;
	pf = fopen("d:\\1.txt", "r");
	if (pf == NULL) {
		printf("���Ū������");
	}
	else {
		while (!feof(pf)) {			//�P�_���O�_Ū������
			char ch = fgetc(pf);   //Ū���r��
			putchar(ch);
		}
	}
	//���ɤ����w�w�쵲��
    //rewind �N����m���w�^����}�Y,�~�i�A�~��Ū��//

	rewind(pf);

	char str[100] = { 0 };
	while ((fgets(str, 100, pf)) != NULL) {
		printf("%s", str);
	}
		

	fclose(pf);

	system("pause");
}