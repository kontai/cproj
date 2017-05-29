/****************************************
[5/20/2017  14:39]
main.cpp
****************************************/

#include<iostream>
#include"plain-ptr.h"
#include"value-ptr.h"
#include"smart-ptr.h"
using namespace std;

void test_AHP()
{
	int i = 42;
	AHP p1(&i, 42);
	AHP p2 = p1;
	cout << p2.get_ptr_val() << endl;

	p1.set_ptr_val(0);
	cout << p2.get_ptr_val() << endl; //���p1,p2�]����ܧ�(�ƻs���w��m)

	int *ip = new int(42);
	AHP p3(ip, 20);
	cout << p3.get_ptr_val()<<endl;
	delete ip;
	cout << p3.get_ptr_val()<<endl; //�����w
}

void test_VAHP()
{
	int obj = 0;
	VAHP ptr1(obj, 42);
	VAHP ptr2(ptr1);
	cout << ptr2.get_ptr_val() << ","<<ptr2.get_int()<<endl;
	ptr1.set_ptr_val(25);
	ptr1.set_int(2);
	cout << ptr1.get_ptr_val() << ","<<ptr1.get_int()<<endl;
	cout << ptr2.get_ptr_val() << ","<<ptr2.get_int()<<endl;
	
}

void test_SAHP()
{
	int obj = 0;
	SAHP ptr1(&obj, 42);
	SAHP ptr2(ptr1);
	SAHP ptr3(&obj, 42);
	cout << ptr1.get_ptr_val() << "," << ptr1.get_int() << endl;
	cout << ptr2.get_ptr_val() << "," << ptr2.get_int() << endl;
	ptr1.set_ptr_val(25);
	cout << ptr1.get_ptr_val() << ","<<ptr1.get_int()<<endl;
	cout << ptr2.get_ptr_val() << ","<<ptr2.get_int()<<endl;
}

int main(){
	/*cout << "�`�W���w" << endl;
	test_AHP();
	cout << "�ȫ���" << endl;*/
	test_VAHP();
	cout << "���z����" << endl;
	test_SAHP();
	



system("pause");
return 0;
}