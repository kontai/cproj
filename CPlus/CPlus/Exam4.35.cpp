#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string> 
#include<vector>
#include<cstring>

using namespace std;

int mainEXAM() {
	string ins;
	vector<string> vs;

	while (cin >> ins) {
		vs.push_back(ins);
	}

	char **pss = new char*[vs.size()];
	for (vector<string>::iterator  index = vs.begin();index != vs.end();index++,*pss++) {
		char *p = new char((*index).size() + 1);
		strcpy(p, (*index).c_str());
		*pss = p;
		cout << *pss << endl;
	}

	for (int i = 0;i != vs.size();i++) {
		delete [] pss[i];
	}
	delete []  pss;


	/*
	//array of int initialize vector//

		const size_t arr_size = 10;
		int arr[arr_size] = { 0,1,2,3,4,5,6,7,8,9 };
		vector<int>vec(arr,arr+10);
		cout << vec[9] << endl;
	*/
/*
	//array of int initialize vector//
	vector<int>vin = { 0,1,2,3,4,5,6,7,8,9 };
	int *asp = new int[vin.size()+1]();
	int j = 0;
	for (vector<int>::iterator i = vin.begin();i != vin.end() ;i++,j++) {
		asp[j] = *i;
		cout << "ar[" << j << "]=" << asp[j] << endl;
	}
	delete[] asp;
	*/

	system("pause");




	return 0;
}