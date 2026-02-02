#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "LinkStack.h"

struct LinkNode;

struct LinkList;

struct Person;
//initailize the stack
struct LinkList* initList();

//push an element onto the stack
void pushData(struct LinkList* linklist, struct Person* data);

//pop an element from the stack
struct LinkNode* popData(struct LinkList* linklist);

//check if the stack is empty
int isEmpty(struct LinkList* linklist);

//get the size of the stack
int getSize(struct LinkList* linklist);

//clear the stack
void clearStack(struct LinkList* linklist);
