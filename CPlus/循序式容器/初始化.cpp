#include<iostream>
#include<vector>
#include <list>
#include <deque>

using namespace std;

int main�e��() {
	vector<int>vec(10, 2);
	vector<int>::iterator iter = vec.begin() + vec.size() / 2;
	vector<int>::reverse_iterator	riter = vec.rbegin();  //riter ���Vvec�̫�@�Ӥ���

	list<int>ilist(vec.begin(), vec.end());
	//�϶����(first,last)
	//ilist������[vec.begin()] first �}�l,����[vec.end()] lastt ����	(���]�Avec.end())
	 //���İ϶�����:�������P�@�e�� , first�@�w�n�blast���e

	//ilist.begin() + ilist.size() / 2;	//���~,list iterator�����\�@�[��k(+ , - )�����Y�B��(>= , < , <= , >)
														//�u�䴩�e,��m++ , -- ,�H��== , !=
	system("pause");
	return 0;
}