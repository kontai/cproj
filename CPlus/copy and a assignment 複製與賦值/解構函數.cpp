/****************************************
[5/18/2017  20:24]
�Ѻc���.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;

class NoName
{
public:
	NoName() : sptr(new string), i(0), d(0)
	{
		cout << "�c�y�禡�Q�եΤF.." << endl;
	}

	NoName(const NoName&);
	NoName& operator=(const NoName&);

 //�����������w����,�N�����ϥθѺc���,�Ϥ�,�h�i�ϥνsĶ���۰ʴ��Ѫ��X����ƧY�i
	~NoName();

	private:
	string* sptr;
	int i;
	double d;
};

NoName::NoName(const NoName& other)
{
	sptr = new string;
	*sptr = *(other.sptr);
	i = other.i;
	d = other.d;
}

NoName& NoName::operator=(const NoName& rhs)
{
	sptr = new string;
	*sptr = *(rhs.sptr);
	i = rhs.i;
	d = rhs.d;
	return *this;
}

NoName::~NoName()
{
	delete sptr;
	cout << "�Ѻc�禡�Q�ե�.." << endl;
}

int maindele()
{
	NoName a;
	NoName* p = new NoName;
	delete p; //�եθѺc���

	system("pause");
	return 0;
}
