#pragma once
/*
2018/12/16 10:25:03
myarray.h
*/

#include<stdio.h>
#include<stdlib.h>
#define datatype int

struct Data {
	datatype *pstart;
	int lenth;	//����
	int sort;   //0=�L�� , 1=����
};

void init(struct Data *parr);
void initWithData(struct Data *parr, datatype data);
void initWithArray(struct Data *parr, datatype *arr, datatype data);
