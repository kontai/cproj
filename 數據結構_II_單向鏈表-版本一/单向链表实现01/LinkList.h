#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifdef __cplusplus
extern "C"{
#endif
	struct linknod
	{
		char *arr;
		struct linknod *next;
	};

	struct nodedata
	{
		struct linknod mylinknod;
		int size;
	};
	typedef struct linknod mylink;
	typedef struct nodedata mynode;
	typedef void * Linknode;


	
	void* initnod();//��ʼ������
	void insert(Linknode headder, int pos, Linknode data);//��������
	void print(Linknode phead);//��ӡ����









#ifdef __cplusplus
}
#endif