#include<iostream>
#include<string>
#include<cctype>

using namespace std;

//substr : �l�r��
//append : ���[�ܦr�����
//replace : ������,�M�ᴡ�J�r��(erase + insert) ,�����P���J���ƥؤ����ۦP
int mainString() {
	string s("Hello,world!");
	cout << "s= " << s << endl;
	string s2 = s.substr(6, 5);   // substr(pos, n);   from pos to n
	cout << "s2= " << s2 << endl;
	string s3 = s.substr(6);   // substr(pos, n);   from pos to end;
	cout << "s3= " << s3 << endl;

	string s4 = s.append("\t\aanother word");
	cout << "s4= " << s4 << endl;

	string s5 = s4.replace(0, 12, "everything change");
	cout << "s5= " << s5 << endl;

	s4.erase();
	cout << "s4= " << s4 << endl;

	system("pause");
	return 0;
}