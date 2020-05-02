#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "has_head_list.h"

int main(void)
{
	struct NODE* head = NULL;
	struct NODE* new_node = NULL;
	struct NODE* del_node = NULL;
	int num = 10;
	int data = 0;
	int i = 0;

	init_list(&head);//初始化了一個有頭的鏈表的頭結點

	for (i = 0; i < num; i++) {
		new_node = make_node(i + 10);
		//insert_node_from_begin(new_node, head);
		insert_node_to_end(new_node, head);
	}
	print_list(head);

	printf("要刪除的節點\n");
	scanf("%d", &data);
	del_node = search(data, head);
	if (del_node != NULL) {
		delete_node(del_node, head);
	}

	print_list(head);

	destory_list(&head);

	if (head == NULL) {
		printf("head 已經銷毀\n");
		system("pause");
	}

	return 0;
}