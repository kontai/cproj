#include "myStack.h"

//ªì©l¤Æ
struct SStack* initStack()
{
	struct SStack* stack = (struct SStack*)malloc(sizeof(struct SStack));
	if (stack==NULL)
	{
		return NULL;
	}
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

void* popData(struct SStack *stack)
{
	if (stack==NULL)
	{
		return;
	}
	void* myData = stack->data[stack->m_size - 1];
	stack->m_size--;

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


void showAllStack(struct SStack* stack, void(*print_data)(void*))
{
	for (int i=0;i<stack->m_size;i++)
	{
		print_data(popData(stack));
	}
}


