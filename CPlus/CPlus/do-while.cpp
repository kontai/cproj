#include<iostream>
#include <string>

using  namespace std;
int mainDoWhile() {
	string a, b, c;   //��l�ƻݩ�j��~,�קKwhile�P�_��,�ϰ��ܼƵL�k�Q�ѧO
	do {
		cout << "please input two words" << endl;
		cin >> a >> b;
		if (a < b)
			cout << "a less than b" << endl;
		else if (a == b)
			cout << "a = b" << endl;
		else
			cout << "b less than a" << endl;

		cout << "continue?? y=yes,n=no:";
		cin >> c;
	} while (c[0] == 'y' || c[0] == 'Y');

	system("pause");
	return  0;
}