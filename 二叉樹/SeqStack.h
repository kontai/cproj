#pragma once

#include<stdlib.h>
#include<string.h>

#ifdef __cplusplus
extern "C"{
#endif


#define MAX 1024


	//順序棧數據結構
	struct SStack
	{
		void *data[MAX]; //存放數據的數組
		int size;//棧中元素的個數
	};


	typedef void * SeqStack;

	//數組高下標的位置當做棧頂，因為不需要移動數組中的元素在插入和刪除中

	//初始化
	SeqStack Init_SeqStack();
	//入棧
	void Push_SeqStack(SeqStack stack, void *data);
	//出棧
	void Pop_SeqStack(SeqStack stack);
	//獲得棧頂元素
	void *Top_SeqStack(SeqStack stack);
	//獲得棧的大小
	int Size_SeqStack(SeqStack stack);
	//銷毀棧
	void Destroy_SeqStack(SeqStack stack);


#ifdef __cplusplus
}
#endif