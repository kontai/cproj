#pragma once
#ifdef __cplusplus
extern "C"{
#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	//需要兩個結構體
	//一個節點結構體
	//一個是節點信息結構體
	//初始化節點信息結構體
	//插入節點
	//根據節點位置查找節點
	//根據值位置查找節點

	
	//LinkList就帶表了void *
	typedef void * LinkList;
	//
	typedef void(*FOREACH)(void *);
	typedef int(*COMPARE)(void *,void *);

	LinkList Init_LinkList();//初始化鏈表
	void Insert_LinkList(LinkList list, int pos, void *data);//插入節點
	void Foreach_LinkList(LinkList list, FOREACH myforeach);//遍歷節點
	
	void RemoveByPos_LinkList(LinkList list, int pos);//按位置刪除
	
	void RemoveByVal_LinkList(LinkList list, void *data, COMPARE compare);//按值刪除
	
	void Clear_LinkList(LinkList list);//清空鏈表
	
	int Size_LinkList(LinkList list);//大小
	
	void Destroy_LinkList(LinkList list);//銷毀鏈表
	


#ifdef __cplusplus
}
#endif