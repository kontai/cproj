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
void addData(Dlist list, void* data)
{
	if (list == NULL)
	{
		return;
	}
	if (data == NULL)
	{
		return;
	}
	struct DynamicArray* d_array = list;

	//判斷是否需要擴容
	if (d_array->m_size == d_array->capacity)
	{
		void** newArr = malloc(sizeof(data) * (SIZE + d_array->capacity));
		if (newArr == NULL)
		{
			printf("allocate new array fail.\n");
			return;
		}

		//將原數組的數據拷貝到新數組
		memcpy(newArr, d_array->dList, d_array->m_size);
		free(d_array->dList);
		d_array->dList = NULL;
		d_array->dList = newArr;
	}

	//添加數據
	d_array->dList[d_array->m_size] = data;

	//更新大小
	d_array->m_size++;
}

//依據位置獲取元素
Dlist getDataByPos(Dlist list, int pos)
{
	if (list==NULL)
	{
		return NULL;
	}

	struct DynamicArray* d_array = list;
	if (pos<0 || pos > d_array->m_size)
	{
		printf("pos not available.\n");
		return NULL;
	}
}

//依據數據獲取元素
Dlist getDataByVal(Dlist list, void* data);

//獲取動態數組的大小
int getSize(Dlist list);

//判斷動態數組是否為空
int isEmpty(Dlist list);
