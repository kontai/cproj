#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<io.h>

//_access�P�_���/��󧨬O�_�s�b
//_access("file",[option]0-�P�_�O�_�s�b,2-�P�_�O�_�iŪ,4-�P�_�O�_�i�g,6-�P�_�O�_�iŪ�i�g)
//��^��(0-�i�H/�s�b , �D0 - ���i/���s�b)

void main3() {
	char ch = 0;
	char file[20] = "c:\\1.txt";
	//FILE *flp = fopen(file, "w");
	if (_access(file, 0)) {
		printf("can't find file");
	}
	else {
		printf("find file:%s", file);
	}

	system("pause");
}