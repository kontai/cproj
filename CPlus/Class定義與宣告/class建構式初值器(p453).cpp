/****************************************
[4/24/2017  21:05]
class�غc����Ⱦ�.cpp
****************************************/

#include<iostream>

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

class Order
{
	int i;
	int j;
public:
	Order(int val):j(val),i(j){ } //���~,�����Q��l�ƪ�j�Ӫ�l��i
};

int mainClassInitial() {

	system("pause");
	return 0;
}