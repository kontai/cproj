/*
2020/05/16 16:45:23
¤G¤e¾ðªº»¼Âk¹M¾ú.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

#if 0
struct BiNode
{
	char n;
	struct BiNode* lNode;	//¥ª¸`ÂI
	struct BiNode* rNode;	//¥k¸`ÂI
};

//¥ý§Ç¹M¾ú(DLR)¡G®Ú¡÷¥ª¡÷¥k
void DLR_recur(struct BiNode* root)
{
	if (root == NULL)
		return;
	printf("%c\t", root->n);
	DLR_recur(root->lNode);
	DLR_recur(root->rNode);
}

//¤¤§Ç¹M¾ú(LDR)¡G¥ª¡÷®Ú¡÷¥k
void LDR_recur(struct BiNode* root)
{
	if (root == NULL)
		return;
	LDR_recur(root->lNode);
	LDR_recur(root->rNode);
	printf("%c\t", root->n);
}

//«á§Ç¹M¾ú(LRD)¡G¥ª¡÷¥k¡÷®Ú
void LRD_recur(struct BiNode* root)
{
	if (root == NULL)
		return;
	LRD_recur(root->lNode);
	printf("%c\t", root->n);
	LRD_recur(root->rNode);
}

void main() {
	struct BiNode nodeA = { 'A',NULL,NULL };
	struct BiNode nodeB = { 'B',NULL,NULL };
	struct BiNode nodeC = { 'C',NULL,NULL };
	struct BiNode nodeD = { 'D',NULL,NULL };
	struct BiNode nodeE = { 'E',NULL,NULL };
	struct BiNode nodeF = { 'F',NULL,NULL };
	struct BiNode nodeG = { 'G',NULL,NULL };
	struct BiNode nodeH = { 'H',NULL,NULL };

	//Layer I
	nodeA.lNode = &nodeB;
	nodeA.rNode = &nodeF;

	//Layer II
	nodeB.rNode = &nodeC;

	nodeF.rNode = &nodeG;

	//Layer III
	nodeC.lNode = &nodeD;
	nodeC.rNode = &nodeE;

	nodeG.lNode = &nodeH;

	DLR_recur(&nodeA);
	putchar('\n');
	LDR_recur(&nodeA);
	putchar('\n');
	LRD_recur(&nodeA);

	system("pause");
}
#endif
