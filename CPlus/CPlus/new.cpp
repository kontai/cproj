#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	vector<int>inc;
	for (vector<int>::size_type i = 0;i < 10;i++) {
		inc.push_back(i);
	}
	//inc.clear();
	cout << inc.size()<<endl;


	system("pause");
	return 0;
}