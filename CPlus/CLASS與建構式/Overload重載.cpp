#include<iostream>
#include <string>

using namespace std;

/*
  ����:
  (�@)��ƦW�ۦP,���O�ѼƤ��P(��^�Ȥ]���i�ۦP)
  (�G)�����b�ۦP�@�ΰ��(�sĶ�����M���ƦW,�~�����O�˴�)
  (�T)�ѼƼƶq�P���O,�O�����Ϥ�����
 */

void wh(int) {
};
void wh(double);
//void wh(const double); //error:�Dreference�Ѽ�,const�P�Dconst��ڤW�O�ۦP��(�u�O�ƻs�޼ƭ�)

//const reference diff. w/ reference
void wh(const string &);
void wh(string &);

long wh(long*);
long wh(long *const); //���ƫŧi(const�����w����[�ƻs��],�ӫD�ҫ����O)

int *wh(int*);
double *wh(double*);

int mainOver_load() {
	wh("warning ");
	wh(1.22);
	wh(20);

	system("pause");
	return 0;
}