/****************************************
[5/4/2017  14:36]
class�����ഫ.cpp
****************************************/

#include<iostream>
#include <string>

using namespace std;

class Implicit {
public:
	explicit Implicit(const string &st=""):str(st) {}
	 //Implicit(const string &st=""):str(st) {}

	bool same_isbn(Implicit& ref) {
		return str == ref.str;
	}

private:
	string str;

};


int mainClassExplicit(){
	Implicit aa("abcd");
	Implicit bb=Implicit("abc");

	//���]�߫غc����,"def"�|�����ഫ��Implicit("def");
	//Implicit cc = "def"; 
	//��غc���Hexplicit�ŧi,�w�q/�ե�class��H������̾a�����ഫ,�sĶ�|����
system("pause");
return 0;
}