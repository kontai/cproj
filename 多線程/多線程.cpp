/*
2018/09/02 13:59:13
�h�u�{.cpp
*/

#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#include<Windows.h>

void run1(void* p) {
	MessageBoxA(0, "test text", "run1", 0);
}

void run2(void* p) {
	MessageBoxA(0, "test text", "run2", 0);
}
void run3(void* p) {
	MessageBoxA(0, "test text", "run3", 0);
}
void main2() {
	// HANDLE hd[3] = { 0 };(��)
	HANDLE *hd = (HANDLE*)malloc(12);//(��---�ʺA���s���t)
	void(*pfun[3])(void*p) = { run1,run2,run3 }; //��ƫ��w�Ʋ� 
	//void(**pfun)(void*p) = (void(**)(void*))malloc(sizeof(void*)*3);
	for (int i = 0; i < 3; i++)
	{
	hd[i]=	(HANDLE) _beginthread(pfun[i], 0, NULL);
	}

	WaitForMultipleObjects(3, hd, true, INFINITE); //���ݦh�ӽu�{����
//	WaitForMultipleObjects(3, hd, true, 3000); //����3000ms(3s)
										//�L������


	//system("pause");
}