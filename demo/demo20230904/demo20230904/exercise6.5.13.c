#include<stdlib.h>
#include<stdio.h>

/*
*file:exercise6.5.13.c
*Date:2023/09/04
*Description:重寫循環,使循環體為空
*/

int main_exe6513(void) {
	int n, m = 1;
	short times = 0;
	for (n = 0; m > 0; n++, m /= 2) {
		;
		printf("%d\n", ++times);
	}


}
