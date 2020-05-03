#include"DynamicArray.h"

//初始化數組
struct DynamicArray *Init_DynamicArray(int capacity)
{
	if (capacity <= 0)
	{
		return NULL;
	}

	struct DynamicArray *arr = malloc(sizeof(struct DynamicArray));
	if (NULL == arr)
	{
		return NULL;
	}
	arr->capacity = capacity;
	arr->addr = malloc(sizeof(void *)*arr->capacity);
	arr->size = 0;

	return arr;
}
//插入元素
void Insert_DynamicArray(struct DynamicArray *arr, int pos, void *data)
{

	if (NULL == arr)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	if (pos < 0 || pos > arr->size)
	{
		pos = arr->size;
	}

	//判斷空間是否足夠
	if (arr->size >= arr->capacity)
	{

		//1. 申請一塊更大的內存空間
		int newcapacity = arr->capacity * 2;
		void **newspace = malloc(sizeof(void *)* newcapacity);

		//2. 將原來空間的數據拷貝到新空間
		memcpy(newspace, arr->addr, sizeof(void *)* arr->capacity);

		//3. 釋放原來空間的內存
		free(arr->addr);

		//4. 更新addr指向
		arr->addr = newspace;
		arr->capacity = newcapacity;

	}


	//移動元素，給pos位置空出位置來
	for (int i = arr->size - 1; i >= pos; --i)
	{
		arr->addr[i + 1] = arr->addr[i];
	}

	//將新元素插入到pos位置
	arr->addr[pos] = data;
	arr->size++;
}
//遍歷
void Foreach_DynamicArray(struct DynamicArray *arr, void(*_callback)(void *))
{
	if (NULL == arr)
	{
		return;
	}

	if (NULL == _callback)
	{
		return;
	}

	for (int i = 0; i < arr->size; ++i)
	{
		_callback(arr->addr[i]);
	}


}

//位置刪除
void RemoveByPos_DynamicArray(struct DynamicArray *arr, int pos)
{

	if (NULL == arr)
	{
		return;
	}

	if (pos < 0 || pos > arr->size - 1)
	{
		return;
	}


	for (int i = pos; i < arr->size - 1; ++i)
	{
		arr->addr[i] = arr->addr[i + 1];
	}


	arr->size--;
}

//按值刪除
void RemoveByValue_DynamicArray(struct DynamicArray *arr, void *data, int(*compare)(void*, void *))
{
	if (NULL == arr)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	if (NULL == compare)
	{
		return;
	}


	for (int i = 0; i < arr->size; ++i)
	{
		if (compare(arr->addr[i], data))
		{
			RemoveByPos_DynamicArray(arr, i);
			break;
		}
	}

}

//銷毀數組
void Destroy_DynamicArray(struct DynamicArray *arr)
{
	if (NULL == arr)
	{
		return;
	}

	if (arr->addr != NULL)
	{
		free(arr->addr);
		arr->addr = NULL;
	}

	free(arr);
	arr = NULL;
}
