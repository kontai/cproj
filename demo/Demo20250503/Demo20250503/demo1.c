#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include <string.h>

/*
*file:demo1.c
*Date:2025/05/03
*Description:
*/

#define BUFFERSIZE 256	//緩衝區大小
#define   CAPSIZE 10	//預設的容量

typedef struct
{
	int x;
	int y;
} POINT;

void add_pointer(POINT* array, int* size, int* cap)
{
	if (*size >= *cap)
	{
		*cap *= 2;
		array = realloc(array, *cap * sizeof(POINT));
		if (array == NULL)
		{
			fprintf(stderr, "Memory reallocation failed\n");
			exit(EXIT_FAILURE);
		}
	}


}

int parse_point(char* line, int* x, int* y)
{
	if (line != NULL)
	{
		if (sscanf(line, "X&dY%d", x, y) == 2)
		{

		}
		else
		{
			printf(stderr, "Invalid format\n");
			return 0;
		}
	}
	else return 0;
}

void Reset_Point(POINT** array, int* size, int* cap)
{
	*size = 0;
	if (array == NULL)
	{
		*cap = 10;
		*array = malloc(*cap * sizeof(POINT));
		if (*array == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
	}
}

int main(void)
{
	FILE* fp = fopen("D:/test.1ST", "r");
	if (!fp)
	{
		perror("fopen()");
		exit(errno);
	}

	char line[BUFFERSIZE];
	POINT* basePoint = NULL;
	POINT* offsetPoint = NULL;

	int baseCap = CAPSIZE, offsetCap = CAPSIZE;
	int baseSize = 0, offsetSize = 0;

	//初始化POINT陣列
	Reset_Point(&basePoint, &baseSize, &baseCap);
	Reset_Point(&offsetPoint, &offsetSize, &offsetCap);

	int inTSection = 0; //是否在T區段
	int inBaseMode = 0; //是否在基準模式
	int inOffsetMode = 0; //是否在偏移模式

	int x = 0, y = 0; //座標
	while (fgets(line, sizeof(line), fp))
	{
		//找到T開頭的行
		if (strncmp(line, "T", 1) == 0)
		{
			printf("%s\n", line);
			if (inOffsetMode != 1)
				inBaseMode = 1;

		}
	}

	if (inBaseMode == 1) {
		//開始基準點
		Reset_Point(&basePoint, &baseSize, &baseCap);
		Reset_Point(&offsetPoint, &offsetSize, &offsetCap);
		add_pointer()
	}
	return 0;
}
