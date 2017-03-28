/****************************************
[3/26/2017  07:31]
Source.cpp
****************************************/

#include<iostream>
#include<vector>
#include<list>
#include<string>
/*
 * class的標籤共有三種:public,private,protected
 *	class內預設(無標籤)是private
 *	struct是public
 *	
 *	public內的成員,在程式內所有都可訪問
 *	private內的成員,只有在原本的class內成員函數能夠訪問
 *	
 *	在所有成員定義前,標籤都可以出現,該標籤作用範圍在下個標籤 或者class的右括號前都有效
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