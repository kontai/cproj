#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a simple stack structure
struct SStack
{
	void* data[1024];;
	int m_size;
};


typedef void(*Stacks);


//initailize stack
struct SStack* intiStack();

//push data
void pushData(struct SStack* stack, void* data);


//pop data
void* popData(struct SStack* stack);

//check stack is empty?
int isEmpty(const struct SStack* stack);

//showAll
void showAllStack(struct SStack stack, void(*printData)(void*));


