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

	init_list(&head);//��l�ƤF�@�Ӧ��Y������Y���I


	for (i = 0; i < num; i++) {
		new_node = make_node(i + 10);
		//insert_node_from_begin(new_node, head);
		insert_node_to_end(new_node, head);
	}
	for_each(head, print_node);
	//print_list(head);

	LOG("���C�Ӹ`�I�������ȥ[1�G\n");
	for_each(head, add_node);

	for_each(head, print_node);


	LOG("�n�R�����`�I");
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
		printf("head �w�g�P��\n");
	}


	// �H�U�O�m��  

	/*
	    �@�Ӿ㫬�]An integer�^
	 b) �@�ӫ��V�㫬�����w�]A pointer to an integer�^
	 c) �@�ӫ��V���V�㫬�����w�]A pointer to a pointer to an integer�^
	 d) �@��10�Ӧs��㫬���Ʋա]An array of 10 integers�^
	 e) �@��10�Ӧs����V�㫬���w���Ʋ�
	 �]An array of 10 pointers to integers�^
	 f) �@�ӫ��V�s��10�Ӿ㫬�Ʋժ����w
	 �]A pointer to an array of 10 integers�^
	 g) �@�ӫ��V �ݭn�@�Ӿ㫬�ѼƨåB��^�ȬO�@�Ӿ㫬��ƪ����w
	 �]A pointer to a function that takes an integer as an argument and
	 returns an integer�^
	 h) �@�Ӧs��10�� ���V �ݭn�@�Ӿ㫬�ѼƨåB��^�ȬO�@�Ӿ㫬��ƪ����w��
	 �Ʋ�
	 �]An array of ten pointers to functions that take an integer argument
	 and return an integer�^
	*/

#if 0
	int a;//�@�Ӿ��a
	int*a;//�@�ӫ��V��Ϊ����w
	int * *a;//�@�ӫ��V��Ϋ��w�� ���w
	int a[10];// �@�Ӧs��10�Ӿ�Ϊ��Ʋ�
	int *a[10];//�@�ӼƲ� �s��10�� ���V��Ϊ����w
	int(*a)[10];//�@�ӫ��V   �s��10�Ӿ�μƲժ� ���w
	int(*a)(int); // �@�ӫ��V �ݭn�@�Ӿ㫬�ѼƨåB��^�ȬO�@�Ӿ㫬��ƪ����w
	//��ƫ��w�Ʋ�
	typedef int(*FP)(int); //�@�Ө�ƫ��w
	FP a[10];

	int(*fp[10])(int);
#endif
	return 0;
}