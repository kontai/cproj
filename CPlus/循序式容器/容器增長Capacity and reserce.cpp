#include<iostream>
#include <vector>

using namespace  std;

//c++ Primer 4/e p.330
//(�j�p)size() : �����ƶq
//(�e�q)capacity()  : �d�ߨt�ά��e����ڰt�m�j�p(����{�ֳt�t�m,�t�η|�w�d�ƥΪŶ�),��� >= size()
//reserve() : ���wcapacity�j�p,�]�w�ȶ����l�Ȥj�~���@��,�L�k�Y��

int mainCapacity_reserve() {
	vector<int>	ivec;
	cout << "����l�� vector size() and capacity():" << endl;
	cout << "vetcor size: " << ivec.size() << '\t' << "capccity size: " << ivec.capacity() << '\n' << endl;
	vector<int>::size_type i = 0;
	while (i != 24)
		ivec.push_back(i++);
	cout << "��ȫ� vector size() and capacity():" << endl;
	cout << "vetcor size: " << ivec.size() << '\t' << "capccity size: " << ivec.capacity() << '\n' << endl;

	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	cout << "�Ӻ�capacity�w�d�Ŷ�   vector size() and capacity():" << endl;
	cout << "vetcor size: " << ivec.size() << '\t' << "capccity size: " << ivec.capacity() << '\n' << endl;

	//��size=capacity��,�p�A�W�K����,�N�|���s�t�m�x�s�ž�
	ivec.push_back(0);
	cout << "�յۦApush�@����  	vector size() and capacity():" << endl;
	cout << "vetcor size: " << ivec.size() << '\t' << "capccity size: " << ivec.capacity() << '\n' << endl;

	ivec.reserve(60);
	cout << "reserve 10�Ӥ���  	vector size() and capacity():" << endl;
	cout << "vetcor size: " << ivec.size() << '\t' << "capccity size: " << ivec.capacity() << '\n' << endl;

	system("pause");
	return 0;
}