#include"DynamicArray.h"

//��l�ƼƲ�
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
//���J����
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

	//�P�_�Ŷ��O�_����
	if (arr->size >= arr->capacity)
	{

		//1. �ӽФ@����j�����s�Ŷ�
		int newcapacity = arr->capacity * 2;
		void **newspace = malloc(sizeof(void *)* newcapacity);

		//2. �N��ӪŶ����ƾګ�����s�Ŷ�
		memcpy(newspace, arr->addr, sizeof(void *)* arr->capacity);

		//3. �����ӪŶ������s
		free(arr->addr);

		//4. ��saddr���V
		arr->addr = newspace;
		arr->capacity = newcapacity;

	}


	//���ʤ����A��pos��m�ťX��m��
	for (int i = arr->size - 1; i >= pos; --i)
	{
		arr->addr[i + 1] = arr->addr[i];
	}

	//�N�s�������J��pos��m
	arr->addr[pos] = data;
	arr->size++;
}
//�M��
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

//��m�R��
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

//���ȧR��
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

//�P���Ʋ�
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
