#include <iostream>
#include <cassert>
#include<string>

using namespace std;

const string &str(const string &a, const string &b)
{
	string tmp = a;
	return tmp; //��^reference to local object�|���Ϳ��~,�禡����,local�O����Ŷ��Q����,��^�ҰѷӪ��O�����O�����m
}

int mainRfToLocal(int argc,char *argv[])
{
	string x("abc"), y("def");
	string ss = str(x, y);
	cout << ss << endl;

	system("pause");
	return EXIT_SUCCESS;
}