#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

/*
*file:file_control.c
*Date:2023/09/30
*Description:
*/

#if 0
#define BUFSIZ 4

int main(void) {
	FILE* fp;
	char ar[BUFSIZ] = { 0 };
	fp = fopen("1.txt", "w");
	if (fp == NULL) {
		printf("file can't create.");
		exit(EXIT_FAILURE);
	}
	setvbuf(fp, ar, _IOFBF, BUFSIZ);
	fprintf(fp, "HELLO abc");
	printf("%s\n", ar);
	fflush(fp);
	fclose(fp);

	return 0;
}
#endif

#define BUFSIZ 4

int main(void) {
	FILE* fp;
	char ar[BUFSIZ] = { 0 };
	fp = fopen("1.txt", "w");
	if (fp == NULL) {
		printf("file can't create.");
		exit(EXIT_FAILURE);
	}
	setvbuf(fp, ar, _IOFBF, BUFSIZ);
	fprintf(fp, "HELLO abc");
	printf("%s\n", ar);
	fflush(fp);
	fclose(fp);

	return 0;
}

