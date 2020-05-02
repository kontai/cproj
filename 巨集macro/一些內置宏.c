/*

ANSI标准定义了几个个预定义的宏名。它们包括但不止于：

__LINE__
__FILE__
__DATE__
__TIME__
__STDC__

*/
#include<stdio.h>
//#include<stdlib.h>

#ifdef _DEBUG
#define DEBUGMSG(msg,date) printf(msg);printf("\ndate:%d\nLine:%d\nFile:%s\n", date, __LINE__, __FILE__)
#else
#define DEBUGMSG(msg,date)
#endif



void main()
{
	DEBUGMSG("TEST MESSAGE:", 2020);
	system("pause");
}