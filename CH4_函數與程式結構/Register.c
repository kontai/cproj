/*
2018/11/04 15:07:06
Register.c
*/

#include<stdio.h>
#include<stdlib.h>


void	myfun(register unsigned , register unsigned long );   //可以對頻繁使用的變數設定為暫存器變數(但編譯器可以決定是否使用)
void main(){
	myfun(22, 33);


	system("pause");
}

void	myfun(register unsigned m, register unsigned long n) {
	printf("m=%p,n=%p\n", &m, &n);	//無法取得暫存器變數位址
}
