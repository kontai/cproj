/*
2019/03/12 10:38:36
0205結構體數組.c
*/

#include<stdio.h>
#include<stdlib.h>

struct Monster {
	int x;
	int y;
}ms;

void set_val(struct Monster in[],int lenth) {
	for (int i = 0; i < lenth; i++) {
		in[i].x = i;
		in[i].y = i * 2;
	}
}

void main0205I(){
	
	struct Monster ss[10];
	set_val(ss,10);
	

	system("pause");
}