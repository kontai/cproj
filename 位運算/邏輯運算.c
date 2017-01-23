#include <stdio.h>
#include <stdlib.h>

struct my_struct
{
	int a:1;
	int b:1;
	//int c:14;
};

void main()
{
	struct my_struct a;
	printf("%p\n", &a);

	system("pause");
}

