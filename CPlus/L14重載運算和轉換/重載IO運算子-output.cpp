/****************************************
[5/22/2017  21:15]
����IO�B��l.cpp
****************************************/

#include<iostream>
#include <vector>
#include<string>

using namespace std;
/*
 *�榡: ostream& operator<<(ostream& , const class-member&)
 * �q�`���|�C�L����r��,���F���Τ�i�H�b�P�@��C�L��L�y�z��r
 * 
 * IO�����B��l����non-member�禡
 * //�p�Goperator<<��Mem���@�Ӧ���
 *	 Mem item;
 *	 Mem<<cout; (�Ϊk�ө_��,�ӥB�Moutput�B��l���W�Ϊk�ۤ�)
 * 
 * �Ӧ]���`�`�ݭn�M�Xclass private����.�ҥH������IO�B��l�]���ͤ�(friend)
 */
class CheckoutRecord
{
public:
	friend ostream& operator<<(ostream&, const CheckoutRecord&);
	friend class Date;
	
	//.....
private:
	double book_id;
	string title;
	pair<string, string>borrower;
	vector< pair<string, string >*>wait_list;
};


ostream& operator<<(ostream& out,const CheckoutRecord& ck){
	out << ck.book_id << "\t" << ck.title << endl;

	//vector �M pair �e���Loutput�B��l,�ҥH�n�ۤw�]�p,�H�j��v�ӿ�X
	for(vector< pair<string,string> * >::const_iterator iter=ck.wait_list.begin();
		iter!=ck.wait_list.end();iter++)
	{
		out << (*iter)->first << "\t" << (*iter)->second << endl;
	}
	return out;
}
int mainIO_Output(){



system("pause");
return 0;
}