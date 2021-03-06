#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*

此鏈表形式
優點：
1.無須malloc
2.代碼較簡潔
3.隱藏數據(?)

缺點：
1.用戶需要於結構體中附上Node,供鏈表使用
2.無法插入重複的Node (會造成無限循環∞)


*/

//鏈表節點數據結構
struct LinkNode
{
	struct LinkNode *next;
};


//鏈表結構體
struct LList
{
	struct LinkNode header; //頭結點
	int size;
};

typedef void * LinkList;


//初始化鏈表
LinkList Init_LinkList()
{

	struct LList *list = malloc(sizeof(struct LList));
	if (NULL == list)
	{
		return NULL;
	}

	list->header.next = NULL;
	list->size = 0;

	return list;
}


void Insert_LinkList(LinkList list, int position, void *data)
{
	if (NULL == list)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	struct LList * mylist = (struct LList *)list;
	struct LinkNode *mynode = (struct LinkNode *)data;


	if (position < 0 || position > mylist->size)
	{
		position = mylist->size;
	}


	//找位置(找到position位置的前一個位置)
	struct LinkNode *pCurrent = &(mylist->header);
	for (int i = 0; i < position; ++i)
	{
		pCurrent = pCurrent->next;
	}


	//數據入鏈表
	mynode->next = pCurrent->next;
	pCurrent->next = mynode;


	mylist->size++;
}


void Foreach_LinkList(LinkList list, void(*myforeach)(void *) )
{

	if (NULL == list)
	{
		return;
	}

	if (NULL == myforeach)
	{
		return;
	}

	struct LList * mylist = (struct LList *)list;

	struct LinkNode *pCurrent = mylist->header.next;

	while (pCurrent != NULL)
	{
		struct LinkNode *pNext = pCurrent->next;
		myforeach(pCurrent);
		pCurrent = pNext;
	}

}

//刪除節點
void RemoveByPos_LinkList(LinkList list, int position)
{
	if (NULL == list)
	{
		return;
	}

	struct LList * mylist = (struct LList *)list;

	if (position < 0 || position > mylist->size - 1)
	{
		return;
	}

	//輔助指針
	struct LinkNode *pCurrent = &(mylist->header);
	for (int i = 0; i < position; ++i)
	{
		pCurrent = pCurrent->next;
	}


	//緩存下待刪除節點
	struct LinkNode *pDel = pCurrent->next;

	//重新建立待刪除節點的前驅和後繼結點關係
	pCurrent->next = pDel->next;

	mylist->size--;
}


void Destroy_LinkList(LinkList list)
{
	if (NULL == list)
	{
		return;
	}

	free(list);
	list = NULL;
}

struct Person
{
	struct LinkNode node; //結構體應該指針？ (不可使用指針,因如果是雙向鏈表,變成8字節,會誤訪到其他數據域)
	char name[64];
	int age;
};

void myPrint(void *data)
{
	struct Person *person = (struct Person *)data;
	printf("Name:%s Age:%d\n", person->name,person->age);
}

void test()
{

	//初始化鏈表
	LinkList list = Init_LinkList();


	//創建數據
	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };
	struct Person p4 = { NULL, "ddd", 40 };
	struct Person p5 = { NULL, "eee", 50 };
	struct Person p6 = { NULL, "fff", 60 };


	//插入數據
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p6);


	//遍歷
	Foreach_LinkList(list, myPrint);

	//刪除
	RemoveByPos_LinkList(list, 3);

	printf("------------------\n");

	//遍歷
	Foreach_LinkList(list, myPrint);

	//銷毀
	Destroy_LinkList(list);
}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}