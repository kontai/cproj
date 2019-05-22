#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Typedef_.h"

void mainY() {
	INFO st = { 10,"abc" };
	printf("%d,%s\n", st.num, st.str);
	IP sp;
	sp = (IP)malloc(sizeof(INFO));
	sprintf(sp->str, "def");
	printf("%s", sp->str);
	system("pause");
}