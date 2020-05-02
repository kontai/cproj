#ifndef _NO_HEAD_LIST_H_
#define _NO_HEAD_LIST_H_

#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//鏈表的節點
struct node
{
	int data;//數據域
	struct node *next;//指針域
};

//初始化鏈表的接口
void init_list(struct node **head_p);

//創建一個節點的接口
struct node* make_node(int data);

//銷毀一個節點
void free_node(struct node *node);

//將節點插入鏈表的接口 （插入鏈表的尾部）
int insert_node_to_end(struct node *new_node, struct node **head_p);

//將節點插入鏈表的接口(插入鏈表的頭部)
int insert_node_from_begin(struct node *new_node, struct node **head_p);

//銷毀一個鏈表
void destory_list(struct node **head_p);

//刪除一個節點
int delete_node(struct node *del_node,  struct node**head_p);

//查詢一個節點
struct node * search(struct node *head, int data);

//遍歷鏈表
void print_list(struct node *head);

#endif