#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#ifdef __cplusplus
extern "C"{
#endif

	//1. 先把所需要的數據信息結構定義下來
	struct DynamicArray
	{
		//數組存儲元素的空間的首地址
		void **addr;
		//存儲數據的內存中最大能夠容納多少元素
		int capacity; //容量
		//當前存儲數據的內存中有多少個元素
		int size; //大小
	};

	//初始化數組
	struct DynamicArray *Init_DynamicArray(int capacity);
	//插入元素
	void Insert_DynamicArray(struct DynamicArray *arr, int pos, void *data);
	//遍歷
	void Foreach_DynamicArray(struct DynamicArray *arr, void(*_callback)(void *));
	//位置刪除
	void RemoveByPos_DynamicArray(struct DynamicArray *arr, int pos);
	//按值刪除
	void RemoveByValue_DynamicArray(struct DynamicArray *arr, void *data, int(*compare)(void*, void *));
	//銷毀數組
	void Destroy_DynamicArray(struct DynamicArray *arr);

#ifdef __cplusplus
}
#endif