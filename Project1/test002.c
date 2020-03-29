/*
2020/03/22 20:59:29
test002.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include <time.h>

void main(){
	time_t result = time(NULL);
	//printf("%d\n",gmtime(&result)->tm_yday);
	printf("localtime:%s\n",asctime(localtime(&result)));
	printf("asctime:%s\n",asctime(gmtime(&result)));
	printf("ctime:%s\n",ctime(&result));
	
	//printf("%s\n", asctime(&result));

	system("pause");
}