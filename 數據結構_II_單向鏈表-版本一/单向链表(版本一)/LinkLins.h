#pragma once
#ifdef __cplusplus
extern "C"{
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	//��Ҫ�����ṹ��
	//һ���ڵ�ṹ��
	//һ���ǽڵ���Ϣ�ṹ��
	//��ʼ���ڵ���Ϣ�ṹ��
	//����ڵ�
	//���ݽڵ�λ�ò��ҽڵ�
	//����ֵλ�ò��ҽڵ�

	
	//LinkList�ʹ�����void *
	typedef void * LinkList;
	//
	typedef void(*FOREACH)(void *);
	typedef int(*COMPARE)(void *,void *);

	LinkList Init_LinkList();//��ʼ������
	void Insert_LinkList(LinkList list, int pos, void *data);//����ڵ�
	void Foreach_LinkList(LinkList list, FOREACH myforeach);//�����ڵ�
	
	void RemoveByPos_LinkList(LinkList list, int pos);//��λ��ɾ��
	
	void RemoveByVal_LinkList(LinkList list, void *data, COMPARE compare);//��ֵɾ��
	
	void Clear_LinkList(LinkList list);//�������
	
	int Size_LinkList(LinkList list);//��С
	
	void Destroy_LinkList(LinkList list);//��������
	


#ifdef __cplusplus
}
#endif