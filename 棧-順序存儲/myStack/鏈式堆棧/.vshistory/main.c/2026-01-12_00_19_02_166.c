#include "LinkStack.h"


struct Person
{
	struct LinkNode* node;
	char* name;
	int age;
};

int main()
{
	struct LinkList *myList= initList();

	struct Person person1={NULL,"aaa",10};
	struct Person person2 = { NULL,"bbb",20 };
	struct Person person3 = { NULL,"ccc",30 };
	struct Person person4 = { NULL,"ddd",40 };
	struct Person person5 = { NULL,"eee",50 };

	pushData(myList, &person1);
	pushData(myList, &person2);
	pushData(myList, &person3);
	pushData(myList, &person4);
	pushData(myList, &person5);



	return EXIT_SUCCESS;
}