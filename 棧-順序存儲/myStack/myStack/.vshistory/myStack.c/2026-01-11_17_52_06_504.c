#include "myStack.h"
//ªì©l¤Æ
struct SStack* initStack()
{
	struct SStack* stack = (struct SStack*)malloc(sizeof(struct SStack));
	if (stack==NULL)
	{
		return NULL;
	}

	//initialize data
	memset(stack->data, 0, MAX);
	stack->m_size = 0;
	return stack;
}
void pushData(void* stack, void* data)
{
	struct SStack* my_stack = stack;
	if (stack==NULL)
	{
		return ;
	}
	if (data==NULL)
	{
		return;
	}

	//push data
	my_stack->data[my_stack->m_size] = data;
	my_stack->m_size++;

}

void* popData(void* stack)
{
	struct SStack* my_stack = stack;
	if (stack==NULL)
	{
		return NULL;
	}
	if (my_stack->data==0)
	{
		return NULL;
	}
	void* myData = my_stack->data[my_stack->m_size - 1];
	my_stack->m_size--;

	return myData;
}

int isEmpty(const struct SStack *stack)
{
	if (stack==NULL)
	{
		return -1;	//not available stack
	}
	if (stack->m_size==0)
	{
		return 1;	//empty
	}
	return 0;	//not empty;
}


void showAllStack(void* stack, void(*print_data)(void*))
{
	struct SStack *my_stack = stack;
	int len = my_stack->m_size;
	for (int i=0;i<len;i++)
	{
		print_data(popData(stack));
	}
}


