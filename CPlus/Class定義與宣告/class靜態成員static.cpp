/****************************************
[5/9/2017  20:58]
class�R�A����static.cpp
****************************************/

#include<iostream>
#include<string>

//static�����W�ٸ��bclass�@�ΰ줤,�i�H�קK�M��Lclasses�������άO�Mglobal����o�ͦW�ٽĬ�
//�F��ʸˡCstatic�����i�H�Oprivate,global����o����
//�\Ū�{���X�i�H���P�ݥX�@�ӵ{���X�M��class���������p,�ϵ{���N�ϧ�M��

using namespace std;

class Account {
public:
	void applyint() {
		amount += amount*interestRate;
	}

	static double rate() {
		return interestRate;
	}
	static void rate(double);

private:
	string owner;
	//static double amount;
	double amount;
	int  index;
	static double interestRate;
	static  double initRate();
	//��ƫ�const static�����ܼƥi�H�bclass���餺������l��
	static const  int initVal = 3;
	//initVal�Oconst;
	static double arr_con[initVal];
};

// **�`�N** static�ƾڦ��������b���w�q�~���w�q,�B�u�w�q�@��
//�bclass�~,�����A�[�Wstatic����r,�o����r�u�bclass���餺�ŧi�W�X�{
double Account::interestRate = 3.4;

void Account::rate(double newRate) {
	interestRate = newRate;
}

//const static �����ܼƤw�g�bclass�D�餺��l��,���n�b�~���w�q
const int Account::initVal;

class Bar
{
public:
	//....
private:
	Bar *mem1;
	static Bar mam2; //static�����W�ߩ���󪫥�Ӧs�b
  //Bar mem3;		 //���~

public:
	Bar& wiii( char = red);
private:
	static const char red = '#';

};

int mainStaticClass() {
	Account ac1;
	Account *ac2 = &ac1;

	//�H�U�O�I�sstatic rate()���T�ص�����k
	double rate;
	rate = ac1.rate();
	rate = ac2->rate();
	rate = Account::rate(); //�ϥ�scope�B��l,�����z�Lclass���o(static�S��)
	cout << rate << endl;

	system("pause");
	return 0;
}