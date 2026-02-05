#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>

/*
*file:demo.c
*Date:2023/09/13
*Description:
*/
//#define MAX(a,b) ((a)>(b)?(a):(b))
//#define PRINT_INT(n) printf(#n"=%d\n",n)
//#define GENERIC_MAX(type)			\
//	type type##MAX(type x,type y)	\
//{									\
//return x>y?x:y;						\
//}
#define GENERIC_MAX(type) \
type type##_MAX(type x, type y) \
{ \
    return x > y ? x : y; \
}


int main(void) {
	//int i = 2, j = 3, k = 4;
	float x = 3.13f, y = 93.22f;
	//printf("max: %d\n", MAX(i, MAX(j, k)));
	//PRINT_INT(i);
	float result = GENERIC_MAX(float)(x, y);
	printf("GENERIC_MAX: %f\n", result);

	//printf("GENERIC_MAX: %f\n", GENERIC_MAX(float)(x, y));

	return 0;
}
