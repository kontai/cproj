/****************************************
[4/18/2017  21:30]
class�@�ΰ�.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;

char test;

class PlanA {
public:
	typedef string::size_type index;
	char ch;
	int ia;
	index info(index, index)const;
	void test_func(char test) //�H�U���@�ΰ�d��
	{
		char in_local = test;

		char in_class = this->test;
		//or
		char in_class_2 = PlanA::test;

		char in_global = ::test;
	}
	PlanA() :ch('a'), ia(0) {
	}
	/*
	 * class�����w�q�������W�ٷj�M:
	 * �j�M����:
	 * �����禡local�@�ΰ줺�ŧi--> class�����ŧi-> �X�{�󦨭��禡�w�q���e���@�ΰ줺���ŧi
	 */
	 //	typedef char index;
private:
	char test;
};

class PlanB {
public:
	char ch;
	int ia;
};
PlanA::index PlanA::info(index x, index y)const
//index�w�q��class,���B�Aclass�@�ΰ�~,�ҥH�n���W�׹�
//class�~�������禡,�b�禡�W�٫᪺�޼�&�禡�D��,�|�Q��@class�����w�q,�������W�׹�
//���D��]�bclass�@�ΰ��,�ҥH�i�����ϥ�class����
{
	x = ch;
	return x;
}

//PlanA::index whatb(PlanA::index);
PlanA::index whata(PlanA::index ca) {
	typedef PlanA::index index; //m.....
	index a;
	//a = whatb(ca);
	return ca;
}
int mainScope() {
	//PlanA yank;
	//PlanB yank2=yank; //���~,yank�Pyank2���P���O

	PlanA woo;
	PlanA *haa = &woo;  //�Q�Ϋ��Цs��refence������
	haa->ch = 2;
	woo.ch = 3;
	PlanA **gain = &haa;
	(*gain)->ch = 4;

	system("pause");
	return 0;
}