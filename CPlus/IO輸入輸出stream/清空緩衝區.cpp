#include<iostream>

using namespace std;
//��{���Y���,�w�İϤ��|�۰ʲM��
//�`�`�Q��<�̫�@�ӿ�X>�ӧP�_���~���ͦ�m
//�n�T�{��X����T�����w�M���X�w�İ�,���U�����
int mainClearnBuff() {
	cout << "test" << flush;		//�M�Žw�İ�,���[������
	cout << "test2" << ends;	//�M�Žw�İ�,�����[�Wnull�r��
	cout << "test3" << endl;		//�M�Žw�İ�,�����[�W'\n'�����

	cout << unitbuf << "hello!" << "set1" << "set2" << nounitbuf;
	/*�W�����P
	cout <<   "hello!" << flush<< "set1" <<flush<< "set2"<<flush ;
*/
	system("pause");
	return 0;
}