#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<map>

using namespace std;

ifstream& open_file(ifstream& in, const string& file) {
	in.close();
	in.clear();
	in.open(file);
	return in;
}

int main�r���ഫ(int argc, char **argv) {
	map<string, string> trans_map;
	if (argc < 3)
		cerr << "not enough word?" << endl;

	ifstream input;	//�Ыؿ�J�y,�j�w��"�r����"
	if (!open_file(input, argv[1]))
		cerr << "can't open file!" << endl;

	string key, value;		//�N�ɮ���Jmap
	while (input >> key >> value)
		trans_map.insert(make_pair(key, value));

	ifstream read_file;  //�Ыؿ�J�y,�j�w���n�ഫ���ɮ�
	if (!open_file(read_file, argv[2]))
		cerr << "cant open file!" << endl;

	string line;
	while (getline(read_file, line)) {
		istringstream istr(line);
		string word;
		bool firstword = true;  //����O�_�C�L�Ů�
		while (istr >> word) {
			map<string, string>::iterator im = trans_map.find(word);
			if (im != trans_map.end())  //�p�G��r�X�{�b�r��
				word = im->second;	///������r
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << word;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}