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



//����`�I
struct node
{
	int data;//�ƾڰ�
	struct node *next;//���w��
};

//��l�Ƥ@�Ӧ��Y����Y���I
int init_list(struct node **head_p);

//�Ыؤ@�Ӹ`�I�����f
struct node* make_node(int data);

//�P���@�Ӹ`�I
void free_node(struct node *node);

//�q�Y���J�`�I�����f
int insert_node_from_begin(struct node *new_node, struct node *head);

//�q�������J�`�I
int insert_node_to_end(struct node *new_node, struct node *head);

//�M���@�ӱa�Y�`�I�����
void print_list(struct node *head);

//�d��@������`�I
struct node *search(int data, struct node *head);

//�R���a�Y���I������
int delete_node(struct node *del_node, struct node* head);

//�P���@�����
void destory_list(struct node **head_p);


//�f�Ǥ@�����
int reverse(struct node *head);

//���L�@�Ӹ`�I
void print_node(struct node *node);

void add_node(struct node *node);

//����Τ@�M������k
void for_each(struct node *head, void(*fp)(struct node *node));


#endif