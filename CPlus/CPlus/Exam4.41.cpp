#include<iostream>

using namespace std;

int mainEXAM441() {
	const size_t rowSize = 3;
	const size_t columnSize = 4;
	int ar[rowSize][columnSize] = { 0 };
	//�Q�ΤU�н�ȤG���Ʋ�
	for (int i = 0;i != rowSize*columnSize;i++) {
		ar[i / 4 % 3][i % 4] = i + 1;
	}

	//�Q�Ϋ��Ь��U�����ȥ����@��(��x2)
	int(*p)[4] = ar;
	while (p != ar + rowSize) {
		for (int *pi = *p;pi != *p + 4; pi++) {
			*pi <<= 1;
			cout << *pi << endl;
		}
		p++;
	}
	system("pause");

	return 0;
}