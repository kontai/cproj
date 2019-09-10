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
		pa->p = malloc(strlen(pstrbak)+1);	//だ皌ず―才﹃
		pa->memlen = strlen(pstrbak)+1;		//ず
		strcpy(pa->p, pstrbak);		//ī才﹃
	}
	else if (ch == 'w')
	{
		stringw *pw = p;
		pw->p = NULL;
		pw->memlen = 0;

		wchar_t* pstrbak = pstr;	//锣传糴才
		pw->p = malloc(wcslen(pstrbak)+2);	//だ皌ず―才﹃
		pw->memlen = wcslen(pstrbak)+2;		//ず
		wcscpy(pw->p, pstrbak);		//ī才﹃
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
