/*
2018/09/02 16:16:25
查找.cpp
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<process.h>

void run(void*p) {
	int  *pi = (int*)p;
	char ch[20] = { 0 };
	sprintf(ch, "第%d個訊息框", *pi);
	MessageBoxA(0, ch, "title", 0);
}

void main1(){
	int ar[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++) {
		_beginthread(run, 0, &ar[i]); //function,,實參
	//	HANDLE hd=(HANDLE)_beginthread(run, 0, &i);
	//	WaitForSingleObject(hd, INFINITE);
}
	system("pause");
}