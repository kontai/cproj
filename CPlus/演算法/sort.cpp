#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include<fstream>
#include <bitset>

using namespace std;

bool isShorter(const string &s1,const string &s2)
{
	return s1.size() > s2.size();
}

bool GT5(const string &s3)
{
	return s3.size() > 5;
}

int mainSort()
{
	vector<string>word;
	string next_word;

	ifstream input("c:\\temp\\perldoc.txt");
	if (!input)
		cerr << "file open fail" << endl;
	while (input >> next_word)
		word.push_back(next_word);
//	while (cin >> next_word)
//		word.push_back(next_word);

	for (vector<string>::iterator i = word.begin();	i != word.end();i++)
		cout << *i  <<' ';
	cout << "\n\n\n";

	sort(word.begin(), word.end());  //sort�|�̷�ASCII�r�X����,�N���w�d��~�Ѥp��j�Ƨ�

	for (vector<string>::iterator i = word.begin();	i != word.end();i++)
		cout << *i  <<' ';
	cout << "\n\n\n";

	vector<string>::iterator word_unique = unique(word.begin(), word.end());  
	//unique �|���ƫ��w�d��,�ϱo��r�u�|�X�{�@��,�ê�^�����Ƴ�r���U�@�Ӧ�m(���Ƴ�r���_�l��m)

	for (vector<string>::iterator i = word.begin();	i != word.end();i++)
		cout << *i  <<' ';
	cout << "\n\n\n";

	word.erase(word_unique, word.end());  //�����D���Ƥ���

	stable_sort(word.begin(), word.end(),isShorter);
	vector<string>::size_type wc = count_if(word.begin(), word.end(), GT5);

	system("pause");
	return 0;
}