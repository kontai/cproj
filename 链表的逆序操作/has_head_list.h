#ifndef _HAS_HEAD_H_
#define _HAS_HEAD_H_

#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEBUG(format, ...) \
	fprintf(stderr, "[DEBUG][%s:%d][%s][%s]"format, __FUNCTION__, __LINE__, __DATE__, __TIME__, ##__VA_ARGS__);//__VA_ARGS__ === a,b
#define ERROR(format, ...)\
	fprintf(stderr, "[ERROR][%s:%d][%s][%s]"format, __FUNCTION__, __LINE__, __DATE__, __TIME__, ##__VA_ARGS__);
#define LOG(format, ...)\
	fprintf(stderr, "[LOG][%s:%d][%s][%s]"format, __FUNCTION__, __LINE__, __DATE__, __TIME__, ##__VA_ARGS__);



//鏈表的節點
struct node
{
	int data;//數據域
	struct node *next;//指針域
};

//初始化一個有頭鏈表的頭結點
int init_list(struct node **head_p);

//創建一個節點的接口
struct node* make_node(int data);

//銷毀一個節點
void free_node(struct node *node);

//從頭插入節點的接口
int insert_node_from_begin(struct node *new_node, struct node *head);

//從尾部插入節點
int insert_node_to_end(struct node *new_node, struct node *head);

//遍歷一個帶頭節點的鏈表
void print_list(struct node *head);

//查找一個鏈表的節點
struct node *search(int data, struct node *head);

//刪除帶頭結點的元素
int delete_node(struct node *del_node, struct node* head);

//銷毀一個鏈表
void destory_list(struct node **head_p);


//逆序一個鏈表
int reverse(struct node *head);

//打印一個節點
void print_node(struct node *node);

void add_node(struct node *node);

//鏈表的統一遍歷的方法
void for_each(struct node *head, void(*fp)(struct node *node));


#endif