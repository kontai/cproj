/*
2019/03/12 11:09:17
0205µ≤∫c≈ÈπÔªÙ.c
*/

#include<stdio.h>
#include<stdlib.h>

struct S1 {
	char c;
	double i;
}s1;

struct S2 {
	char c1;
	struct S1 s;
	char c2;
	char c3;
}s2;

struct S3 {
	char c1;
	struct S1 s;
	char c2;
	double c3;
}s3;

struct S4 {
	int c1;
	char c2[10];
}s4;

void main0205II() {
	printf("S1\t%d\n", sizeof(s1));
	printf("S2\t%d\n", sizeof(s2));
	printf("S3\t%d\n", sizeof(s3));
	printf("S4\t%d\n", sizeof(s4));


	system("pause");
}