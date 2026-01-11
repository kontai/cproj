#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct SStack
{
	void* data[1024];;
	int m_size;
};

typedef void(*Stacks);
