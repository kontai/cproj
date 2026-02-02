#include "DynamiicArray.h"

struct DynamicArray
{
	void** dList; //整個動態數組
	int capacity; //動態數組的容量
	int m_size; //動態數組的大小
};

//typedef void(*Dlist);

//初始化动态数组
void* initArray()
{
	struct DynamicArray* array = malloc(sizeof(struct DynamicArray*));
	if (array == NULL)
	{
		printf("allocate struct fail.\n");
		return NULL;
	}
	array->dList = (void**)malloc(sizeof(void*) * SIZE);
	if (array->dList == NULL)
	{
		printf("allocate Dynamic Array fail.\n");
		return NULL;
	}

	array->capacity = SIZE;
	array->m_size = 0;
	return array;
}

//向動態數組添加元素
void addData(Dlist list, void* data);

//依據位置獲取元素
Dlist getDataByPos(Dlist list, int pos);

//依據數據獲取元素
Dlist getDataByVal(Dlist list, void* data);

//獲取動態數組的大小
int getSize(Dlist list);

//判斷動態數組是否為空
int isEmpty(Dlist list);
