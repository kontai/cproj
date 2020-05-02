#include "no_head_list.h"


void init_list(struct node **head_p)
{
	*head_p = NULL;
}

struct node* make_node(int data)
{
	struct node *new_node = NULL;

	new_node = (struct node *)malloc(sizeof(struct node));
	if (new_node == NULL) {
		fprintf(stderr, "make node malloc new_node error\n");
		return NULL;
	}
	memset(new_node, 0, sizeof(struct node));

	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

//銷毀一個節點
void free_node(struct node *node)
{
	if (node != NULL) {
		free(node);
	}
}

//插入一個節點到head中
int insert_node_to_end(struct node *new_node, struct node **head_p)
{
	struct node *head = NULL;
	struct node *last_node = NULL;

	if (new_node == NULL  || head_p == NULL) {
		return 0;
	}
	head = *head_p;

	if (head == NULL) {
		//鏈表此時是空鏈表
		head = new_node;
		//無頭鏈表 的特點需要對head是否為空 進行判斷
	}
	else {
		//找到這個last_node
		//last_node->next = new_node;
		for (last_node = head; last_node->next != NULL; last_node = last_node->next);

		last_node->next = new_node;
	}

	*head_p = head;

	return 0;
}

int insert_node_from_begin(struct node *new_node, struct node **head_p)
{
	if (new_node == NULL || head_p == NULL) {
		return -1;
	}

	struct node *head = *head_p;

	//插入的操作
	if (head == NULL) {
		head = new_node;
	}
	else {
		new_node->next = head;
		head = new_node;
	}


	*head_p = head;

	return 0;
}


void print_list(struct node *head)
{
	struct node *p = NULL;

	for (p = head; p != NULL; p = p->next) {
		printf("%d\n", p->data);
	}
}

//銷毀一個鏈表
void destory_list(struct node **head_p)
{
	struct node *head = *head_p;
	struct node *p = NULL;

	while (head != NULL) {
		//鏈表還有元素
		p = head;
		head = head->next;
		free_node(p);
	}


	*head_p = head;
}

//刪除一個節點，根據要刪除節點的指針來刪除
int delete_node(struct node *del_node, struct node  **head_p)
{
	struct node *head = *head_p;
	struct node *p = NULL;


	if (head == del_node) {
		//如果要刪除的節點是首屆點
		head = head->next;
		free_node(del_node);
		*head_p = head;

		return 0;
	}

	//要刪除的不是頭結點
	for (p = head; p != NULL; p = p->next) {
		if (p->next == del_node) {
			//找到了要刪除的節點，此時p是這個要刪除節點前驅節點
			p->next = p->next->next;
			free_node(del_node);
			break;
		}
	}

	*head_p = head;
	return 0;
}


//查詢一個節點
struct node * search(struct node *head, int data)
{
	struct node *p = NULL;

	for (p = head; p != NULL; p = p->next) {
		if (p->data == data) {
			return p;
		}
	}

	return NULL;
}


