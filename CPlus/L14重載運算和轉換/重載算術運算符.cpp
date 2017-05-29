/****************************************
[5/23/2017  21:18]
������N�M���Y�B���.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;

class Sales_item3
{
public:
	Sales_item3(const string &book,const int units,const double amount):
		isbn(book),unit_sold(units),revenue(amount){ }
/*
 * �ѩ�+= , -= ����N�B��l�ݭn��^���Oclass��H,�ҥH�ߺD�W���������������
 * �ѼƦC�u���@�ӧΰ�(���B�⤸����this)
 */
	Sales_item3& operator+=(const Sales_item3&);
	Sales_item3& operator-=(const Sales_item3&);
	friend ostream& operator<<(ostream &, const Sales_item3&);

private:
	string isbn;
	int unit_sold;
	double revenue;
};

Sales_item3& Sales_item3::operator+=(const Sales_item3& rhs)
{
  //"this->"�i���μg(�w�bclass�@�ΰ줺)
	this->unit_sold += rhs.unit_sold;
	this->revenue += rhs.revenue;
	return *this;
}

Sales_item3 operator+(const Sales_item3& lhs,const Sales_item3& rhs){
	/*
	 * �p�P�@�륿�W�[�k�B��,�ۥ[�B���,�N���G�ǵ��s��H(����)
	 * �B��^�ȫDreference,�ҥH�N�@��+,-�B��]��non-class���
	 */
	Sales_item3 ret(lhs); 
	ret += rhs;
	return ret;
}

Sales_item3& Sales_item3::operator-=(const Sales_item3& rhs)
{
	
	this->unit_sold -= rhs.unit_sold;
	this->revenue -= rhs.revenue;
	return *this;
}

Sales_item3 operator-(const Sales_item3& lhs, const Sales_item3& rhs) {
	Sales_item3 ret(lhs);
	ret -= rhs;
	return ret;
}
 ostream& operator<<(ostream& out, const Sales_item3& rhs){
	 out << rhs.isbn << "\t" << rhs.unit_sold << "\t" << rhs.revenue << endl;
	 return out;
 }
int mainArithm() {
	Sales_item3 item1(string("0-00-000"), 3, 20.0);
	Sales_item3 item2(string("0-00-000"), 6, 120.0);
	cout << item1 + item2 << endl;
	Sales_item3 item3(item1);
	item3 -= item1;
	cout << item3 << endl;
	


system("pause");
return 0;
}