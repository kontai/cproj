#include "LinkLins.h"

//�ڵ�ṹ��
struct LinkNode
{
	//data����ָ���κ�
	void *data;
	//next ָ����һ���ڵ�
	struct LinkNode *next;

};
//������Ϣ�ṹ��
struct LList
{
	//����ͷ���ĵ�ַ
	struct LinkNode header;
	//��������Ľڵ�
	int size;
};

LinkList Init_LinkList()//��ʼ������(������ṹ��)
{	
	//����һ���ڴ棬
	struct LList *list = malloc(sizeof(struct LList));

	if (NULL == list)
	{
		return NULL;
	}

	list->header.data = NULL;
	list->header.next = NULL;
	list->size = 0;
	return list;
}

//��������Ϣ�ṹ�壬�����½ڵ�
//���Ƚ���һ��void *����
//posҪ�����λ��
void Insert_LinkList(LinkList list, int pos, void *data)//����ڵ�
{
	if (NULL == data)
	{
		return;
	}

	if (NULL == list)
	{
		return;
	}
	//����ָ�룬�����ṹ����Ϣָ��
	struct LList *mylist = (struct LList *)list;
	//���pos<0���������ڵ����������
	if (pos < 0 || pos > mylist->size)
	{
		pos = mylist->size;
	}

	struct LinkNode * pCurrent = &(mylist->header);

	//ѭ���ҵ�pos֮ǰ�Ľڵ�
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//�����µĽڵ����ֵ���ݸ�������������ڵ�����
	struct LinkNode *newnode = malloc(sizeof(struct LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//ǰ��
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;
	//�ڵ�����һ��
	mylist->size++;
}

void Foreach_LinkList(LinkList list, FOREACH myforeach)//�����ڵ�
{
	if (NULL==list)
	{
		return;
	}
	if (NULL == myforeach)
	{
		return;
	}
	//
	struct LList *mylist = (struct LList *)list;

	struct LinkNode *pCurrent = mylist->header.next;
	while (pCurrent!= NULL)
	{
		myforeach(pCurrent->data);
		pCurrent = pCurrent->next;
	}
}

void RemoveByPos_LinkList(LinkList list, int pos)//��λ��ɾ��
{ 
	if (NULL == list)
	{
		return;
	}
	//�����ڵ�
	struct LList *mylist = (struct LList *)list;

	//�����ɾ�������û���ҵ���ֱ�ӷ���
	if (pos < 0 || pos > mylist->size)
	{
		return;
	}

	//�ҵ����λ��
	struct LinkNode *myheader = &(mylist->header);
	//��������ָ�룬����ǰ��ģ��ͺ����
	struct LinkNode *pCurrent = myheader->next;
	//һֱѭ��ֱ���ҵ�pos�ڵ�
	for (int i = 0; i < pos; ++i)
	{
		myheader = pCurrent;
		pCurrent = pCurrent->next;
	}
	//ֱ��������ǰ���ڵ��next�������ĺ����ڵ�
	myheader->next = pCurrent->next;
	free(pCurrent);
	pCurrent = NULL;
	mylist->size--;

}
//��ֵɾ��
//����������Ϣ�ṹ
//����һ���ڵ�
//һ���ص��������û��Լ���д
void RemoveByVal_LinkList(LinkList list, void *data, COMPARE compare)
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
	
	struct LList * mylist = (struct LList *)list;

	//���������ڵ�
	struct LinkNode *myliknode = &(mylist->header);
	struct LinkNode *pCurrrent = myliknode->next;
	//
	while (pCurrrent!= NULL)
	{	//pCurrent->dataָ��һ���ṹ��
		if (compare(pCurrrent->data,data))
		{
			//ɾ���ڵ㣬���ͷ�
			myliknode->next=pCurrrent->next;
			free(pCurrrent);
			pCurrrent = NULL;
			mylist->size--;
			break;
		}
		myliknode = pCurrrent;
		pCurrrent = pCurrrent->next;		
	}
}

void Clear_LinkList(LinkList list)//�������
{

	if (NULL == list)
	{
		return;
	}
	//
	struct LList *mylist = (struct LList *)list;
	struct LinkNode *myheadder = mylist->header.next;
	struct LinkNode *mynext =NULL;
	while (myheadder->next != NULL)
	{
		mynext = myheadder->next;
		free(myheadder);
		myheadder = mynext;
		
	}
	mylist->header.next = NULL;
}

int Size_LinkList(LinkList list)//����ڵ����
{
	if (NULL == list)
	{
		return -1;
	}
	struct LList *mylist = (struct LList *)list;
	return mylist->size;
}

void Destroy_LinkList(LinkList list)//��������
{
	if (NULL == list)
	{
		return;
	}
	Size_LinkList(list);	
	free(list);
	list = NULL;
}