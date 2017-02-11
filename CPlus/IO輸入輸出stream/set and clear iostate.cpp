#include<iostream>
#include <fstream>

using namespace std;

void out1(ifstream&in) {
	cout << "fail()=" << in.fail() << endl;
	cout << "eof()=" << in.eof() << endl;
}
void out() {
	cout << "fail()=" << cin.fail() << endl;
	cout << "eof()=" << cin.eof() << endl;
}
void clr() {
	cin.clear();
	cin.ignore(200, '\n');
}
void process_state() {
	int a;
	while (cin >> a, !cin.eof()) {
		out();
		if (cin.fail()) {
			clr();
		}
	}
}

int mainSet_iostate() {
	ifstream in;
	in.setstate(ifstream::failbit | ifstream::eofbit);		//�]��failbit & badbit �� "true" ;
	cout << "Origing in============" << endl;
	out1(in);
	istream::iostate old_in = in.rdstate();   //rdstate() : �ثeiostate�� (�Hbitset�覡�x�s.�B�z)
	in.clear();					//�M��iostates�Ҧ����A;
	cout << "After clear() in============" << endl;
	out1(in);
	in.clear(old_in);    //�^�_��liostates���A
	cout << "After clear(old_in) in============" << endl;
	out1(in);
	/*
		istream::iostate old_state = in.rdstate();
		cin.clear();
		process_state();
		out();
		cin.setstate(old_state);
		out();
	*/
	system("pause");
	return 0;
}