/****************************************
[4/24/2017  21:05]
class�غc����Ⱦ�.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;

/*
 * ���const������reference���������ܼ�,�Ψ�class���O�S��default�غc���������ܼ�
 * �����ϥΪ�Ⱦ���l��
 */
class constRef {
public:
	//�Q�Ϊ�ȦC��l��
	constRef(int jj) :i(jj), ci(jj), ri(jj) {
	};
	/*
		//�b�غc���D��,�Q��"���"��l��"

		constRefII(int jjj)
		{
			i = jjj;
			//ci = jj;  //���~,const�L�k���
			ri = jjj;
		}
	*/
private:
	int i;
	const int ci;
	int &ri;
};

//�غc����l�ƶ���//
/*
 * �غc����l�ƶ��ǬO�ھ��ܼƩw�q����,���O��l�ư��涶��
 */

class Order {
	int i;
	int j;
public:
	Order(int val) :j(val), i(j) {
	} //���~,�����Q��l�ƪ�j�Ӫ�l��i
};

class Sales_item {
public:
	Sales_item(const string &book) :isbn(book), units_sold(0), revenus(0.0) {
	}

	//�ѼƦC�p���w�]�޼�,�N�|���N�w�]�غc��
	//Sales_item(const string &num=""):isbn(num),units_sold(0),revenus(0.0){ }

	//�H�U��ӫغc���ѩ󳣬O�w�]�غc��,��w�qclass��H�S���޼Ʈ�,�|�y���Ĭ�
	Sales_item(istream &is = cin); //�Ncin�@���ѼƦC�޼�

	// "�w���w�]�޼�"�P�U�C�غc��(default��l��)����
	//Sales_item():units_sold(0),revenus(0.0){ }

private:
	string isbn;
	int units_sold;
	double revenus;
};


int mainClassInit() {
	//Sales_item next;
	Sales_item last("9-99-999");
	//Sales_item  fin(cin);

	system("pause");
	return 0;
}