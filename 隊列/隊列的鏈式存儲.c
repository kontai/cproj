#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkQueue.h"

struct Person
{
	struct QueueNode node;
	char name[64];
	int age;
};

void test()
{
	//初始化隊列
	LinkQueue queue = Init_LinkQueue();

	//創建數據
	struct Person p1 = { NULL, "aaa", 10 };
	struct Person p2 = { NULL, "bbb", 20 };
	struct Person p3 = { NULL, "ccc", 30 };
	struct Person p4 = { NULL, "ddd", 40 };
	struct Person p5 = { NULL, "eee", 50 };
	struct Person p6 = { NULL, "fff", 60 };

	//插入隊列
	Push_LinkQueue(queue, &p1);
	Push_LinkQueue(queue, &p2);
	Push_LinkQueue(queue, &p3);
	Push_LinkQueue(queue, &p4);
	Push_LinkQueue(queue, &p5);
	Push_LinkQueue(queue, &p6);


	struct Person *pBack = (struct Person *)Back_LinkQueue(queue);
	printf("隊尾元素:%s %d\n",pBack->name,pBack->age);

	while(Size_LinkQueue(queue) > 0)
	{
		//獲得隊頭元素
		struct Person *person = (struct Person *)Front_LinkQueue(queue);
		//打印隊頭元素
		printf("Name:%s Age:%d\n", person->name,person->age);
		//彈出隊頭元素
		Pop_LinkQueue(queue);
	}


	//銷毀隊列
	Destroy_LinkQueue(queue);

}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}