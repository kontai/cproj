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

//�Ыؤ@�Ӹ`�I�����f
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

//�P���@�Ӹ`�I
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

	//���̫�@�Ӹ`�I���a�}�A��last_node ���V�L
	for (last_node = head; last_node->next != NULL; last_node = last_node->next);

	//�O��new_node��next ���VNULL
	new_node->next = last_node->next;

	last_node->next = new_node;

	return 0;
}

//�d��@������`�I
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

//�R���a�Y���I������
int delete_node(struct node *del_node, struct node* head)
{
	struct node *p = NULL;

	if (del_node == NULL || head == NULL) {
		return -1;
	}

	for (p = head; p->next != NULL; p = p->next) {
		if (p->next == del_node) {
			//���F�Q�R�����`�I �N�Op->next
			p->next = p->next->next;
			free_node(del_node);
			break;
		}
	}

	return 0;
}

//�M���@�ӱa�Y�`�I�����
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


//����Τ@�M������k
void for_each(struct node *head, void(*fp)(struct node *node)) //fp = print_node
{
	struct node *p = NULL;

	for (p = head->next; p != NULL; p = p->next) {
		//�M���@����� ���C�Ӥ������`�I
		//���O�ե� fp �Ƕi�Ӫ���k �h����C�Ӹ`�I���~��
		fp(p);//printf_node(p);
	}
}

//�P���@�����
void destory_list(struct node **head_p)
{
	struct node * p = NULL;
	struct node *head = NULL;

	if (head_p == NULL) {
		return;
	}

	head = *head_p;

	for (p = head->next; p != NULL;) {
		//p�N�O�n�R�����`�I
		head->next = p->next;
		free_node(p);
		p = head->next;
	}

	//�p�G�`���h�X�A���� head->next = NULL
	if (head != NULL) {
		free_node(head);
		*head_p = NULL;
	}
}

//�f�Ǥ@�����
int reverse(struct node *head)
{
	struct node *p = NULL; //�ǳưf�Ǫ��`�I
	struct node *prev_p = NULL;//p���e�X
	struct node *next_p = NULL;//p�����~

	//��l��
	prev_p = head;
	p = head->next;

	while (p != NULL) {
		//�V��next_p ���Vp�����~
		next_p = p->next;
		//����p�����~��p���e�X
		p->next = prev_p;

		//��p���e�X����p
		prev_p = p;
		
		//��p���� ���p�����~ next_p
		p = next_p;
	}

	//�����ܭ�����������g�@�Ӧa�}
	head->next->next = NULL;
	
	//�N�Y���I ���V�ثe�� prev_p �]�N�O�s���������a�}
	head->next = prev_p;

	return 0;
}