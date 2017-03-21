#define _SCL_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

/************************************************************************/
/*                                                                      */
/*back_inserter(con) :�󤺳��ϥ�push_back();
/*front_inserter(con) :�󤺳��ϥ�push_front();
/*inserter(con,where)�ϥ� insert ��{���J�ާ@�C���F�����p���e���~�Ainserter �ٱa���ĤG��ѡG���V���J�_�l��m�C
/************************************************************************/
int mainInsert_front_back() {
	// position an iterator into ilst
	vector<int>ivec;
	list<int>ilstA;
	list<int>::iterator it = find(ilstA.begin(), ilstA.end(), 42);
	// insert replaced copies of ivec at that point in ilst
	replace_copy(ivec.begin(), ivec.end(), inserter(ilstA, it), 100, 0);
	//�ե� replace_copy ���ĪG�O�q ivec ���ƻs�����A�ñN�䤤�Ȭ� 100 ������������ 0 �ȡCilst ���s�����b it �ҼЩ��������e�����J�C
	list<int> ilst, ilst2, ilst3;    // empty lists
	// after this loop ilst contains: 3 2 1 0
	for (list<int>::size_type i = 0; i != 4; ++i)
		ilst.push_front(i);
	// after copy ilst2 contains: 0 1 2 3
	copy(ilst.begin(), ilst.end(), front_inserter(ilst2));
	// after copy, ilst3 contains: 3 2 1 0
	copy(ilst.begin(), ilst.end(), inserter(ilst3, ilst3.begin()));

	system("pause");
	return 0;
}