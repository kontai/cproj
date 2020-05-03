#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#ifdef __cplusplus
extern "C"{
#endif

	//1. ����һݭn���ƾګH�����c�w�q�U��
	struct DynamicArray
	{
		//�Ʋզs�x�������Ŷ������a�}
		void **addr;
		//�s�x�ƾڪ����s���̤j����e�Ǧh�֤���
		int capacity; //�e�q
		//��e�s�x�ƾڪ����s�����h�֭Ӥ���
		int size; //�j�p
	};

	//��l�ƼƲ�
	struct DynamicArray *Init_DynamicArray(int capacity);
	//���J����
	void Insert_DynamicArray(struct DynamicArray *arr, int pos, void *data);
	//�M��
	void Foreach_DynamicArray(struct DynamicArray *arr, void(*_callback)(void *));
	//��m�R��
	void RemoveByPos_DynamicArray(struct DynamicArray *arr, int pos);
	//���ȧR��
	void RemoveByValue_DynamicArray(struct DynamicArray *arr, void *data, int(*compare)(void*, void *));
	//�P���Ʋ�
	void Destroy_DynamicArray(struct DynamicArray *arr);

#ifdef __cplusplus
}
#endif