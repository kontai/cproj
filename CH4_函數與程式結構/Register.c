/*
2018/11/04 15:07:06
Register.c
*/

#include<stdio.h>
#include<stdlib.h>


void	myfun(register unsigned , register unsigned long );   //�i�H���W�c�ϥΪ��ܼƳ]�w���Ȧs���ܼ�(���sĶ���i�H�M�w�O�_�ϥ�)
void main(){
	myfun(22, 33);


	system("pause");
}

void	myfun(register unsigned m, register unsigned long n) {
	printf("m=%p,n=%p\n", &m, &n);	//�L�k���o�Ȧs���ܼƦ�}
}
