#include<iostream>
#include <cassert>
#include <string>

using namespace std;

int mainNDEBUG() {
	/*
#ifndef NDEBUG
	cerr << "�qifndef��endif�������{���X,�u���b�}�o�ɷ|����"
			<< "\n�}�o����,���q�{���X�i�ǥ�#define NZDEBUG�Ӳ���";

	string str;
	cin >> str;
	assert(isupper(str[0]));
	//���r�D�j�g�r��,��^false,assert���_�{��,����ܿ��~�T��
	///////////////////
	assert : �D�зǮw���,�ӬO����NDEBAUG�ҩw�q
	#ifdef NDEBUG
	#define assert(condition) ((void)0)
	#else
	#define assert(condition) /*implementation defined*/
	//////////////////

	 /*
		 �i���X�T��
		 cerr << "�ɮ�:" << __FILE__
			 << "\n�ثe�渹:" << __LINE__
			 << "\n���:" << __DATE__
			 << "\n�ɶ�:" <<__TIME__;
	  */
	system("pause");
	return 0;
}