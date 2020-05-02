#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "has_head_list.h"

int main(void)
{
	struct node *head = NULL;
	struct node *new_node = NULL;
	struct node *del_node = NULL;
	int num = 10;
	int data = 0;
	int i = 0;

	init_list(&head);//初始化了一個有頭的鏈表的頭結點


	for (i = 0; i < num; i++) {
		new_node = make_node(i + 10);
		//insert_node_from_begin(new_node, head);
		insert_node_to_end(new_node, head);
	}
	for_each(head, print_node);
	//print_list(head);

	LOG("給每個節點元素的值加1：\n");
	for_each(head, add_node);

	for_each(head, print_node);


	LOG("要刪除的節點");
	scanf("%d", &data);
	del_node = search(data, head);
	if (del_node != NULL) {
		delete_node(del_node, head);
	}

	//print_list(head);
	for_each(head, print_node);


	printf("====== reverse  =====\n");
	reverse(head);
	//print_list(head);
	for_each(head, print_node);

	destory_list(&head);

	if (head == NULL) {
		printf("head 已經銷毀\n");
	}


	// 以下是練習  

	/*
	    一個整型（An integer）
	 b) 一個指向整型的指針（A pointer to an integer）
	 c) 一個指向指向整型的指針（A pointer to a pointer to an integer）
	 d) 一個10個存放整型的數組（An array of 10 integers）
	 e) 一個10個存放指向整型指針的數組
	 （An array of 10 pointers to integers）
	 f) 一個指向存放10個整型數組的指針
	 （A pointer to an array of 10 integers）
	 g) 一個指向 需要一個整型參數並且返回值是一個整型函數的指針
	 （A pointer to a function that takes an integer as an argument and
	 returns an integer）
	 h) 一個存放10個 指向 需要一個整型參數並且返回值是一個整型函數的指針的
	 數組
	 （An array of ten pointers to functions that take an integer argument
	 and return an integer）
	*/

#if 0
	int a;//一個整形a
	int*a;//一個指向整形的指針
	int * *a;//一個指向整形指針的 指針
	int a[10];// 一個存放10個整形的數組
	int *a[10];//一個數組 存放10個 指向整形的指針
	int(*a)[10];//一個指向   存放10個整形數組的 指針
	int(*a)(int); // 一個指向 需要一個整型參數並且返回值是一個整型函數的指針
	//函數指針數組
	typedef int(*FP)(int); //一個函數指針
	FP a[10];

	int(*fp[10])(int);
#endif
	return 0;
}