#include <iostream>
#include<numeric>
#include <vector>

using namespace std;

int mainAccumulate() {
	vector<int>ivec;
	cout << "Enter number (CTRL+Z  to end):" << endl;
	int anynum;
	while (cin >> anynum)
		ivec.push_back(anynum);
	//accumulate(t1,t2,n)   :�p�⤸���`�M;t1�����_�l,t2��������,n��l��; n+t[x]+t[x+1]+.....+t[x+y]
	cout << accumulate(ivec.begin(), ivec.end(), 5);

//�N���w�϶���0
	fill(ivec.begin(), ivec.end(), 0); 


	system("pause");
	return 0;
}