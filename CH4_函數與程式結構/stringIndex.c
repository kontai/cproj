/*
2018/11/03 18:01:35
stringIndex.c

程式目的:
搜尋含有指定字串的列內容 "oul"
並顯示最後出現字串位置,如沒有就-1
		

Ah Love!Could you and I with Fate compire
To grasp this sorry Scheme of Things entire,
Would not rw shatter it to bite - and then
Re - mould it near to the harts's Desire!
    

*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXLINE 1000

int getline(char[], int line);
int patten(char[], char[], int);




void main2() {
	char ch[MAXLINE];
	short count = 0;
	int found = 0;
	int loc = 0;
	char str[] = { "oul" };
	while ((count = getline(ch, MAXLINE)) > 0) {
		if ((loc=patten(ch, str, count))>=0) 
		{
			found++;
			printf("%s\n %d\n", ch, count);
		}
	}
	printf("found:%d", found);
	printf("單字%s在位置:%d處", str,loc+1);
	system("pause");
}

int getline(char s[], int lim) {
	int i = 0;
	char c = 0;
	while (--lim && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = c;
	}
	s[i] = '\0';
	return i;   //返回字數;
}

int patten(char source[], char dest[], int num) {
	int i = 0, j = 0;
	int find = 0;
	while (source[i] != '\0') {						//exit if end of file
		while ((source[i] == dest[j])) {			//loop-compare each char1
			i++, j++;
			if (dest[j] == '\0')
				return (i-3);
			else if (source[i] != dest[j])
			{
				i--;
				j = 0;
				break;
			}
		}

		i++;
	}

	return -1;
}