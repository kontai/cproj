// 結構.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void main()
{
	int i = 0;
	int num=0;
	while(1)
	{
		num += 1;
		printf("%d\n", num);
		Sleep(1000);
	}
	system("pause");
	
}

