#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int mainFstreamIO() {
	string ifile("c:\\temp\\1.txt");

	ifstream in;   //�Ы�ifstream,���j�w�ɮ�
	in.open("c:\\temp\\1.txt");	 //�I�sopen()�Nifstream����j�w����w�ɮ�
	//�H�W�⦡�@�Φp�P	ifstream in(ifile.c_str())
	//ifstream in(ifile.c_str()); //�Ы�ifstream,�ñN�L�j�w����w�ɮפW
	//�ɮצW�ٶ���C-String,��ĳ��string��Ƭ�c-string  string.c_str()

	ofstream out;  
	out.open("c:\\temp\\1.txt");
	//	ofstream out(ifile.c_str());	//�Ы�ofstream,�ñN�L�j�w����w�ɮפW

	if (!in) {
		cerr << "unable to open file!" << endl;
		system("pause");
		return -1;
	}

	in.close();	//����in
	out.close();	//����out
	in.open("c:\\2.txt");		//���ɮץؼ�,�n�������j�w

	system("pause");
	return 0;
}