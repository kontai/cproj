#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//fprintf fscanf      ���ݭn�g�r�Ŧ����,�ഫ

void mainfp() {
	char ch[30] = "c:\\ftext.txt";

	FILE *pf;
	pf = fopen(ch, "w");
	if (pf == NULL) {
		printf("���}�ҥ���");
	}
	else {
		for (int i = 0;i < 10;i++) {
			fprintf(pf, "%s!\n%d\n", "�g�J��󦨥\", i);
		}
	}
	fclose(pf);

	system("pause");
}

void mainfs() {
	char ch[30] = { 0 };
	int num = 0;

	FILE *ps;
	ps = fopen("c:\\ftext.txt", "r");

	if (ps == NULL) {
		printf("���}�ҥ���");
	}
	else {
		while (!feof(ps)) {
			fscanf(ps, "%s %d", ch, &num);
			printf("%s  num=%d\n", ch, num);
		}
	}
	fclose(ps);

	system("pause");
}