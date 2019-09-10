#define _CRT_SECURE_NO_WARNINGS
#include"ui.h"
#include"dataarray.h"
#include "init.h"

char uistr[] =
{ 
"1.顯示所有數據\n\
2.刪除所有數據\n\
3.根據QQ查詢密碼\n\
4.修改數據\n\
5.排序\n\
6.清屏\n\
7.查找\n\
8.尾部增加\n\
9.插入\n\
q.退出\n\
"
};

void help()
{
	printf("%s\n", uistr);
}

void uiMain()
{
	struct DATAST* test;
	test = malloc(sizeof(struct DATAST));
	initWithArray(test, str);

	while (1)
	{
		help();
		char ch = getch();
		switch (ch)
		{
			case '1':
				showAll(test);
				break;

			case '2':
				delAll(test);
				break;

			case '3':
				printf("\n選擇查詢方式:(1.以QQ查詢第一個 2.以QQ查詢所有 3.以密碼查詢 4.以密碼查詢所有:\n");
				char choice = getchar();
				getchar();

				switch (choice)
				{
				case '1':
				{
					long long QQ;
					printf("請輸入QQ=>");
					scanf("%lld", &QQ);
					FindQQ(test,QQ);
					break;
				}

				case '2':
				{
					long long QQ;
					printf("請輸入QQ=>");
					scanf("%lld",&QQ);
					FindQQAll(test,QQ);
					break;
				}

				case '3':
				{
					char  pstring[100] = { 0 };
					printf("請輸入pass=>");
					scanf("%s", pstring);
					FindPass(test, pstring);
					break;
				}

				case '4':
				{
					char  pstring[100] = { 0 };
					printf("請輸入pass=>");
					scanf("%s", pstring);
					FindPassAll(test, pstring);
					break;
				}
				default:
					printf("\n=====輸入錯誤！===== \n\n");
					break;
				}
				break;

			case '4':
				break;

			case '5':
				break;

			case '6':
				system("cls");
				break;

			case '7':
				break;

			case '8':
				break;

			case '9':
				break;

			case 'q':
				exit(0);

			default:
				printf("\n=====輸入錯誤！===== \n\n");
				break;
	}
	}
}

