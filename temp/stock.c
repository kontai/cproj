/*
2019/02/04 9:34:25
stock.c
*/

#include<stdio.h>
#include<stdlib.h>

int Plus1(int x, int y) {
	return x + y;
}

int Plus2(int x, int y, int z) {
	int t = 0;
	int r = 0;
	r = Plus1(2, 3);
	t = Plus1(r, z);
	return t;
}

int Plus3(int v, int w, int x, int y, int z) {
	int t = 0;
	int r = 0;
	t = Plus2(v, w, x);
	r = Plus2(t, y, z);
	return r;
}

int mainA(){
	//Plus1(2, 3);
	//Plus2(2, 3,4);
	Plus3(2, 3, 4, 5, 6);
	system("pause");
	return 0;
}