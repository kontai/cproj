#include"myStack.h"

void printData(void* data)
{
	struct Person* p = data;
	printf("%s,%d", p->name, p->age);
}

void main()
{
	Stacks* myStack = initStack();

	struct Person p1={"aaa",1};
	struct Person p2={"bbb",2};
	struct Person p3={"ccc",3};
	struct Person p4={"ddd",4};
	struct Person p5={"eee",5};
	struct Person p6={"fff",6};

	pushData(myStack, &p1);
	pushData(myStack, &p2);
	pushData(myStack, &p3);
	pushData(myStack, &p4);
	pushData(myStack, &p5);
	pushData(myStack, &p6);

	showAllStack(myStack, printData);



	EXIT_SUCCESS;
}
