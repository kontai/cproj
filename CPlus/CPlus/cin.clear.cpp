#include<iostream>
#include<string>
#include <vector>

using  namespace std;
int mainCinClear() {
	vector<int>a, b;
	int aa;

	cout << "please input a=>\n";
	while (cin >> aa) {
		a.push_back(aa);
	}
	cin.clear();	//cin.clear() : clears error and eof flags  �N��J�y�M��,�קK�NEOF���A�Q�U�@��CINŪ�J
	cout << "please input b=>\n";
	while (cin >> aa) {
		b.push_back(aa);
	}

	vector<int>::size_type len;
	a.size() < b.size() ? len = a.size() : len = b.size();
	vector<int>::size_type i = 0;
	for (;i != len;i++) {
		if (a[i] != b[i]) {
			cout << "false" << endl;
			break;
		}
	}
	if (i == len) {
		cout << "true" << endl;
	}

	system("pause");
	return 0;
}