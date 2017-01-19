#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

void main()
{
	char(*Cname)[20];
	char(*Cnum)[10];
	char(*Caddr)[50];
	int numOfPerson = 0;
	printf("how many people:");
	scanf("%d", &numOfPerson);
	Cname = (char(*)[20])malloc(numOfPerson * sizeof(char[20]));
	Cnum = (char(*)[10])malloc(numOfPerson * sizeof(char[10]));
	Caddr = (char(*)[50])malloc(numOfPerson * sizeof(char[50]));




	system("pause");
}