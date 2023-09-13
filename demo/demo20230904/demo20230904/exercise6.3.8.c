#include<stdlib.h>
#include<stdio.h>

/*
*file:exercise6.3.8.c
*Date:2023/09/04
*Description:
*/

int main_exe638(void) {
	int i;
	for (i = 10; i >= 1; i /= 2)
	{
		printf("%d ", i++);
	}
}
