#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;

//istringstream:�N��J�y�j�w��string,�u�iŪ�J
//ostringstream:�N��J�y�j�w��string,�u�i�g�X
//iostringstream:�N��J�y�j�w��string,�iŪ�]�i�g
//�p�PC�y������sscanf , sprintf ----  �榡�ƿ�J��X

int cnt(string);

int mainStringStream()
{
	ostringstream out;
	int inA = 22, inB = 55;
	out << "Hello! " << inA ;   //�N�r��ᤩ��ostringstream
	 cout<< out.str()<<endl;
	string str = out.str();
	cout << str << endl;

	istringstream in;
	int change_int=0;
	string st2int = "5566";
	in.str(st2int);
	in >> change_int;   //�Ѧr���ഫ�����
	cout << change_int<<endl;


	cout << "�п�J�s�X(���N�r��+�Ʀr<CTRL+Z����)=>";
	string find_int ;
		int  total = 0;
	while (getline(cin, find_int)) {
		in.clear();
		in.str(find_int);
		string dump;
		while (in >> dump) {
			total += cnt(dump);
		}
	}
	cout <<"�r�ꤺ��ƺةM="<< total<<endl;
	system("pause");
	return 0;
}
int cnt(string str) {
	string::iterator id = str.begin();
	int sum = 0,f_total=0;
	while (id != str.end()) {
		if (*id >= '0' && *id <= '9') 
			sum = *id - '0' + 10 * sum;
		else {
			f_total += sum;
			sum = 0;
		}
		id++;
	}

			f_total +=sum;
			cout << f_total<<endl;
	return f_total;
}