#include"SeqStack.h"

//初始化
SeqStack Init_SeqStack()
{
	struct SStack *stack = malloc(sizeof(struct SStack));
	if (NULL == stack)
	{
		return NULL;
	}

	//memset(stack->data, 0, sizeof(struct SStack));
	stack->size = 0;
	for (int i = 0; i < MAX; ++i)
	{
		stack->data[i] = NULL;
	}
	
	return stack;
}
//入棧
void Push_SeqStack(SeqStack stack, void *data)
{

	if (NULL == stack)
	{
		return;
	}

	if (NULL == data)
	{
		return;
	}

	struct SStack *s = (struct SStack *)stack;

	if (s->size == MAX)
	{
		return;
	}

	s->data[s->size] = data;
	s->size++;
}
//出棧
void Pop_SeqStack(SeqStack stack)
{

	if (NULL == stack)
	{
		return;
	}

	struct SStack *s = (struct SStack *)stack;

	if (s->size == 0)
	{
		return;
	}


	s->data[s->size - 1] = NULL;
	s->size--;
}
//獲得棧頂元素
void *Top_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return NULL;
	}

	struct SStack *s = (struct SStack *)stack;

	if (s->size == 0)
	{
		return NULL;
	}


	return s->data[s->size - 1];

}
//獲得棧的大小
int Size_SeqStack(SeqStack stack)
{
	if (NULL == stack)
	{
		return -1;
	}

	struct SStack *s = (struct SStack *)stack;

	return s->size;
}
//銷毀棧
void Destroy_SeqStack(SeqStack stack)
{

	if (NULL == stack)
	{
		return;
	}

	free(stack);
}