#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"SeqStack.h"

struct Person
{
	char name[64];
	int age;
};


void test()
{
	
	//初始化棧
	SeqStack stack = Init_SeqStack();


	//創建數據
	struct Person p1 = { "aaa", 10 };
	struct Person p2 = { "bbb", 20 };
	struct Person p3 = { "ccc", 30 };
	struct Person p4 = { "ddd", 40 };
	struct Person p5 = { "eee", 50 };
	struct Person p6 = { "fff", 60 };

	//數據入棧
	Push_SeqStack(stack, &p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);
	Push_SeqStack(stack, &p4);
	Push_SeqStack(stack, &p5);
	Push_SeqStack(stack, &p6);

	//輸出棧中所有元素
	while (Size_SeqStack(stack) > 0)
	{

		//獲得棧頂元素
		struct Person *person =  (struct Person *)Top_SeqStack(stack);
		//打印
		printf("Name:%s Age:%d\n",person->name,person->age);
		//彈出棧頂元素
		Pop_SeqStack(stack);

	}

	printf("Size:%d\n", Size_SeqStack(stack));

	//銷毀棧
	Destroy_SeqStack(stack);
	stack = NULL;

}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}