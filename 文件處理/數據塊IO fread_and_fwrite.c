#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void mainWriteInt() {
	int ch[100];
	char path[20] = "c:\\�G�i��.txt";
	for (int i = 0;i < 100;i++)
	{
		ch[i] = i;
	}

	FILE *pt;
	pt = fopen(path, "wb");
	if(pt==NULL)
	{
		printf("���}�ҥ���");
	}
	else
	{

		printf("���}�Ҧ��\");
		int res=0;   //�x�s���g�J�ƶq
		res = fwrite(ch, sizeof(int), 100, pt);
		if(res!=100)
		{
			printf("error");
		}
		//fwrite
			//�Ĥ@�ӰѼ�:�ӷ��ƾڪ����a�}
			//�ĤG�ӰѼ�:�ƾګ��O�j�p
			//�ĤT�ӰѼ�:�ƶq
			//�ĥ|�ӰѼ�:�n�g�J���ؼФ��
		fclose(pt);
	}



	system("pause");
}

void mainReadInt() {
	int ch[100];
	char path[20] = "c:\\�G�i��.txt";
	FILE *pt;
	pt = fopen(path, "rb");
	if (pt == NULL) {
		printf("���}�ҥ���");
	}
	else {

		printf("���}�Ҧ��\");
		int res = 0;   //�x�s���g�J�ƶq
		res = fread(ch, sizeof(int), 100, pt);
		if (res != 100) {
			printf("error");
		}
		for (int i = 0;i < 100;i++) {

			printf("ch[%d]=%d\n", i, ch[i]);
		}
	}
	system("pause");
}