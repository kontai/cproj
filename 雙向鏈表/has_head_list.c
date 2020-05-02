#include "has_head_list.h"

int init_list(struct NODE **head_p)
{
	struct NODE *head = NULL;

	head = (struct NODE*)malloc(sizeof(struct NODE));
	if (head == NULL) {
		fprintf(stderr, "malloc head error\n");
		return -1;
	}

	head->data = 0;
	head->next = NULL;

	*head_p = head;

	return 0;
}

//創建一個節點的接口
struct NODE* make_node(int data)
{
	struct NODE *new_node = NULL;

	new_node = (struct NODE*)malloc(sizeof(struct NODE));
	if (new_node == NULL) {
		return NULL;
	}

	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

//銷毀一個節點
void free_node(struct NODE *node)
{
	if (node != NULL) {
		free(node);
	}
}

int insert_node_from_begin(struct NODE *new_node, struct NODE *head)
{
	if (new_node == NULL || head == NULL) {
		return -1;
	}

	new_node->next = head->next;
	head->next = new_node;

	return 0;
}

int insert_node_to_end(struct NODE *new_node, struct NODE *head)
{
	struct NODE *last_node = NULL;

	if (new_node == NULL || head == NULL) {
		return -1;
	}

	//找到最後一個節點的地址，用last_node 指向他
	for (last_node = head; last_node->next != NULL; last_node = last_node->next);

	//保證new_node的next 指向NULL
	new_node->next = last_node->next;

	last_node->next = new_node;

	return 0;
}

//查找一個鏈表的節點
struct NODE *search(int data, struct NODE *head)
{
	struct NODE *p = NULL;

	for (p = head->next; p != NULL; p = p->next) {
		if (p->data == data) {
			return p;
		}
	}

	return NULL;
}

//刪除帶頭結點的元素
int delete_node(struct NODE *del_node, struct NODE* head)
{
	struct NODE *p = NULL;

	if (del_node == NULL || head == NULL) {
		return -1;
	}

	for (p = head; p->next != NULL; p = p->next) {
		if (p->next == del_node) {
			//找到了被刪除的節點 就是p->next
			p->next = p->next->next;
			free_node(del_node);
			break;
		}
	}

	return 0;
}

//遍歷一個帶頭節點的鏈表
void print_list(struct NODE *head)
{
	struct NODE *p = NULL;

	for (p = head->next; p != NULL; p = p->next) {
		printf("data: %d\n", p->data);
	}
}

//銷毀一個鏈表
void destory_list(struct NODE **head_p)
{
	struct NODE * p = NULL;
	struct NODE *head = NULL;

	if (head_p == NULL) {
		return;
	}

	head = *head_p;

	for (p = head->next; p != NULL;) {
		//p就是要刪除的節點
		head->next = p->next;
		free_node(p);
		p = head->next;
	}

	//如果循環退出，說明 head->next = NULL
	if (head != NULL) {
		free_node(head);
		*head_p = NULL;
	}
}