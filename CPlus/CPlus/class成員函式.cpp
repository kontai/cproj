#include<iostream>

using namespace std;

//	bool same_isbn(const Sales_Item &rha)	const	//
//��ƥ�����const,��������Ƭ�const�������
//�����몺this�Ѽƫ��O,���B�P��this->isbn(�I�s��ƪ�����,�䪫��class����isbn)
//"const����"�Ϊ�"point to const����",�u��ΨөI�sconst�������

class Sales_Item
{
public:
	double avg_prince() const;
	bool same_isbn(const Sales_Item &rha)	const		//�w�q��class���������禡,�N�Q����inline�禡.
	{																					
		return isbn == rha.isbn;											//�����禡�i�s����class��private����
	}

private:
	std::string isbn;
	unsigned units_sold;
	double revence;
};									//�p�Pstruct,class�����n�[�W����;

double Sales_Item::avg_prince() const		//�����禡�����bclass���w�q,���禡�D��i�H�bclass�~�w�q
{
	if (units_sold)
		return revence / units_sold;
	else
		return 0;
	}

int mainClassSales()
{
	


	system("pause");
	return 0;
}
