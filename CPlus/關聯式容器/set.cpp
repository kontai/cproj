#include <iostream>
#include<vector>
#include<map>
#include<fstream>
#include<set>		//�t�J�Y��

using namespace std;

//set : �Pmap���@�P�ާ@,insert , count , find , erase��;
//�Pmap���P�O(1)�u�s�bkey,�õLvalue (2)�L�k�ϥΤU��
//��u�ݭn�d��O�_�s�b�Y�����ɫܦ���
//key�����O�W�@�L�G,�p�J�쭫��,�h�|����
int mainSet() {
	vector<int>ivec;
	for (vector<int>::size_type i = 0;i != 10;i++) {
		ivec.push_back(i);
		ivec.push_back(i);
	}

	set<int> iset(ivec.begin(), ivec.end());
	cout << ivec.size() << endl;
	cout << iset.size() << endl;  //���ƪ�key�Q�ٲ���

	iset.find(1);		//��^�@��iterator���Vkey��1������
	iset.count(1);		//��^1

	set<int>::iterator set_it = iset.find(1);
	//*set_it = 11;	key�O�`��,�L�k���



	system("pause");
	return 0;
}

/*
	void restrict_wc(ifstream& remove_file,map<string,int>& word_count)
	{
		set<string>exclude_word;
		string remove_word;
		while(remove_file>>remove_word)
			exclude_word.insert(remove_word);
		string key_in;
		while (cin >> key_in)
			if (!exclude_word.count(key_in))
				++word_count[key_in];

	}
*/
