#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include <vector>

using namespace std;
int mainE518() {
	string str;
	vector<string*>vs;
	while (cin >> str) {
		string *ps = new string;
		*ps = str;
		vs.push_back(ps);
	}
	vector<string*>::iterator iit = vs.begin(); //�N�ܼƫŧi�b�~�ϰ�,�H�K����O����
	while (iit != vs.end()) {
		cout << **iit << ' ' << (*iit)->size() << endl;
		iit++;
	}

	iit = vs.begin();  //�N���в��^�}�Y
	while (iit != vs.end()) {
		delete *iit;
		iit++;
	}

	system("pause");
	return 0;
}