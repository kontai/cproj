#include "stdafx.h"
#include<iostream>
#include<string>
#include <vector>

//vector �p�P�i�ʺA���t�j�p��Array
//vector(n)vinit  : vinit�����@�Ӥw��l�ƪ���n������
//push_back ��J�@�Ӥ�����vector����)
//�i�Q�ΤU�Ф覡����,���X,�ק露����

using namespace std;

void mainVec() {
	string str("this is string!");
	vector<char>ch1(8);
	cout << ch1.size() << endl;
	for (string::size_type i = 0;i < str.size();i++) {
		ch1.push_back(str[i]);
	}
	ch1[0] = 'c';
	cout << ch1.size() << endl;
	cout << ch1[0] << endl;

	vector<string>vst;
	vst.push_back(str);
	vst.push_back("another string");
	cout << vst[0] << endl;
	cout << vst[1] << endl;

	vector<string>vsarr[3];
	vsarr[0].push_back(str);
	vsarr[1].push_back("another string");
	cout << vsarr[0][0] << endl;
	//	cout << vsarr[0][1] << endl;

	system("pause");
}