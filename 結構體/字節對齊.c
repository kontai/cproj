#include "stdafx.h"
#include<stdio.h>
#include <stdlib.h>

/*
字節對齊優點:尋址方便

結構體字節對齊規則:
1.
各成員字節數能夠被最寬基本成員整除(字節數不足者.將自動填加填充字節,做字節對齊）
ps:最寬基本成員,char int double float ...;結構體、數駔都不是最寬基本成員

2.
結構體每個成員相對於結構體首地址的偏移量都是成員大小的整數倍.如有需要,編譯器會在成員之間加上填充字節(internal adding).



*/
	struct addA 
{
		
	short a;       //2+(2)  加上2的補充字節
	int b;           //4   ---max
	char c[9];   //9+(3) 加上3的補充字節 
};

	struct  addB 
{
		
	char a;       //1+(1)  加上2的補充字節
	short b;      //2   ---max
	char c[9];   //9+(1) 加上3的補充字節 , 才可被最寬基本成員整除
};

	struct  addC 
{
		
	int  a;         //4  ---max
	char b;       //1    
	char c[9];   //9   成員b 和 c 因是連續且同類型,位址將合併計算 1+9+(2)
};







void main()
{
	printf("%d\n", sizeof(struct addA));
	printf("%d\n", sizeof(struct addB));
	printf("%d\n", sizeof(struct addC));


	system("pause");
}