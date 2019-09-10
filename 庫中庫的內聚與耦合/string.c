#include "string.h"

void init(void* p, char ch)
{
	if (ch == 'a')
	{
		stringa *pa = p;
		pa->p = NULL;
		pa->memlen = 0;
	}
	else if (ch == 'w')
	{
		stringw *pw = p;
		pw->p = NULL;
		pw->memlen = 0;
	}
	else abort();
}


void initwithstring(void* p, char ch, void* pstr) 
{

	if (ch == 'a')
	{
		stringa *pa = p;

		char* pstrbak = pstr;
		pa->p = malloc(strlen(pstrbak)+1);	//���t���s�A�D�r�Ŧ���סC
		pa->memlen = strlen(pstrbak)+1;		//���s����
		strcpy(pa->p, pstrbak);		//�����r�Ŧ�
	}
	else if (ch == 'w')
	{
		stringw *pw = p;
		pw->p = NULL;
		pw->memlen = 0;

		wchar_t* pstrbak = pstr;	//�ഫ�e�r�šC
		pw->p = malloc(wcslen(pstrbak)+2);	//���t���s�A�D�r�Ŧ���סC
		pw->memlen = wcslen(pstrbak)+2;		//���s����
		wcscpy(pw->p, pstrbak);		//�����r�Ŧ�
	}
	else abort();

}

void show(void* p, char ch)
{
	if (ch == 'a')
	{
		stringa* sa = p;
		printf("%s\n", sa->p);
	}
	else if (ch == 'w')
	{
		stringw* sw = p;
		wprintf(L"%s\n", sw->p);
	}
	else abort();
}
