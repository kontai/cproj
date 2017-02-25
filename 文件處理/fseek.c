#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <corecrt_io.h>

void main() {
	FILE *pf = fopen("d:\\1.txt", "r");
	FILE *pp = fopen("d:\\2.txt", "w");
	if(pf==NULL)
	{
		printf("file open fail;\n");
	}
	else 
	{

		fgets(pf, 100,stdin);
	}
	fclose(pf);
	
	fclose(pp);




	system("pause");

}
