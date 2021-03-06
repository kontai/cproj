#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include"SeqStack.h"
#if 0

struct BiNode
{
	char ch;
	struct BiNode *lchild;
	struct BiNode *rchild;
};

struct Info
{
	struct BiNode *node;
	bool flag;
};

struct Info* createInfo(struct BiNode *node, bool flag)
{
	struct Info *info = malloc(sizeof(struct Info));
	info->flag = flag;
	info->node = node;

	return info;
}

void nonRecursion(struct BiNode *root)
{

	//初始化棧
	SeqStack stack = Init_SeqStack();
	//先把根節點壓入棧中
	Push_SeqStack(stack, createInfo(root, false));

	while (Size_SeqStack(stack) > 0)
	{
		//獲得棧頂元素	
		struct Info *info = (struct Info *)Top_SeqStack(stack);
		//彈出棧頂元素
		Pop_SeqStack(stack);


		if (info->flag)
		{
			printf("%c ",info->node->ch);
			free(info);
			continue;
		}

		//將根節壓入棧中
		info->flag = true;
		Push_SeqStack(stack, info);

		//將右子樹壓入棧中
		if (info->node->rchild != NULL)
		{
			Push_SeqStack(stack, createInfo(info->node->rchild, false));
		}

		//將左子樹壓入棧中
		if (info->node->lchild != NULL)
		{
			Push_SeqStack(stack, createInfo(info->node->lchild, false));
		}

	
	}


	//銷毀棧
	Destroy_SeqStack(stack);
}


void test()
{
	struct BiNode nodeA = { 'A', NULL, NULL };
	struct BiNode nodeB = { 'B', NULL, NULL };
	struct BiNode nodeC = { 'C', NULL, NULL };
	struct BiNode nodeD = { 'D', NULL, NULL };
	struct BiNode nodeE = { 'E', NULL, NULL };
	struct BiNode nodeF = { 'F', NULL, NULL };
	struct BiNode nodeG = { 'G', NULL, NULL };
	struct BiNode nodeH = { 'H', NULL, NULL };


	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;

	nodeB.rchild = &nodeC;

	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;

	nodeF.rchild = &nodeG;

	nodeG.lchild = &nodeH;


	nonRecursion(&nodeA);

}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}
#endif