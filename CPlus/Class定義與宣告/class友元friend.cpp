/****************************************
[5/6/2017  10:52]
class�ͤ�friend.cpp
****************************************/

//�ͤ����\�D�����禡�s��class private����
#include<iostream>


using namespace std;

class CaseA
{
public:
	CaseA():a(0),b(0){ }
	CaseA(int x,int y):a(x),b(y){ }

	//�ŧi�ͤ��t��.���Dclass�����禡�]����s��private����!
	friend int Add(CaseA&);

	 friend istream& Read(istream &, CaseA &);
private:
	int a, b;
	
};

int Add(CaseA& t)
{
	return t.a + t.b;  //�b�D�����禡non-member�s�������禡����
}


istream& Read(istream &keyin,CaseA& Cain)
{
	cout << "give some integer=>";
	keyin >> Cain.a;
	keyin >> Cain.b;
	return keyin;
}


int mainFriend(){
	CaseA ta(33,66);
	cout << Add(ta) << endl;
	CaseA tb;

	int a;
	Read(cin, tb)>>a;
	cout << a;
	



system("pause");
return 0;
}