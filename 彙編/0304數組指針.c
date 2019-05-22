/*
2019/03/28 10:38:58
0304數組指針.c
*/

/*
1、*() 與 []是可以互換的，也就是說：

*(*(p+1)+2) 相當與 p[1][2]

那*(p+1)[2] 是否一定等於p[1][2]呢？ 通過反彙編進行論證。

2、使用陣列指標遍歷一個一維陣列.

*/
#include<stdio.h>
#include<stdlib.h>

void main0304() {
	char arr[] = { 1,2,3,4,5,6,7,8,9 };
	char(*p)[2] = (char(*)[2])arr;
	char tmp = (*p)[2];
	//	printf("%d\n", tmp);
	tmp = (*(p+1))[2];
	printf("%d\n", tmp);
	tmp = *(*(p)+1);
	printf("%d\n", tmp);
	//	char tmp2 = p[1][2];

	system("pause");
}