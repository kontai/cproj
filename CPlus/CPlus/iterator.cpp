#include<iostream>
#include<vector>
#include<string>

using namespace std;

//iterator �p�PC�y��������
//begin()�Ǧ^�e���Ĥ@��������,end()�Ǧ^�e���������U�@�ӫ���

int  mainIterator() {
	vector<string>vs;
	string ch = "impressive";
	string ch2 = "impossible";
	vs.push_back(ch);
	vs.push_back(ch2);

	cout << vs[0]<<'\n'<<vs[1] << endl;

	vector<string>::iterator ivst = vs.begin();
	vector<string>::size_type len = vs.size();
	while(len--)
	{
		*ivst = "boring";
		ivst++;
	}
	
	cout << vs[0]<<'\n'<<vs[1] << endl;
	string *st = &ch;
	*st = "changed";
	cout << *st << '\n' << ch << endl;
	system("pause");

	return 0;
}