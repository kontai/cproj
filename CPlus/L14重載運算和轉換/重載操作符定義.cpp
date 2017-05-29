/****************************************
[5/21/2017  10:39]
�����ާ@�ũw�q.cpp
****************************************/

#include<iostream>
/*
 * �����B�⤣�i�Nbuild-in���O���s�w�q
 * int operator+(int,int) X���~
 * 
 * ���ରbuild-in���O�w�q�s�B��l
 * int a[10],b[19];
 * a+b   X build-in ints �L�k��array�ۥ[
 *  
 * �����B��l�ܤ֥������@��class type �� emuneration type(�C�|)
 * 
 * �B��l�u������(precedence)�B���X�v(Associativity)�L�k����
 * = �B [] �B () �B ->  �����w�q�������禡,�_�h�sĶ�|�X��
 */
using namespace std;

class Sales_item
{
public:
	Sales_item(int c) :a(c){ }
	int  operator+(const Sales_item& ia2) {
		return a + ia2.a;
	}
	Sales_item& operator+=(const Sales_item& it2) {
		a += it2.a;
		return *this;
	}
	friend ostream& operator<<(ostream&, const Sales_item&);
	friend istream& operator>>(istream&, Sales_item&);
private:
	int a;
};

 ostream& operator<<(ostream& os, const Sales_item& out) {
	os << out.a << endl;
	return os;
}
istream& operator>>(istream& is, Sales_item& in) {
	is >> in.a ;
	return is;
}

int mainInstro(){
	Sales_item item1(3), item2(2);
	cout << item1+item2 << endl;
	cout << item1.operator+(item2) << endl;
	cin >> item1 >> item2;
	cout << item1+item2 << endl;



system("pause");
return 0;
}