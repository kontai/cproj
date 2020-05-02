#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "no_head_list.h"

int main(void)
{
	struct node *head;
	struct node *new_node = NULL;
	int num = 10;
	int i = 0;
	int del_data = 0;

	//初始化頭結點
	init_list(&head);


	for (i = 0; i < num; i++) {
		new_node = make_node(i + 10);
		//insert_node_to_end(new_node, &head);
		insert_node_from_begin(new_node, &head);
	}

	print_list(head);

	printf("請輸入要刪除的節點:");
	scanf("%d", &del_data);
	struct node *del_node = search(head, del_data);
	if (del_node != NULL) {
		delete_node(del_node, &head);
	}

	printf("-----\n");

	print_list(head);


	//銷毀一個鏈表
	destory_list(&head);


	if (head == NULL) {
		printf("head == NULL\n");
	}

	return 0;
}