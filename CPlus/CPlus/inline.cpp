#include<iostream>
#include <string>

using namespace std;


inline	const  int  call()			//�b��ƪ�^���e�ϥ�inline,�|�b�禡�I�s�I�i��(�椺in line)�X�i,�קK�ӥ~�}�P(���u���Ω�p���禡)
												//�ϥ�inline,���N�禡�w�q����Y��,���ѽsĶ���i���X�i
{
	static  int a = 0;
	return a++;
}

int mainLine()
{
	int a = 0;
	while ((a = call()) < 20)		//���Bcall()�X�i��a++;
		cout << a << endl;

	system("pause");
	return 0;
}