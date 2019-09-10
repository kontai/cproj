#include "string.h"

void main()
{
	setlocale(LC_ALL,"zh-TW");
	stringa string1;
	stringw string2;

//	init(&string1, 'a');
//	init(&string2, 'w');
	initwithstring(&string1, 'a', "abc");
	initwithstring(&string2, 'w', L"¥ìº¸´µ");
	show(&string1, 'a');
	show(&string2, 'w');

	system("pause");
}