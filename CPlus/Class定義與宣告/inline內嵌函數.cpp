/****************************************
[3/29/2017  21:11]
inline���O���.cpp
****************************************/

#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

//���O��ƬO�b�@�몺��ƫe���A�[�Winline�o������r�A�Ҧp�H�U���Ҥl
//���O��ƬO�Ψӥ[�tC++������t�סA�b�{���X���y�k�W���|������Ӥj���t���A���O�bCompiler�sĶ�ɡA�o�|�����@�˪��ĪG
// �@��Ө��A��ڭ̼��g��ơA�éI�s�ϥΡA�q���������y�����O�|�����ثe�u�@���q���O�����}�A�M����ܨ�ƪ��O�����m�B�z���{�ǫ�A�æ^��������}�W�A�ӳo�˨Ӧ^�|�y���ɶ��W���B�~�t��C

//C++��O���ѳo�ؤ��O��ơA��ڭ̥[�J����r�ɡA�b�sĶ�ɫK�|���Ƥ����{�������i�}

//�Y�K�[�Jinline�Q�n�ϥΤ��O��ơA�sĶ�ɤ]���@�w�N�|��@�A�sĶ���|��ܡA�p�G�A���檺��Ƥ��{���X�һݮɶ��j��B�z�I�s��ƪ��ɶ��A�h��`�٪��ɶ�����֡A�Ϥ��Y�O�A����Ƥ��{���X���檺�ɶ��ܵu�A�h�ϥΤ��e��ƥi�H�٥h���h���I�s��ƪ��ɶ��A�åB�p�G�`�`�|�ϥΨ즹��ơA�ϥΤ��O���Ĳv�]�|����n
//
//inline int sqa(int x)
//{
//	return x*x;
//}
//
//int mainInline(){
//	int val = 2;
//	sqa(val);  //inline:���B�����i�}��2*2
//
//
//
//system("pause");
//return 0;
//}

class Mala {
public:
	char text1();
	inline char text1(size_t r, size_t t2);
	Mala(string &str);
private:
	string content;
	size_t r, t2;
};