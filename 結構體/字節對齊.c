#include "stdafx.h"
#include<stdio.h>
#include <stdlib.h>

/*
�r�`����u�I:�M�}��K

���c��r�`����W�h:
1.
�U�����r�`�Ư���Q�̼e�򥻦����㰣(�r�`�Ƥ�����.�N�۰ʶ�[��R�r�`,���r�`����^
ps:�̼e�򥻦���,char int double float ...;���c��B���ʳ����O�̼e�򥻦���

2.
���c��C�Ӧ����۹�󵲺c�魺�a�}�������q���O�����j�p����ƭ�.�p���ݭn,�sĶ���|�b���������[�W��R�r�`(internal adding).



*/
	struct addA 
{
		
	short a;       //2+(2)  �[�W2���ɥR�r�`
	int b;           //4   ---max
	char c[9];   //9+(3) �[�W3���ɥR�r�` 
};

	struct  addB 
{
		
	char a;       //1+(1)  �[�W2���ɥR�r�`
	short b;      //2   ---max
	char c[9];   //9+(1) �[�W3���ɥR�r�` , �~�i�Q�̼e�򥻦����㰣
};

	struct  addC 
{
		
	int  a;         //4  ---max
	char b;       //1    
	char c[9];   //9   ����b �M c �]�O�s��B�P����,��}�N�X�֭p�� 1+9+(2)
};







void main()
{
	printf("%d\n", sizeof(struct addA));
	printf("%d\n", sizeof(struct addB));
	printf("%d\n", sizeof(struct addC));


	system("pause");
}