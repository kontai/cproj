#include<iostream>
#include<list>
#include <vector>
#include <iterator>

using namespace std;

int mainCopy()
{
	vector<int> ivec;
	for(vector<int>::size_type index=0;index!=10;index++)
		ivec.push_back(index);

	list<int> ilist;
	//copy() : �T�ӰѼ�,���O�O�ӷ��e�����_�I,���I,�ؼЮe��
	//�����T�O�ت��ݻP�ӷ��@�ˤj
	copy(ivec.begin(), ivec.end(), back_inserter(ilist));

	//�L�Xlist�̪���
	for (list<int>::iterator index = ilist.begin();index != ilist.end();index++)
		cout << *index << endl;

	//<<<<<��n����k>>>>>
	list<int>better_one(ivec.begin(), ivec.end());
	for (list<int>::iterator index = better_one.begin();index != better_one.end();index++)
		cout << *index << endl;


	system("pause");
	return 0;
}