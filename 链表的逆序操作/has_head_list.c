#include "has_head_list.h"

int init_list(struct node **head_p)
{
	struct node *head = NULL;

	head = (struct node*)malloc(sizeof(struct node));
	if (head == NULL) {
		ERROR("malloc head error\n");
		return -1;
	}

	head->data = 0;
	head->next = NULL;

	*head_p = head;

	LOG("init list over\n");

	return 0;
}

//創建一個節點的接口
struct node* make_node(int data)
{
	struct node *new_node = NULL;

	new_node = (struct node*)malloc(sizeof(struct node));
	if (new_node == NULL) {
		ERROR("malloc %d error\n", data);
		return NULL;
	}

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

int insert_node_from_begin(struct node *new_node, struct node *head)
{
	if (new_node == NULL || head == NULL) {
		ERROR("new_node == NULL || head == NULL");
		return -1;
	}

	new_node->next = head->next;
	head->next = new_node;

	return 0;
}

int insert_node_to_end(struct node *new_node, struct node *head)
{
	struct node *last_node = NULL;

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
struct node *search(int data, struct node *head)
{
	struct node *p = NULL;

	for (p = head->next; p != NULL; p = p->next) {
		if (p->data == data) {
			return p;
		}
	}

	return NULL;
}

//刪除帶頭結點的元素
int delete_node(struct node *del_node, struct node* head)
{
	struct node *p = NULL;

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
void print_list(struct node *head)
{
	struct node *p = NULL;

	for (p = head->next; p != NULL; p = p->next) {
		DEBUG("data: %d\n", p->data);
	}
}

void print_node(struct node *node)
{
	DEBUG("data: %d\n", node->data);
}

void add_node(struct node *node)
{
	node->data += 1;
}


//鏈表的統一遍歷的方法
void for_each(struct node *head, void(*fp)(struct node *node)) //fp = print_node
{
	struct node *p = NULL;

	for (p = head->next; p != NULL; p = p->next) {
		//遍歷一個鏈表 找到每個元素的節點
		//分別調用 fp 傳進來的方法 去執行每個節點的業務
		fp(p);//printf_node(p);
	}
}

//銷毀一個鏈表
void destory_list(struct node **head_p)
{
	struct node * p = NULL;
	struct node *head = NULL;

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

//逆序一個鏈表
int reverse(struct node *head)
{
	struct node *p = NULL; //準備逆序的節點
	struct node *prev_p = NULL;//p的前驅
	struct node *next_p = NULL;//p的後繼

	//初始化
	prev_p = head;
	p = head->next;

	while (p != NULL) {
		//向讓next_p 指向p的後繼
		next_p = p->next;
		//改變p的後繼為p的前驅
		p->next = prev_p;

		//讓p的前驅等於p
		prev_p = p;
		
		//讓p等於 原先p的後繼 next_p
		p = next_p;
	}

	//先改變原先首元素的寫一個地址
	head->next->next = NULL;
	
	//將頭結點 指向目前的 prev_p 也就是新的首元素地址
	head->next = prev_p;

	return 0;
}