#include "myStack.h"

struct SStack* intiStack()
{
	struct SStack* stack = (struct SStack*)malloc(sizeof(struct SStack));
	if (stack==NULL)
	{
		return NULL;
	}
	stack->m_size = 0;
	return stack;
}