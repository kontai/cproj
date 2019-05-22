/*
2018/11/10 9:33:29
動態分配-二級指針.c
*/

#include<stdio.h>
#include<stdlib.h>

void main(){
	int(*ar)[10] = malloc(sizeof(int) * 30);
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 10; j++)
		{
			ar[i][j] = i * 10 + j;
			//printf("%d\n", ar[i][j]);
		}
	free(ar);

	int(*ar3)[5][4] = malloc(sizeof(int) * 40);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 4; k++)
			{
				ar3[i][j][k] = i * 20 + j * 4 + k;
				//printf("%d\t", ar3[i][j][k]);
				printf("%d\t", *(*(ar + i) + j)+k) ;
			}

	free(ar3);
	ar3 = NULL;


	system("pause");
}