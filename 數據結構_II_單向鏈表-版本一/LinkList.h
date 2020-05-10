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

	//初始化鏈表
	LinkList Init_LinkList();
	//插入節點
	void Insert_LinkList(LinkList list,int pos,void *data);
	//遍歷鏈表
	void Foreach_LinkList(LinkList list, FOREACH myforeach);
	//按位置刪除
	void RemoveByPos_LinkList(LinkList list,int pos);
	//按值刪除
	void RemoveByVal_LinkList(LinkList list, void *data, COMPARE compare);
	//清空鏈表
	void Clear_LinkList(LinkList list);
	//大小
	int Size_LinkList(LinkList list);
	//銷毀鏈表
	void Destroy_LinkList(LinkList list);


#ifdef __cplusplus
}
#endif