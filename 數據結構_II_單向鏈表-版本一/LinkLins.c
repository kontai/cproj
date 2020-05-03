#include "LinkLins.h"

//節點結構體
struct LinkNode
{
	//data可以指向任何
	void* data;
	//next 指向下一個節點
	struct LinkNode* next;
};
//鏈表信息結構體
struct LList
{
	//保存頭結點的地址
	struct LinkNode header;
	//保存鏈表的節點
	int size;
};

LinkList Init_LinkList()//初始化鏈表(用鏈表結構體)
{
	//開闢一塊內存，
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

//用鏈表信息結構體，插入新節點
//首先接收一個void *類型
//pos要插入得位置
void Insert_LinkList(LinkList list, int pos, void* data)//插入節點
{
	if (NULL == data)
	{
		return;
	}

	if (NULL == list)
	{
		return;
	}
	//輔助指針，輔助結構體信息指針
	struct LList* mylist = (struct LList*)list;
	//如果pos<0後或大於最大節點就在最後插入
	if (pos < 0 || pos > mylist->size)
	{
		pos = mylist->size;
	}

	struct LinkNode* pCurrent = &(mylist->header);

	//循環找到pos之前的節點
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//開闢新的節點把數值傳遞給他，並把這個節點鏈接
	struct LinkNode* newnode = malloc(sizeof(struct LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//前插
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;
	//節點增加一個
	mylist->size++;
}

void Foreach_LinkList(LinkList list, FOREACH myforeach)//遍歷節點
{
	if (NULL == list)
	{
		return;
	}
	if (NULL == myforeach)
	{
		return;
	}
	//
	struct LList* mylist = (struct LList*)list;

	struct LinkNode* pCurrent = mylist->header.next;
	while (pCurrent != NULL)
	{
		myforeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

void RemoveByPos_LinkList(LinkList list, int pos)//按位置刪除
{
	if (NULL == list)
	{
		return;
	}
	//輔助節點
	struct LList* mylist = (struct LList*)list;

	//這個是刪除，如果沒有找到就直接返回
	if (pos < 0 || pos > mylist->size)
	{
		return;
	}

	//找到這個位置
	struct LinkNode* myheader = &(mylist->header);
	//兩個輔助指針，保存前面的，和後面的
	struct LinkNode* pCurrent = myheader->next;
	//一直循環直到找的pos節點
	for (int i = 0; i < pos; ++i)
	{
		myheader = pCurrent;
		pCurrent = pCurrent->next;
	}
	//直接讓他的前驅節點的next鏈接它的後驅節點
	myheader->next = pCurrent->next;
	free(pCurrent);
	pCurrent = NULL;
	mylist->size--;
}
//按值刪除
//傳入鏈表信息結構
//傳入一個節點
//一個回調函數，用戶自己編寫
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

	//兩個輔助節點
	struct LinkNode* myliknode = &(mylist->header);
	struct LinkNode* pCurrrent = myliknode->next;
	//
	while (pCurrrent != NULL)
	{	//pCurrent->data指向一個結構體
		if (compare(pCurrrent->data, data))
		{
			//刪除節點，並釋放
			myliknode->next = pCurrrent->next;
			free(pCurrrent);
			pCurrrent = NULL;
			mylist->size--;
			break;
		}
		myliknode = pCurrrent;
		pCurrrent = pCurrrent->next;
	}
}

void Clear_LinkList(LinkList list)//清空鏈表
{
	if (NULL == list)
	{
		return;
	}
	//
	struct LList* mylist = (struct LList*)list;
	struct LinkNode* myheadder = mylist->header.next;
	struct LinkNode* mynext = NULL;
	while (myheadder->next != NULL)
	{
		mynext = myheadder->next;
		free(myheadder);
		myheadder = mynext;
	}
	mylist->header.next = NULL;
}

int Size_LinkList(LinkList list)//鏈表節點個數
{
	if (NULL == list)
	{
		return -1;
	}
	struct LList* mylist = (struct LList*)list;
	return mylist->size;
}

void Destroy_LinkList(LinkList list)//銷毀鏈表
{
	if (NULL == list)
	{
		return;
	}
	Size_LinkList(list);
	free(list);
	list = NULL;
}