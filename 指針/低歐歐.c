

#include "stdafx.h"
//尹成ch5 指針 第一講 5.3.1-5 <dll注入>
void main111111111()
{
	int num = 0;
	printf("%x\n", &num);

	while (1)
	{
		num++;
		printf("%d\n", num);
		Sleep(5000);
	}

	system("pause");
}

