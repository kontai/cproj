/*
2018/09/02 16:16:25
�d��.cpp
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>

void run(void*p) {
	int  *pi = (int*)p;
	char ch[20] = { 0 };
	sprintf(ch, "��%d�ӰT����", *pi);
	MessageBoxA(0, ch, "title", 0);
}

void main1(){
	int ar[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++) {
		_beginthread(run, 0, &ar[i]); //function,,���
	//	HANDLE hd=(HANDLE)_beginthread(run, 0, &i);
	//	WaitForSingleObject(hd, INFINITE);
}
	system("pause");
}