#include<iostream>
#include <string>
#include <bitset>

using namespace std;

int mainError() {
	bitset<100> bit;

	try {
		for (size_t i = 0;i != bit.size();i++)
			bit[i] = i;
		bit.to_ulong();	//���ͷ��첧�`
	}
	catch (runtime_error err) {	//�B�̲��`
		cout << err.what() << endl;
	}
	system("pause");
	return 0;
}