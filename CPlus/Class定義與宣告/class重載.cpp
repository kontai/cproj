/****************************************
[4/4/2017  09:20]
class����.cpp
****************************************/
/*
 * class�������@�Υu��P�@class���������禡����;�P�~�����D�����禡�Τ@��禡�������ۤz
 * 
 */
#include<iostream>
#include<string>

using namespace std;
class Screen {
public:
	typedef string::size_type index;
	char get()const {
		return content[cursor];
	}
	char get(index wd, index ht)const
	{
		cout << wd << '\t' << ht << endl;
		return 'a';
	}
private:
	string content;
	index cursor;
	index width, hight;

};

int mainClassOverload() {
	Screen myscreen;
	char ch;
	ch=myscreen.get(0,0);



system("pause");
return 0;
}