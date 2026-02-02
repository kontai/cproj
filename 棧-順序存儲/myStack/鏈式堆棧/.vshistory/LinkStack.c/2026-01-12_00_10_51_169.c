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
	struct LinkNode* node;
	char* name;
	int age;
};

//initailize the stack
struct LinkList* initList()
{
	struct LinkList* linklist = malloc(sizeof(struct LinkList));
	if (linklist == NULL)
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
	if (linklist == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	data->node = linklist->pheadNode.next;
	linklist->pheadNode.next = data->node;
	linklist->m_size++;
}

//pop an element from the stack
struct LinkNode* popData(struct LinkList* linklist)
{
	if (linklist == NULL)
	{
		return NULL;
	}
	if (linklist->m_size==0)
	{
		return NULL;
	}
	struct Person* p = linklist->pheadNode.next;
	linklist->pheadNode.next = p->node;
	linklist->m_size--;
	return p;
}

//check if the stack is empty
int isEmpty(struct LinkList* linklist)
{
	if (linklist==NULL)
	{
		return -1;
	}
	return linklist->m_size == 0;	//1 means empty,0 means not empty
}

//get the size of the stack
int getSize(struct LinkList* linklist)
{
	if (linklist==NULL)
	{
		return -1;
	}
	return linklist->m_size;
	
}

//clear the stack
void clearStack(struct LinkList* linklist)
{
	if (linklist==NULL)
	{
		return;
	}
	free(linklist);
	linklist = NULL;
}
