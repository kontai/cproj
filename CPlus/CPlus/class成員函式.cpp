#include<iostream>

using namespace std;

//	bool same_isbn(const Sales_Item &rha)	const	//
//ㄧ计ソЮconst,ㄧ计constΘㄧ计
//留畴this把计,矪单this->isbn(㊣ㄧ计ン,ㄤンclassΘisbn)
//"constン"┪"point to constン",ノㄓ㊣constΘㄧ计

class Sales_Item
{
public:
	double avg_prince() const;
	bool same_isbn(const Sales_Item &rha)	const		//﹚竡classずΘㄧΑ,盢砆跌inlineㄧΑ.
	{																					
		return isbn == rha.isbn;											//ΘㄧΑㄤclassprivateΘ
	}

private:
	std::string isbn;
	unsigned units_sold;
	double revence;
};									//struct,class挡璶だ腹;

double Sales_Item::avg_prince() const		//ΘㄧΑゲ斗classず﹚竡,ㄧΑ砰class﹚竡
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
