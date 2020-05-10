#pragma once

#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#ifdef __cplusplus
extern "C"{
#endif

	typedef void * LinkList;
	typedef void(*FOREACH)(void *);
	typedef int(*COMPARE)(void *,void *);

	//��l�����
	LinkList Init_LinkList();
	//���J�`�I
	void Insert_LinkList(LinkList list,int pos,void *data);
	//�M�����
	void Foreach_LinkList(LinkList list, FOREACH myforeach);
	//����m�R��
	void RemoveByPos_LinkList(LinkList list,int pos);
	//���ȧR��
	void RemoveByVal_LinkList(LinkList list, void *data, COMPARE compare);
	//�M�����
	void Clear_LinkList(LinkList list);
	//�j�p
	int Size_LinkList(LinkList list);
	//�P�����
	void Destroy_LinkList(LinkList list);


#ifdef __cplusplus
}
#endif