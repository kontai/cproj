#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

void process(string &s) {
}
int mainFstreamR() {
	vector<string>file;		//vector���t�h�ӵ{���ɦW
	ifstream input;
	vector<string>::iterator it = file.begin();
	while (it != file.end()) {
		input.open(it->c_str());
		if (!input) {
			cerr << "unable open file!" << endl;
			break;
		}

		string s;
		while (cin >> s)
			process(s);

		input.close();	//�]ifstream��~���ŧi,�ҥH�b�i�J�U�@�Ӱj��e�n�Ninput�Ѱ��j�w
		input.clear();  //���Niostate���A�M�� �bŪ���ɮ׹L�{,�u�n�J��end-of-file�Ψ�L���~
								//����clear()�ʧ@,�����input��J���ʧ@���|����
		it++;
	}

	system("pause");
	return 0;
}