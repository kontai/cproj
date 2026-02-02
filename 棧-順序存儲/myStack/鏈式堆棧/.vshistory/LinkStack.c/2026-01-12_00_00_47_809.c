#include "LinkStack.h"

struct LinkNode
{
	struct LinkNode* next;
};

struct LinkList
{
	struct LinkNode pheadNode;
	int m_size;
};

struct Person
{
	struct LinkNode *node;
	char* name;
	int age;
};

//initailize the stack
struct LinkList* initList()
{
	struct LinkList* linklist = malloc(sizeof(struct LinkList));
	if (linklist==NULL)
	{
		return NULL;
	}
	linklist->pheadNode.next = NULL;
	linklist->m_size = 0;
	return linklist;
}

//push an element onto the stack
void pushData(struct LinkList* linklist, struct Person* data)
{
	if (linklist==NULL)
	{
		return;
	}
	if (data==NULL)
	{
		return;
	}
	data->node = linklist->pheadNode.next;
	linklist.pheadNode.next = data->node;
	linklist->m_size++;



}

//pop an element from the stack
struct LinkNode* popData(struct LinkList* linklist);

//check if the stack is empty
int isEmpty(struct LinkList* linklist);

//get the size of the stack
int getSize(struct LinkList* linklist);

//clear the stack
void clearStack(struct LinkList* linklist);
