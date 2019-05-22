/*
2018/11/10 14:47:41
指針數組.c
*/

#include<stdio.h>
#include<stdlib.h>

void main3(){
	int num = 10;
	int a[10];
	//int b[num];  //棧上動態數組.gcc才適用
	//a = (int[12]) { 0 };a是常量

	int(*p)[10]; //動態分配內存,系統不會自動回收空間
	int *pc = (int[]) { [1] = 34 }; //pc是變量,於編譯時棧上靜態分配內存,
	pc = (int[20]) { 0 };  //重新賦予數組,舊的內存空間將不可再使用

	int (*p2)[4] = (int[][4]) { 0 };
	int (*p3)[][4] = (int[][4]) { 0 };


	system("pause");
}