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
 *	private��������,�u���b�쥻��class��������Ư���X��
 *	
 *	�b�Ҧ������w�q�e,���ҳ��i�H�X�{,�Ӽ��ҧ@�νd��b�U�Ӽ��� �Ϊ�class���k�A���e������
 */
using namespace std;

class Person {
public:
	Person(const string &na, const string &add) :name(na), address(add) {
	}
	string getadd();
	string name;
	string address;

}tests;
string Person::getadd()
	{
		return address;
	}
	string getname()
	{
		return name;
	}
int main(){
	string n = "kontai";
	string a = "taouyam";
	tests.address = n;
	tests.name = a;

system("pause");
return 0;
}