#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main2() {
	char path[40] = "c:\\w.txt";
	// �p�G��󤣦s�b,�h�|�Ыؤ��
	//�p�G���s�b,�h�����ײM�s,�Y�Ӥ�󤺮e�|����
	//w�Ҧ� �u��g,����Ū
	//w+�Ҧ� �J��g,���Ū
	//wb -Ū���G�i����
	//wt - Ū���@����
	FILE *pf = fopen(path, "w");
	if (pf == NULL) {
		printf("���Ш�����");
	}
	else {
		printf("���Ыئ��\");

		char ch = fputs("test text", pf);
		fflush(pf);
		int res = fgetc(pf);
		printf("\n%d", res);
		fclose(pf);
	}

	system("pause");
}