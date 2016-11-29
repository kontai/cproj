#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct Cstring
{
	char *p;
	int truestr;
};


typedef  struct  Cstring tai_string;

void init(tai_string *str);
void init_strwid(tai_string *str, int len);
void init_strstr(tai_string *str, char *cpstr);
void print_str(tai_string *str);
