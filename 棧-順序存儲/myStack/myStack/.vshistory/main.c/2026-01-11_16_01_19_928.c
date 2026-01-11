#include"myStack.h"

void printData(void* data)
{
	struct Person* p = data;
	printf("%s,%d", p->name, p->age);
}

void main()
{
	Stacks* myStack = initStack();




	EXIT_SUCCESS;
}
