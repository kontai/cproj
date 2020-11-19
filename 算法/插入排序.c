/*
2020/05/17 9:59:23
´¡¤J±Æ§Ç.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#define NEWLINE putchar('\n')

void printArray(int arr[], int len)
{
	if (arr == NULL)
	{
		return;
	}
	int i = 0;
	for (; i < len; i++)
	{
		printf("%d  ", arr[i]);
	}
}

void InsertSort(int arr[], int len)
{
	if (arr == NULL)
	{
		return;
	}
	int i = 0;
	for (; i < len; i++)
	{
		if (arr[i] < arr[i - 1])
		{
			int tmp = arr[i];
			int j = i - 1;
			for (; j >= 0 && arr[j] > tmp; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = tmp;
		}
	}
}

void InsertSort2(int arr[], int len)
{
	if (arr == NULL)
		return;
	int i = 1;
	int tmp = 0;
	for (; i < len; i++)
	{
		if (arr[i] < arr[arr[i - 1]])
		{
			for (int j = i - 1; j >= 0 && arr[j] > arr[j +1 ]; j--)
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
void main() {
	int arr[] = { 2,3,55,12,37,23,1,76 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, len);
	NEWLINE;
	//InsertSort(arr, len);
	InsertSort2(arr, len);
	NEWLINE;
	printArray(arr, len);

	system("pause");
}