#include "myarray.h"

void init(struct Data* parr) {
	if (parr != NULL)
	{
		parr->pstart = NULL;
		parr->length = 0;
		parr->sort = 0;
	}
	else
		printf("init error");
}

void initWithData(struct Data* parr, datatype data) {
	if (parr != NULL)
	{
		parr->pstart = malloc(sizeof(data));
		parr->length = 1;
		*(parr->pstart) = data;
	}
	else
		printf("initWithData error");
}

void initWithArray(struct Data* parr, datatype* arr, datatype data_length) {
	if (parr != NULL)
	{
		parr->pstart = malloc(sizeof(arr) * data_length);
		memcpy(parr->pstart, arr, sizeof(*arr) * data_length);
		parr->length = data_length;
	}
	else
		printf("initWithArray error");
}

void addObject(struct Data* parr, datatype data)
{
	if (parr != NULL)
	{
		realloc(parr->pstart, (parr->length + 1) * sizeof(datatype));
		*(parr->pstart + parr->length) = data;
		parr->length++;
	}
	else
	{
		if (parr->pstart == NULL || parr->length == 0)
			initWithData(parr, data);
		else printf("addObject error");
	}
}
void addArray(struct Data* parr, datatype* arr, datatype length)
{
	if (parr->pstart != NULL)
	{
		realloc(parr->pstart, (parr->length + length) * sizeof(datatype));
		memcpy((parr->pstart + parr->length), arr, length * sizeof(datatype));
		parr->length += length;

	}
	else
	{
		if (parr->pstart == NULL || parr->length == 0)
			initWithArray(parr, arr, length);
		else printf("addArray error");
	}

}


int* findFirst(struct Data* parr, datatype data)
{
	if (parr == NULL || parr->pstart == NULL || parr->length == 0) {
		printf("無輸入資料要找啥...\n");
	}
	else
	{
		for (datatype i = 0; i < (parr->length); i++)
		{
			if (parr->pstart[i] == data)
				return &parr->pstart;
		}
	}

	printf("找不到...\n");
	return 0;
}

void insertObject(struct Data* parr, datatype dest, datatype data)
{
	if (parr == NULL || parr->pstart == NULL || parr->length == 0) {
		printf("無輸入資料要找啥...\n");
		return;
	}

	realloc(parr->pstart, (parr->length + 1) * sizeof(datatype));
	parr->length++;
	for (int i = parr->length; i > dest; i--)
		parr->pstart[i] = parr->pstart[i - 1];
	parr->pstart[dest] = data;
}

void insertArray(struct Data* parr, datatype dest, datatype* data, datatype length)
{
	if (parr == NULL || parr->pstart == NULL || parr->length == 0) {
		printf("無輸入資料要找啥...\n");
		return;
	}
	else if (parr->length < dest)
	{
		printf("超過資料長度...\n");
		return;
	}
	else
	{

		realloc(parr->pstart, (parr->length + length) * sizeof(datatype));
		for (int i = 0; i < parr->length+length-dest; i++)
		{ 
			parr->pstart[parr->length + length -1- i] = parr->pstart[parr->length - 1 - i];
		}

		parr->length += length;

		for (int i = 0, j = dest; i < length; i++, j++)
		{
			parr->pstart[j] = data[i];
		}
	}
}


void show(struct Data* parr) {
	if (parr == NULL || parr->pstart == NULL || parr->length == 0) {
		printf("無輸入資料...\n");
	}
	else
	{

		for (int i = 0; i < parr->length; i++) {
			printf("%4d", parr->pstart[i]);
		}
		putchar('\n');
	}
}
