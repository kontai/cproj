#pragma once
#ifdef __cplusplus
extern "C"{
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	//�ݭn��ӵ��c��
	//�@�Ӹ`�I���c��
	//�@�ӬO�`�I�H�����c��
	//��l�Ƹ`�I�H�����c��
	//���J�`�I
	//�ھڸ`�I��m�d��`�I
	//�ھڭȦ�m�d��`�I

	
	//LinkList�N�a��Fvoid *
	typedef void * LinkList;
	//
	typedef void(*FOREACH)(void *);
	typedef int(*COMPARE)(void *,void *);

	LinkList Init_LinkList();//��l�����
	void Insert_LinkList(LinkList list, int pos, void *data);//���J�`�I
	void Foreach_LinkList(LinkList list, FOREACH myforeach);//�M���`�I
	
	void RemoveByPos_LinkList(LinkList list, int pos);//����m�R��
	
	void RemoveByVal_LinkList(LinkList list, void *data, COMPARE compare);//���ȧR��
	
	void Clear_LinkList(LinkList list);//�M�����
	
	int Size_LinkList(LinkList list);//�j�p
	
	void Destroy_LinkList(LinkList list);//�P�����
	


#ifdef __cplusplus
}
#endif