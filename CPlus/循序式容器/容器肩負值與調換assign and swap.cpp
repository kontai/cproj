#include<iostream>
#include<string>
#include<vector>

using namespace std;

int mainAssign_Swap() {
	vector<string>lstr, lstr2, lstr3 = { "peace","world","rule","road" };

	vector<string>::size_type index = 0;
	string str, str2;
	cin.clear();
	while (getline(cin, str), !cin.eof()) {
		lstr.push_back(str);
		cin.clear();
		if (getline(cin, str2), !cin.eof());
		lstr2.push_back(str2);
		cin.clear();
		vector<string>::reverse_iterator test_swap = lstr.rbegin();  //�̫�@�Ӥ���
		vector<string>::reverse_iterator test_swap2 = lstr2.rbegin();

		//lstr = lstr2;		//�M��lstr,�Nlstr2�ƻs��lstr(�e���j�p�]�|�ܦ��Plstr2�ۦP)
		//lstr.assign(lstr3.begin(), lstr3.end());  //�N�t�@�Ӯe���϶�,�ƻs������e��(����I�s�ۨ��e���϶�,��Ȯ�,����iterator�|�Q�R��)
		//lstr.assign(3, "aa");  //�N3�Ӧr��"aa"�_¾���e��(�e���ؤo�]�ܦ�3!)

		cout << "before swap:" << endl;
		cout << lstr.at(index) << '\t' << lstr2.at(index) << endl;

		lstr.swap(lstr2);
		//�m����e���Ҧ�����,�t�פ�assign��(�m������:��e�����O�����ۦP)

		cout << " after swap:" << endl;
		cout << lstr.at(index) << '\t' << lstr2.at(index) << endl;
		cout << " after swap iterator:" << endl;
		cout << *test_swap << '\t' << *test_swap2 << endl;
		//swap��,����iterotor�]���|����!(�]�N�O���ۦP�ˤ���)
		index++;
	}

	system("pause");
	return 0;
}