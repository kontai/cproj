#define _CRT_SECURE_NO_WARNINGS
#include"ui.h"
#include"dataarray.h"
#include "init.h"

char uistr[] =
{ 
"1.��ܩҦ��ƾ�\n\
2.�R���Ҧ��ƾ�\n\
3.�ھ�QQ�d�߱K�X\n\
4.�ק�ƾ�\n\
5.�Ƨ�\n\
6.�M��\n\
7.�d��\n\
8.�����W�[\n\
9.���J\n\
q.�h�X\n\
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
				printf("\n��ܬd�ߤ覡:(1.�HQQ�d�߲Ĥ@�� 2.�HQQ�d�ߩҦ� 3.�H�K�X�d�� 4.�H�K�X�d�ߩҦ�:\n");
				char choice = getchar();
				getchar();

				switch (choice)
				{
				case '1':
				{
					long long QQ;
					printf("�п�JQQ=>");
					scanf("%lld", &QQ);
					FindQQ(test,QQ);
					break;
				}

				case '2':
				{
					long long QQ;
					printf("�п�JQQ=>");
					scanf("%lld",&QQ);
					FindQQAll(test,QQ);
					break;
				}

				case '3':
				{
					char  pstring[100] = { 0 };
					printf("�п�Jpass=>");
					scanf("%s", pstring);
					FindPass(test, pstring);
					break;
				}

				case '4':
				{
					char  pstring[100] = { 0 };
					printf("�п�Jpass=>");
					scanf("%s", pstring);
					FindPassAll(test, pstring);
					break;
				}
				default:
					printf("\n=====��J���~�I===== \n\n");
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
				printf("\n=====��J���~�I===== \n\n");
				break;
	}
	}
}

