#include"myStack.h"

void printData(void* data)
{
	struct Person* p = data;
	printf("%s,%d\n", p->name, p->age);
}

int main()
{
	Stacks myStack = initStack();
	//struct SStack* s = initStack();
	//s->m_size = 909;	//不完整的类型不能访问成员

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



	return EXIT_SUCCESS;
}
