/****************************************
[4/4/2017  20:49]
class�����Ѽ�this.cpp
****************************************/

#include<iostream>

using namespace std;

//*this : ���VCLASS����point , �j�w�󦨭��禡�I�s�̤W

//��I�s�����禡,�Ʊ��^�O����Ѧ�(*this)
class Screen {
public:
	typedef string::size_type index;
	Screen get();
	void get(char);
	Screen move(index, index, char);

	//nonconst�����禡,this��const����(p.126),�i����this�ҫ�����,�����i����this�ҫ���}
	//Rback& bi(char);
	//const�����禡,this�ҫ�����H�Φ�}�����i����

private:
	string contenes;
	index cursor;
	index width, lenth;
};

void Screen::get(char ch) {
	cout << ch << endl;
}

int mainvis() {
	Screen myscreen;
	myscreen.get('a');
	system("pause");
	return 0;
}