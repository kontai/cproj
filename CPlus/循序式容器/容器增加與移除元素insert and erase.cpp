#include<iostream>
#include<string>
#include <list>
#include <vector>

using namespace std;

/*
  c.push_bask(t)		�K�[t�Ȩ�e��c������,��^void
  c.push_front(t)		�K�[t�Ȩ�e��c������,��^void
  c.insert(p,t)			�biterator p�ҫ���m���e�ݴ��Jt�Ȥ���,��^�@��iterator���V�s�K�[������
  c.insert(p,n,t)			�biterator p�ҫ���m���e�ݴ��Jn��t�Ȥ���,��^void
  c.insert(p,b,e)			�biterator p�ҫ���m���e�ݴ��Jiterator b �M e�Ҫ�ܪ��϶�����,��^void

//push_front()=>vector���䴩
 */
int mainInsertErase() {
	string word;
	vector<string> ivec;
	vector<string>::iterator first = ivec.begin(), last = ivec.end();
	while (cin >> word)					//�Q��insert()����b�e���e�ݲK�[����
	{
		first = ivec.insert(first, word);		//�ĪG���Ppush_front()   �Q��insert()���Nvector���䴩��push_front()
		cout << *first << "  " << &first << endl;
	}
	/*
		while(first!=last)
		{
			first = ivec.insert(first, "abc");  //insert�s����,�|�ϭ쥻�O�s��end��m����,�y���L�a�j��
			first++;
		}
	*/
	int i = 0;
	while (first != ivec.end())			//�C���^���s�e������,�קK�O�s�T�w��������m,�y�����`��
	{
		cout << ivec.front() << '\t' << ivec.size() << endl;
		first = ivec.insert(first, "abc");
		first += 2;
	}
	system("pause");
	return 0;
}