#include"myarray.h"

void main() {
	struct Data ar1;
	int a1[] = { 0,1,2,3,4,5,6,7,8,9 };
	initWithArray(&ar1, a1, sizeof(a1)/sizeof(*a1));
	show(&ar1);


	system("pause");
}