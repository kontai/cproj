/****************************************
[5/25/2017  21:26]
������Ⱦާ@��.cpp
****************************************/

#include<iostream>

using namespace std;
class String
{
public:
	String(const char*);

	String& operator=(const String&);

	void print()
	{
		cout << pstring << endl;
	}

	
	
private:
	char *pstring;
};

String::String(const char* ch)
{
	ch = ch ? ch : "";
	pstring = new char[strlen(ch) + 1];
	strcpy(pstring, ch);
}

String& String::operator=(const String& ass){
	if(strlen(pstring)!=(strlen(ass.pstring)))
	{
		char *CpStr = new char[strlen(ass.pstring) + 1];
		delete[] pstring;  //�R��pstring�ҫ���}
		pstring = CpStr;	//�Npstring���V�s�إߪ��ʺA�Ŷ�
	}
	strcpy(pstring, ass.pstring);

		return *this;
	
}

int mainAssign_(){
	String str("hotdog");
	String str2("pizza");
	str2.print();

	str2 = str;
	
	str2.print();



system("pause");
return 0;
}