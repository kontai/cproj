#include<iostream>

using namespace std;

int main() {

	int a = 1;
	int b = 2;
	if (a++ > 0 || b++ > 0) {
		cout << a <<' '<<b<< endl;
	}

	system("pause");

	return 0;
}
