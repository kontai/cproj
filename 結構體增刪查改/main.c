#include"myarray.h"

void main() {
	struct Data ar1;
	int a1[] = { 0,1,2,3,4,5,6,7,8,9 };
	initWithArray(&ar1, a1, sizeof(a1)/sizeof(*a1));

	addObject(&ar1, 34);
	show(&ar1);

	int a2[] = { 1,2,3,4,5,6,7,8,9,10,11,12 };


	addArray(&ar1, a2,sizeof(a2)/sizeof(*a2));
	show(&ar1);

	insertObject(&ar1, 2, 992);
	show(&ar1);

	insertArray(&ar1, 3, a1, sizeof(a1) / sizeof(*a1));
	show(&ar1);
	system("pause");
}