#include "LinkLins.h"

//�`�I���c��
struct LinkNode
{
	//data�i�H���V����
	void* data;
	//next ���V�U�@�Ӹ`�I
	struct LinkNode* next;
};
//���H�����c��
struct LList
{
	//�O�s�Y���I���a�}
	struct LinkNode header;
	//�O�s����`�I
	int size;
};

LinkList Init_LinkList()//��l�����(������c��)
{
	//�}�P�@�����s�A
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

//�����H�����c��A���J�s�`�I
//���������@��void *����
//pos�n���J�o��m
void Insert_LinkList(LinkList list, int pos, void* data)//���J�`�I
{
	if (NULL == data)
	{
		return;
	}

	if (NULL == list)
	{
		return;
	}
	//���U���w�A���U���c��H�����w
	struct LList* mylist = (struct LList*)list;
	//�p�Gpos<0��Τj��̤j�`�I�N�b�̫ᴡ�J
	if (pos < 0 || pos > mylist->size)
	{
		pos = mylist->size;
	}

	struct LinkNode* pCurrent = &(mylist->header);

	//�`�����pos���e���`�I
	for (int i = 0; i < pos; ++i)
	{
		pCurrent = pCurrent->next;
	}

	//�}�P�s���`�I��ƭȶǻ����L�A�ç�o�Ӹ`�I�챵
	struct LinkNode* newnode = malloc(sizeof(struct LinkNode));
	newnode->data = data;
	newnode->next = NULL;

	//�e��
	newnode->next = pCurrent->next;
	pCurrent->next = newnode;
	//�`�I�W�[�@��
	mylist->size++;
}

void Foreach_LinkList(LinkList list, FOREACH myforeach)//�M���`�I
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

void RemoveByPos_LinkList(LinkList list, int pos)//����m�R��
{
	if (NULL == list)
	{
		return;
	}
	//���U�`�I
	struct LList* mylist = (struct LList*)list;

	//�o�ӬO�R���A�p�G�S�����N������^
	if (pos < 0 || pos > mylist->size)
	{
		return;
	}

	//���o�Ӧ�m
	struct LinkNode* myheader = &(mylist->header);
	//��ӻ��U���w�A�O�s�e�����A�M�᭱��
	struct LinkNode* pCurrent = myheader->next;
	//�@���`������䪺pos�`�I
	for (int i = 0; i < pos; ++i)
	{
		myheader = pCurrent;
		pCurrent = pCurrent->next;
	}
	//�������L���e�X�`�I��next�챵�������X�`�I
	myheader->next = pCurrent->next;
	free(pCurrent);
	pCurrent = NULL;
	mylist->size--;
}
//���ȧR��
//�ǤJ���H�����c
//�ǤJ�@�Ӹ`�I
//�@�Ӧ^�ը�ơA�Τ�ۤv�s�g
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

	//��ӻ��U�`�I
	struct LinkNode* myliknode = &(mylist->header);
	struct LinkNode* pCurrrent = myliknode->next;
	//
	while (pCurrrent != NULL)
	{	//pCurrent->data���V�@�ӵ��c��
		if (compare(pCurrrent->data, data))
		{
			//�R���`�I�A������
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

void Clear_LinkList(LinkList list)//�M�����
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

int Size_LinkList(LinkList list)//���`�I�Ӽ�
{
	if (NULL == list)
	{
		return -1;
	}
	struct LList* mylist = (struct LList*)list;
	return mylist->size;
}

void Destroy_LinkList(LinkList list)//�P�����
{
	if (NULL == list)
	{
		return;
	}
	Size_LinkList(list);
	free(list);
	list = NULL;
}