#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//鏈表的節點
struct teacher {
	int data;
	struct teacher* next;
};

//靜態鏈表
void test1()
{
	struct teacher t1, t2, t3, t4, t5; //靜態鏈表所有的節點，都是預先開闢完畢的，節點的個數是固定的。
	struct teacher* p = NULL; //遍歷鏈表的指針

	t1.data = 1;
	t2.data = 2;
	t3.data = 3;
	t4.data = 4;
	t5.data = 5;

	t1.next = &t2;//t1->t2
	t2.next = &t3;//t1->t2->t3
	t3.next = &t4;//t1->t2->t3->t4
	t4.next = &t5;//t1->t2->t3->t4->t5
	t5.next = NULL;//t1->t2->t3->t4->t5->NULL

	//遍歷一個靜態的鏈表
	for (p = &t1; p != NULL; p = p->next) {
		printf("p->data:%d\n", p->data);
	}
}

//動態鏈表
void test2()
{
	struct teacher* head = NULL; //頭指針
	struct teacher* last_node = NULL;//始終指向最後一個元素的指針
	struct teacher* new_node = NULL;//是一個新創建的鏈表的節點指針
	struct teacher* p = NULL; //遍歷遍歷的臨時指針
	int data = 0;

	printf("請輸入一個老師的data: ");
	scanf("%d", &data);
	while (data != -1) {
		//動態創建一個鏈表的節點
		new_node = (struct teacher*)malloc(sizeof(struct teacher));
		if (new_node == NULL) {
			return;
		}
		memset(new_node, 0, sizeof(struct teacher));

		new_node->data = data;
		new_node->next = NULL;

		//將new_node 添加到 head鏈表中
		if (head == NULL) {
			head = new_node;
		}
		else {
			last_node->next = new_node;
			last_node = new_node;
		}

		last_node = new_node;

		printf("請輸入一個老師的Data: ");
		scanf("%d", &data);
	}

	//遍歷一個鏈表
	for (p = head; p != NULL; p = p->next) {
		printf("%d\n", p->data);
	}

	//釋放所有的節點
	for (p = head; p != NULL; )
	{
		head = p->next;
		free(p);
		p = head;
	}

	if (head == NULL) {
		printf("list is NULL\n");
	}
}

int main(void)
{
	//test1();
	test2();

	return 0;
}