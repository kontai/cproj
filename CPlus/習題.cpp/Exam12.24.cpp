/****************************************
[5/4/2017  09:51]
Exam12.24.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;

class Sales_item
{
public:
	Sales_item(const string &book):isbn(book),units_sold(0),revenus(0.0){ }

//"�w���w�]�޼�"�P�U�C�غc��(default��l��)����
  //Sales_item(const string &num=""):isbn(num),units_sold(0),revenus(0.0){ }

	//Sales_item():units_sold(0),revenus(0.0){ }


	Sales_item(istream &is);
private:
	string isbn;
	int units_sold;
	double revenus;
};

Sales_item::Sales_item(istream &is=cin) //�Ncin�@���ѼƦC�޼�
{
	string ss;
	is >> ss;
}

int mainExam12_24(){

	Sales_item next;
	Sales_item last("9-99-999");
	Sales_item  fin(cin);
	



system("pause");
return 0;
}