/****************************************
[5/22/2017  22:16]
����IO�B��l-input.cpp
****************************************/

/*
 *�榡:istream& operator>>(istream& in,Sales_item2& s)   
 *class-member���i�]�w��const(input�ت��N�O�g�ܸӹ�H)
 *
 * �Poutput���P���O,�ݭn�P�_��J�O�_����(*���n)
 */
#include<iostream>
#include<string>

using namespace std;

class Sales_item2
{
public:
	friend istream& operator>>(istream& in, Sales_item2& s);
	Sales_item2():units_sold(0),revenue(0){ }
private:
	string isbn;
	size_t units_sold;
	double revenue;

};

istream& operator>>(istream& in,Sales_item2& s){
	double price;
	in >> s.isbn >> s.units_sold >> price;
	//�ˬd��J�O�_���\(���d�ҥu������²�檺�˴�--��J���\�NOK)
	//�Ԩ�p.287
	if (in)
		s.revenue = s.units_sold * price;
	else
		s = Sales_item2(); //��J����:�N���󭫸m���w�]���A
	return in;
}

int mainIO_input(){
	Sales_item2 a;
	Sales_item2 *b = new Sales_item2();
	cin >>a;


system("pause");
return 0;
}