/****************************************
[3/26/2017  07:31]
Source.cpp
****************************************/

#include<iostream>
#include<vector>
#include<list>
#include<string>
/*
 * class�����Ҧ@���T��:public,private,protected
 *	class���w�](�L����)�Oprivate
 *	struct�Opublic
 *
 *	public��������,�b�{�����Ҧ����i�X��
 *	private��������,�u���b�쥻��class��(�������)����X��
 *
 *	�b�Ҧ������w�q�e,���ҳ��i�H�X�{,�Ӽ��ҧ@�νd��b�U�Ӽ��� �Ϊ�class���k�A���e������
 */
using namespace std;

class Person {
public:
	Person(const string &na, const string &add) :name(na), address(add) {
	}
	string getadd() const;
private:
	string getname() const;
	string name;
	string address;
};

string Person::getadd() const {
	return address;
}

string Person::getname() const {
	return name;
}

int mainLablec() {
	string n = "kontai";
	string a = "taouyam";

	system("pause");
	return 0;
}