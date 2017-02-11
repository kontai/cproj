#include<iostream>
#include<fstream>

using namespace std;

void st(istream &in) {
	cout << "cin.bad()=" << in.bad() << endl;
	cout << "cin.fail()=" << in.fail() << endl;
	cout << "cin.eof()=" << in.eof() << endl;
}

int mainIOstream() {
	int n = 0, sum = 0;
	while (cin >> n, !cin.eof()) {
		st(cin);
		if (cin.bad())
			cerr << "bad input,error corrupt" << endl;
		if (cin.fail()) {
			cerr << "wrong input,try again!" << endl;
			cin.clear(iostream::failbit);
			//�M�����~���A , �޼ƧΦ�j��iostate(iostate���T�ت��A:badbit,failbit,eofbit)
			cin.ignore(200, '\n');
			//�M��cin�w�s cin.ignore(number,delimiter)  �M�����r���ƶq,�βM������J�촫��ũΤ�󵲧�����'\n'
		   //�p�ݲM�Žw�s(flushed,�g�J�ɮשι�ڸ˸m),cin���򱵦��D�s�w�s�����~��J,�Φ��L���`��(���`��)

			continue;
		}
		else {
			sum += n;
			cout << sum << endl;
		}
	}
	if (cin.eof())
		cout << "End Of File!" << endl;

	system("pause");
	return 0;
}