#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct DynamicArray;

typedef void(*DynamicList);
//初始化动态数组
void* initArray();

//向動態數組添加元素
void addData(DynamicList list, void* data);

//獲取指定位置的元素
DynamicList getDataByPos(DynamicList list, int pos);
