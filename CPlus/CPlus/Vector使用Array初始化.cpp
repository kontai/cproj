#include<iostream>
#include <vector>

using namespace std;

int mainVectorInit() {
	const size_t Bit_size = 6;
	int arr[Bit_size] = { 0,1,2,3,4,5 };
	//vector�i�H�ϥ�array�����d��@��l��
	//�Ĥ@�ӰѼ�,�ǤJ�}�C��}�@���ҩl�d��
	//�ĤG�ӰѼ�,�q�ҩl�d��}�l��n�ƻs��"�̫�@�Ӥ������U�@�Ӧ�m"
	vector<int>vin(arr, arr + Bit_size);	 //arr[0] ~ arr[4]  
	vector<int>vin2(arr + 1, arr +5);		//arr[1],arr[2],arr[3],arr[4]; �|�Ӥ���,4+1(�̫�@�Ӥ������U�@�Ӧ�m)
	cout << vin[0] << endl;
	cout << vin2[0] << ' ' << vin2[3] << endl;
	char *sp = "abcdefg";
	vector<char>vin3(sp + 2, sp +4);		//�ϥ�sp[2],sp[3]��l��vin3
	cout << vin3[0] << ' ' << vin3[1] << endl;
	

	system("pause");

	return 0;
}