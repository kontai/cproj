#include<iostream>
#include<string>

using namespace std;

/*
 pairs �������Ѫ��ާ@

 pair<T1, T2> �Ыؤ@�ӪŪ� pair ����A������Ӥ������O�O T1 �M T2 p1; 	�����A�ĥέȪ�l�ơ]�� 3.3.1 �`�^

 pair<T1, T2> p1(v1, v2); �Ыؤ@�� pair ����A������Ӥ������O�O T1 �M T2 �A�䤤 first ������l�Ƭ� v1�A�� second ������l�Ƭ� v2

make_pair(v1, �H v1 �M v2 �ȳЫؤ@�ӷs pair ����A�䤸���������O�O v2) 	v1 �M v2 ������

 p1 < p2 	��� pair ���󤧶����p��B��A��w�q��`�r�妸�ǡG�p�G p1.first < p2.first �Ϊ� !(p2.first < p1.first) &&  p1.second < p2.second�A�h��^ true

 p1 == p2 	�p�G��� pair ���� first �M second �����̦��۵��A�h�o��ӹ�H�۵��C�ӹB��ϥΨ䤸���� == �ާ@��

 p.first 	��^ p ���W�� first ���]�����^��Ʀ���
 p.second 	��^ p ���W�� second ���]�����^��Ʀ���

 */

typedef pair<string, string> Author;

int mainPair() {
	//Author pstr("honor", "return"); �ϥ�typedef²�ƪ�l��
	pair<string, string> pstr;
	string first_s, second_s;
	while (cin >> first_s >> second_s) {
		pstr = make_pair(first_s, second_s);  //�Q��make_pair��l��,��_�U��,����T���pair�欰
	//	pstr = pair<string, string>(first_s, second_s);	�@�Φp�W
	}
	//while(cin>>pstr.first>>pstr.second)  //pair�����ܼƬOpublic,�ҥH�i������l�Ʀ���

	system("pause");
	return 0;
}