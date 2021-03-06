#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"SeqStack.h"

int IsLeft(char ch)
{
	return ch == '(';
}

int IsRight(char ch)
{
	return ch == ')';
}

void printError(const char *str,char *errMsg,char *pos)
{

	printf("錯誤信息:%s\n", errMsg);
	printf("%s\n",str);
	int dis = pos - str;
	for (int i = 0; i < dis; ++i)
	{
		printf(" ");
	}
	printf("A\n");


}

void test()
{

	const char *str = "5+5*(6()+9/3*1)-(1)+3(";
	char *p = (char *)str;
	
	//初始化棧
	SeqStack stack = Init_SeqStack();


	while (*p != '\0')
	{

		//判斷當前字符是否是左括號
		if (IsLeft(*p))
		{
			Push_SeqStack(stack, p);
		}


		//判斷當前字符是否是右括號
		if (IsRight(*p))
		{
			if (Size_SeqStack(stack) > 0)
			{
				//彈出棧頂元素
				Pop_SeqStack(stack);
			}
			else
			{
				printError(str,"右括號沒有匹配的左括號!",p);

			}

		}

		p++;
	}

	while (Size_SeqStack(stack) > 0)
	{
		printError(str,"沒有匹配的右括號!",Top_SeqStack(stack));
		//彈出棧頂元素
		Pop_SeqStack(stack);
	}


	//銷毀棧
	Destroy_SeqStack(stack);
	stack = NULL;



}

int main(){

	test();

	char *s = "1 + 2 / 2 - 4";

	system("pause");
	return EXIT_SUCCESS;
}