#include<iostream>
#include<cassert>
#include<string>

using namespace std;

int mainExam6_25() {
	string str;
	while (cin >> str) {
#ifndef NDEBUG
		cout << str << endl;  //�}�o�Ҧ�,��Xstr		�o��Ҧ�,���q���|����
#endif
	}

	system("pause");
	return 0;
}