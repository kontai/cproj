#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void init(char*); //clean string
int lenstr(char*); //count string lenth
void addstr(char *, char*); //copy string
void catstr(char*, char*); //concatenate string
void findstring(char *, char *);
void save_find(int);
void print_find();

void mainYY() {
	char a[50] = { 0 };
	char b[] = "brew install macvim install";
	char *p = a;
	printf("%d\n", lenstr(b));
	addstr(p, b); //copy string
	catstr(p, "sdf");
	printf("%s\n", p);
	findstring(p, "install");
	print_find();
	init(p); //clean array
	system("pause");
	
}

void init(char*p) {
	while (*p) {
		*p++ = 0;
	}
}

int lenstr(char *p) {
	if (p == NULL) {
		printf("Empty");
		return -1;
	}
	int lenth = 0;
	while (*p) {
		lenth++, p++;
	}
	return lenth;
}

void addstr(char *dest, char*source) {
	if (dest == NULL || source == NULL) {
		printf("it's empty");
		return;
	}

	while (*source) {
		*dest++ = *source++;
	}
	*dest = '\0';
}

void catstr(char *dest, char *source) {
	if (dest == NULL || source == NULL) {
		printf("Empty");
		return;
	}
	int len = lenstr(dest);
	dest += len;
	*dest++ = ' '; //add space between  two string
	while (*source) {
		*dest++ = *source++;
	}
	*dest = '\0';
}

void  findstring(char*dest, char*souce) {
	int    len_full= lenstr(dest);
	int           len_source = lenstr(souce);
	for(int i=0;i<len_full-len_source;i++)
	{
		if (*(dest + len_source + i) == ' ')
		{
			
			for (int j = 0;j != len_source + 1;j++) {
				if (*(dest + i + j) != *(souce + j)) {
					break;
				}
				if ((j+1) == len_source) {
					save_find(i);
					printf("%7d\n", i);
					
			}
			}
				}
			}
		}

#define MAX 10
int alloc[MAX] = { 0 };
int alloc_find ;


void save_find(int find)
{
	if((MAX-alloc_find)>0)
	{
		alloc[alloc_find] = find;
		alloc_find++;
	}
}

void print_find()
{
	printf("%d\n", alloc_find);
	for(int i=0;i<alloc_find;i++)
	{
		printf("%d\n", alloc[i]);
	}
}




