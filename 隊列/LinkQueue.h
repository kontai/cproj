#pragma once

struct BiNode
{
	int data;
	struct BiNode *lchild;
	struct BiNode *rchild;
};


#include<stdlib.h>

//鏈表結點的數據類型
struct QueueNode
{
	struct QueueNode *next;
};

//鏈表數據類型
struct LQueue
{
	struct QueueNode header; //頭結點
	int size;
	struct QueueNode *rear; //尾指針，始終指向鏈表的最後一個節點
};

typedef void* LinkQueue;


#ifdef __cplusplus
extern "C"{
#endif

	//初始化
	LinkQueue Init_LinkQueue();
	//入隊
	void Push_LinkQueue(LinkQueue queue, void *data);
	//出隊
	void Pop_LinkQueue(LinkQueue queue);
	//獲得隊頭元素
	void* Front_LinkQueue(LinkQueue queue);
	//獲得隊尾元素
	void* Back_LinkQueue(LinkQueue queue);
	//大小
	int Size_LinkQueue(LinkQueue queue);
	//銷毀隊列
	void Destroy_LinkQueue(LinkQueue queue);

#ifdef __cplusplus
}
#endif