#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>


void main() {
	int a[10] = { 0 };
	int (*p)[10]=&a;
	for(int i=0;i<10;i++)
	printf("%d", *(*p + i));


	

	system("pause");
}