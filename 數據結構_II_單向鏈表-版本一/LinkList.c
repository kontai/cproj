#include"LinkList.h"

//���`�I�ƾ�����
struct LinkNode
{
	void* data;
	struct LinkNode* next;
};

//���ƾ�����
struct LList
{
	struct LinkNode header;
	int size;
};

//��l�����
LinkList Init_LinkList()
{
	struct LList* list = malloc(sizeof(struct LList));
	if (NULL == list)
	{
		return NULL;
	}

	list->header.data = NULL;
	list->header.next = NULL;
	list->size = 0;

	return list;
}
//���J�`�I
void Insert_LinkList(LinkList list, int pos, void* data)
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	struct LList* mylist = (struct LList*)list;

	if (pos < 0 || pos > mylist->size)
	{
		pos = mylist->size;
	}

	//�d�䴡�J��m
	struct LinkNode* pCurrent = &(mylist->header);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//�Ыطs�`�I
	struct LinkNode* newnode = malloc(sizeof(struct LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//�s�`�I���J�����
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	mylist->size++;
}

//�M�����
void Foreach_LinkList(LinkList list, FOREACH myforeach) /*�^�ը��*/
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == myforeach)
	{
		return;
	}

	struct LList* mylist = (struct LList*)list;

	struct LinkNode* pCurrent = mylist->header.next;

	while (pCurrent != NULL)
	{
		myforeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

//����m�R��
void RemoveByPos_LinkList(LinkList list, int pos)
{
	if (NULL == list)
	{
		return;
	}

	struct LList* mylist = (struct LList*)list;

	if (pos < 0 || pos > mylist->size - 1)
	{
		return;
	}

	//���m
	struct LinkNode* pCurrent = &(mylist->header);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//���O�s�ݧR�����I
	struct LinkNode* pDel = pCurrent->next;
	//���s�إ߫ݧR�����I���e�X�M���~���I���Y
	pCurrent->next = pDel->next;
	//����R���`�I���s
	free(pDel);
	pDel = NULL;

	mylist->size--;
}
//���ȧR��
void RemoveByVal_LinkList(LinkList list, void* data, COMPARE compare)
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	if (NULL == compare)
	{
		return;
	}

	struct LList* mylist = (struct LList*)list;

	//���U���w�ܶq
	struct LinkNode* pPrev = &(mylist->header);
	struct LinkNode* pCurrent = pPrev->next;

	while (pCurrent != NULL)
	{
		if (compare(pCurrent->data, data))
		{
			//���F
			pPrev->next = pCurrent->next;
			//����R���`�I���s
			free(pCurrent);
			pCurrent = NULL;
			mylist->size--;
			break;
		}

		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}
//�M�����
void Clear_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return;
	}

	struct LList* mylist = (struct LList*)list;

	//���U���w�ܶq
	struct LinkNode* pCurrent = mylist->header.next;

	while (pCurrent != NULL)
	{
		//���w�s�U�@�Ӹ`�I���a�}
		struct LinkNode* pNext = pCurrent->next;
		//�����e���I���s
		free(pCurrent);

		pCurrent = pNext;
	}

	mylist->header.next = NULL;
	mylist->size = 0;
}
//�j�p
int Size_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return -1;
	}

	struct LList* mylist = (struct LList*)list;

	return mylist->size;
}
//�P�����
void Destroy_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return;
	}

	//�M�����
	Clear_LinkList(list);
	free(list);
	list = NULL;
}