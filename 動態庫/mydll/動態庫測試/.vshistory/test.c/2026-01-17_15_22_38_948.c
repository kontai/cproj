#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "mydll.h"
#pragma comment(lib,"./mydll.lib")

/*
*2026/01/17
*AuTHOR:kontai
*
*/
int main() {
	printf("%d\n",mySub(30, 20));
	return EXIT_SUCCESS;
}