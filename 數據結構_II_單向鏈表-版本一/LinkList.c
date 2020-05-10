#include"LinkList.h"

//鏈表節點數據類型
struct LinkNode
{
	void* data;
	struct LinkNode* next;
};

//鏈表數據類型
struct LList
{
	struct LinkNode header;
	int size;
};

//初始化鏈表
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
//插入節點
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

	//查找插入位置
	struct LinkNode* pCurrent = &(mylist->header);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//創建新節點
	struct LinkNode* newnode = malloc(sizeof(struct LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//新節點插入到鏈表中
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;

	mylist->size++;
}

//遍歷鏈表
void Foreach_LinkList(LinkList list, FOREACH myforeach) /*回調函數*/
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

//按位置刪除
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

	//找位置
	struct LinkNode* pCurrent = &(mylist->header);
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//先保存待刪除結點
	struct LinkNode* pDel = pCurrent->next;
	//重新建立待刪除結點的前驅和後繼結點關係
	pCurrent->next = pDel->next;
	//釋放刪除節點內存
	free(pDel);
	pDel = NULL;

	mylist->size--;
}
//按值刪除
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

	//輔助指針變量
	struct LinkNode* pPrev = &(mylist->header);
	struct LinkNode* pCurrent = pPrev->next;

	while (pCurrent != NULL)
	{
		if (compare(pCurrent->data, data))
		{
			//找到了
			pPrev->next = pCurrent->next;
			//釋放刪除節點內存
			free(pCurrent);
			pCurrent = NULL;
			mylist->size--;
			break;
		}

		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
}
//清空鏈表
void Clear_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return;
	}

	struct LList* mylist = (struct LList*)list;

	//輔助指針變量
	struct LinkNode* pCurrent = mylist->header.next;

	while (pCurrent != NULL)
	{
		//先緩存下一個節點的地址
		struct LinkNode* pNext = pCurrent->next;
		//釋放當前結點內存
		free(pCurrent);

		pCurrent = pNext;
	}

	mylist->header.next = NULL;
	mylist->size = 0;
}
//大小
int Size_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return -1;
	}

	struct LList* mylist = (struct LList*)list;

	return mylist->size;
}
//銷毀鏈表
void Destroy_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return;
	}

	//清空鏈表
	Clear_LinkList(list);
	free(list);
	list = NULL;
}