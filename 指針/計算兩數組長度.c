/*
2018/11/04 18:40:57
計算兩數組長度.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>


void main3() {
	char ch[1000];
	size_t ptr_size = sizeof(ch) / sizeof(ch[0]);
	printf("%d\n", ptr_size);
	printf("%d\n", ptrdiff(ch));

	system("pause");
}

// ptrdiff_t 足夠存放兩數組間大小
ptrdiff_t ptrdiff(char *s) {
	char *p = s;
	while (*p != '\0')
		p++;
	return p - s;
}
