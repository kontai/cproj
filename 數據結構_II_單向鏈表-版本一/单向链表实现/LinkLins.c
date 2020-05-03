#include "LinkLins.h"







Linknode initlinklins()//��ʼ���ڵ�
{
	struct message *mymessage = malloc(sizeof(MS));
	if (mymessage == NULL)
	{
		return NULL;
	}
	mymessage->headder.data = NULL;
	mymessage->headder.next = NULL;
	mymessage->age = 0;

	return mymessage;
}


void insertnode(Linknode phead, int pos, void *data)//��������
{
	if (NULL == phead)
	{
		return;
	}
	if (NULL == data)
	{
		return;
	}

	MS *myphead = (MS *)phead;

	if ( pos < 0 || pos > myphead->age)
	{
		pos = myphead->age;
	}

	MN *pnod = &(myphead->headder);
	
	
	for (int i = 0; i < pos; ++i)
	{
		pnod = pnod->next;
	}

	MN * newnod = malloc(sizeof(MN));
	newnod->data = data;
	newnod->next = NULL;

	newnod->next = pnod->next;
	pnod->next = newnod;

	myphead->age++;

}

void stamp(Linknode phead, FOREACH show)//��ӡ����
{
	if (NULL == phead)
	{
		return;
	}

	MS *myphead = (MS*)phead;
	//��ӡ�ӵڶ����ڵ㿪ʼ
	MN *mydata = myphead->headder.next;

	while (mydata != NULL)
	{
		show(mydata->data);
		mydata = mydata->next;
	}
}

int nodenumber(Linknode phead)//����һ�ڵ����
{
	if (NULL == phead)
	{
		return -1;
	}

	MS *myphead = (MS *)phead;
	return myphead->age;

}
void deletenode(Linknode phead, int pos)//����λ��ɾ��
{
	if (NULL == phead)
	{
		return;
	}
	MS *myphead = (MS *)phead;
	
	if (pos<0 || pos>myphead->age)
	{
		return;
	}
	MN *p1 = myphead->headder.next;
	MN *p2 = NULL;
	for (int i = 0; i < pos; ++i)
	{
		p2 = p1;
		p1 = p1->next;
	}

	p2->next = p1->next;
	if (p1 != NULL)
	{
		free(p1);
		p1 = NULL;
	}
}