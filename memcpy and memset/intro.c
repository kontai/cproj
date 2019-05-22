/*
2018/11/11 16:20:16
intro.c
*/

#include<stdio.h>
#include<stdlib.h>

void main(){
	char *ch = { "test string" };
	int a[] = { 0,1,2,3,4,5,6,7,8,9,10 };
	double b[] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9 };

	char *pc = malloc(sizeof(char)*strlen(ch));
	memcpy(pc, ch, strlen(ch) );
	printf("%s\n", pc);

	memset(pc, 'A', strlen(pc));

	system("pause");
}