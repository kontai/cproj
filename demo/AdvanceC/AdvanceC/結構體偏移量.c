#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>

/*
*file:結構體偏移量.c
*Date:2025/08/23
*Description:
*/


struct stOffset
{
	char a;
	int b;
};

void test01()
{

	struct stOffset s1 = { 'a',2 };
	struct stOffset* s2 = &s1;;

	printf("offset:%d\n", (int)&(s2->b) - (int)s2);	//非標準寫法
	printf("offset:%d\n", offsetof(struct	stOffset, b));	//標準寫法


}

int main(void) {
	test01();
	return 0;
}
