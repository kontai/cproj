#include "DynamiicArray.h"

struct DynamicArray;

typedef void(*Dlist);
//初始化????
void* initArray();

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
