#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//ferror : �P�_���B�z���檬�A�O�_���~
//perror : if error �L�X���~���A��](�p�G�����~)
//clearerr : �M�����~���A(�p���M��.���~���A�|�@���O��)
//
//������:
//�G�i����:�����״N�O�`�r�Ū���
//
//windows �奻���,�|�b�C�楽���[�W��r��/r/n
//Linux  �奻���,�|�b�����[�W����r��/n,�æb��󵲧��[�W�@�ӵ����r��EOF

void mainFerror() {
	char ch[20] = "c:\\ftext.txt";
	int num = 0;

	FILE *pfe = fopen(ch, "r");

	if (pfe == NULL) {
		printf("���}�ҥ���\n"); //����w����(���}�ҥ���),�|Ĳ�o���_�I,���j���^(return)
		//return;
	}
	else {
		printf("���}�Ҧ��\\n");
	}

	if (!ferror(pfe)) {
		printf("���榨�\\n");
	}
	else {
		printf("���楢��\n");
	}

	fwrite("���ռg�J��r", sizeof(wchar_t), 6, pfe);  //fopen Read mode �L�k�g�J
	//fputs("���ռg�J��r", pfe);

	if (!ferror(pfe))   //ferror��^�D0,��ܲ��Ϳ��~(���ϥ�ferror,���~�ä�����)
	{
		printf("���榨�\\n");
	}
	else {
		printf("���楢��\n");
		perror("���ާ@�����D��.�]��");  //perror �ù���X���~�T��
		clearerr(pfe);		//�M����󥢱Ѫ��A(�p���M��,���۪���B�z���A�|�O�����~!)
	}

	////  clearerr�� �A�դ@��
	if (!ferror(pfe)) {
		printf("after clearerr,���榨�\\n");
	}
	else {
		printf("after clearerr,���楢��\n");
		perror("���ާ@�����D��.�]��");
	}

	fclose(pfe);   //�������(�p�����w����(�}�ҥ���),�]�N���ݭn��~

	system("pause");
}