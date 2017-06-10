/****************************************
[5/13/2017  16:21]
Copy �غc��cpp.cpp

�ƻs�غc���D�n�Hreference�Φ��Ѽ�
****************************************/

#include<iostream>
#include<string>
#include <vector>

using namespace std;

class Sales_item {
public:
	Sales_item() :contents(""), unit_sold(0), revenus(0) {
		cout << "Sales_item()" << endl;
	}
	Sales_item(const string &book) :contents(book), unit_sold(0), revenus(0) {
		cout << "Sales_item(const string &book)" << endl;
	}

	Sales_item(const Sales_item& rhs) :
		contents(rhs.contents), unit_sold(rhs.unit_sold), revenus(rhs.revenus) {
	cout << "Sales_item (const Sales_item&)" << endl;
}

	Sales_item& operator=(const Sales_item& rhs){
		contents = rhs.contents;
		unit_sold = rhs.unit_sold;
		revenus = rhs.revenus;
		cout << "Sales_item& operator=(const Sales_item&)" << endl;
		return *this;
	}



	~Sales_item()
	{
		cout << "~Sales_item()" << endl;
	}

		
private:
	string contents;
	int unit_sold, revenus;
};

//��޼Ƭ�class��H,�B�Dreference,copy�غc���N�|�Q�ե�
//non-class��ƽեΧ���,�Ѻc���]�|�Q��_,�R���Ȯɪ��ƥ�

void fun1(Sales_item) {
}

void fun2(Sales_item& omg)
{
}

Sales_item fun3(Sales_item omg)
{
	Sales_item temp;
	temp = omg;
	return temp;
}

int mainCopyS(){
	Sales_item a;
	Sales_item b;
	fun1(a);
	fun2(a);
	a = b;
	Sales_item item = "abc";
	cout << "\n\n-------------" << endl;
	Sales_item c;
	c = fun3(item);
	cout << "-------------\n" << endl;

	vector<Sales_item>d(3);
	cout << "\n\n-------------" << endl;
	Sales_item e[3];
	cout << "\n\n-------------" << endl;

system("pause");
return 0;
}