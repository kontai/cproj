#include<iostream>
#include <string>

using namespace std;

/*
����:
(�@)��ƦW�ۦP,���O�ѼƤ��P(��^�Ȥ]���i�ۦP)
(�G)�����b�ۦP�@�ΰ��(�sĶ�����M���ƦW,�~�����O�˴�)
(�T)�ѼƼƶq�P���O,�O�����Ϥ�����
*/

void wh(int a) {
	cout << a << endl;
}

void wh(double a) {
	cout << a << endl;
}
//void wh(const double); //error:�p�G�޼Ƥ��Oreference,const�P�Dconst��ڤW�O�ۦP��(�u�O�ƻs�޼ƭ�)

//const reference diff. w/ reference
//void wh(const string &);
void wh(string &a) {
	cout << a << endl;
}

//long wh(long*);
//long wh(long *const); //���ƫŧi(const�����w����[�ƻs��],�ӫD�ҫ����O)

int *wh(int*a) {
	cout << a << endl;
	return a;
}
double *wh(double*a) {
	cout << a << endl;
	return a;
}

int mainOverload() {
	string ss = "One Two Three";
	wh(ss);
	wh(1.22);
	wh(20);

	system("pause");
	return 0;
}

long wh(long * const) {
	return 0;
}