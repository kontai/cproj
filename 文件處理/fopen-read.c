#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//r�Ҧ�,�Ӥ�󥲶��s�b,���s�b-���}����
//r�Ҧ� �u��g,����g
//r+�Ҧ� �J��g,���Ū
//rb - �g�J�G�i����
//rt - �g�J�@����
void main1() {
	char path[40] = "c:\\X.txt";
	FILE *pf = fopen(path, "r");
	if (pf == NULL) {
		printf("the file not available");
	}
	else {
		printf("%s\n", path);
		while (!feof(pf))	//�P�_���O�_Ū������
		{
			char ch = fgetc(pf);  //�q���Ū���@�Ӧr��,�O�s��ch
			putchar(ch);
		}
		int res = fputc('A', pf); //�g�J�i���`�sĶ,���O�g�J�|����
		printf("%d", res);

		fclose(pf);
	}

	system("pause");
}