#include <iostream>
#include<numeric>
#include <vector>
#include <iterator>

using namespace std;

int mainFill_Fill_n() {
	vector<int>ivec={12,3234 ,54546 ,76,2,23,4};

//�N���w�϶���0
	fill(ivec.begin(), ivec.end(), 0); 

//�qivec.begin�}�l2�Ӥ���,��0
	fill_n(ivec.begin(), 2, 0); 

	vector<int>fill_test;   //�Ū�vector
	//fill_n(fill_test.begin(), 10, 0);  //����ɷ|���Ϳ��~(�Ū�vector�L�k��g)

	//back_inserter�N�ͦ�insert iterator , �ù�fill_test�I�spush_back,�N10��0�K�[�����
	//�ϥ�back_inserter�ݥ[�J�Y��<iterator>
	fill_n(back_inserter(fill_test), 10, 0);

	system("pause");
	return 0;
}
