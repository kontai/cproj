#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef __cplusplus
extern "C"{
#endif

	struct mynod
	{
		void* data;
		struct mynod *next;
	};

	struct message
	{
		struct mynod headder;
		int age;
	};
	typedef void * Linknode;
	typedef struct message MS;
	typedef struct mynod MN;
	typedef void(*FOREACH)(void *);

	void* initlinklins();//��ʼ���ڵ�
	void insertnode(Linknode phead, int pos, void *data);//��������
	void stamp(Linknode phead, void(*show)(void *));//��ӡ����
	int nodenumber(Linknode phead);//����һ�ڵ����
	void deletenode(Linknode phean, int pos);//����λ��ɾ��



	







#ifdef __cplusplus
}
#endif