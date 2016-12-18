#include "stdafx.h"
#include <stdio.h>
#include<stdlib.h>



void main() {
	char ppap[6][5] = { "abcd","aaaa","bbbb","cccc","dddd","eeee" };
	printf("%p\n", (ppap+2)[1]);
	printf("%p", (ppap+3)[1]);
	


	system("pause");
}