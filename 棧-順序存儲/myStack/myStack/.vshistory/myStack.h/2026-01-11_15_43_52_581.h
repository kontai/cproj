#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a simple stack structure
struct SStack
{
	void* data[1024];;
	int m_size;
};


typedef void(*Stacks);


//initailize stack
struct SStack* intiStack();

//push data
void pushData(struct SStack* stack,void* data)
{
	if (stack==NULL)
	{
		return ;
	}
	if (data==NULL)
	{
		return;
	}

	//push data
	stack->data[stack->m_size] = data;
	stack->m_size++;

}
