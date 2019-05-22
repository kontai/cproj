/*
2019/03/03 11:30:12
緩衝區溢出.c
*/

#include<stdio.h>
#include<stdlib.h>

//基于缓冲区溢出的HelloWorld					
void HelloWord()					
{					
	printf("Hello World");				
					
	getchar();				
}					
/*void Fun()
{
	int arr[5] = {1,2,3,4,5};

	arr[6] = (int)HelloWord;

}	*/
					
//永不停止的HelloWorld					
void Fun()					
{					
	int i;				
	int arr[5] = {0};				
					
	for(i=0;i<=5;i++)				
	{				
		arr[i] = 0;			
		printf("Hello World!\n");			
	}				
}					

				


void main0129(){
	Fun();
	

	system("pause");
}