/****************************************
[5/30/2017  09:29]
���������X�ݾާ@��.cpp
****************************************/

#include<iostream>

//��class�t��"������w",�~�ݭn���������X�ݾާ@��

using namespace std;

class AString
{
public:
	AString():ptr(""){ }
	AString(char const *);
	AString(AString const&);
	~AString();

	AString& operator++();  //�e�[�[
	AString const operator++(int);  //��[�[
	AString& operator--();  //�e���
	AString const operator--(int);  //����

	void print()
	{
		cout << ptr << endl;
	}
private:
	char *ptr;
};

AString::AString(char const *charptr)
{
	charptr = charptr ? charptr : "";
	ptr = new char[strlen(charptr) + 1];
	strcpy(ptr, charptr);
}

AString::AString(AString const& charptr)
{
	ptr = new char[strlen(charptr.ptr) + 1];
	strcpy(ptr, charptr.ptr);
}

AString::~AString()
{
	cout << "delete ponter" << endl;
	delete[] ptr;
}
	AString& AString::operator++(){
		for (size_t i=0;i<strlen(ptr);i++)
		{
			++ptr[i];
		}
		return *this;
}

	AString const AString::operator++(int){
		AString copy(*this);
		++(*this); //�եΫe�[�[
		return copy;
	}

AString& AString::operator--(){
	for (size_t i = 0;i<strlen(ptr);i++) {
		--ptr[i];
	}
	return *this;
}

AString const AString::operator--(int){
	AString copy(*this);
	--(*this);  //�եΫe���
	return copy;
}

int mainPP_D(){
	AString ss1("abslouly");
	AString ss2="n/a";
	ss2.print();
	ss2++;
	ss2.print();
	ss2--;
	ss2.print();

system("pause");
return 0;
}