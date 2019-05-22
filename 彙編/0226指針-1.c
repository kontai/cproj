/*
2019/03/16 10:40:35
0226«ü°w-1.c
*/

#include<stdio.h>
#include<stdlib.h>

struct Student {
	int x;
	int y;
};

void main0226() {
	/*
		struct Student**** s;

		s = (struct Student****)100;
		s++;
		printf("s++=%d\n", s);

		s = (struct Student****)100;
		s=s+2;
		printf("s+2=%d\n", s);

		s = (struct Student****)100;
		s=s-3;
		printf("s-3=%d\n", s);
	*/


	/*
	struct Student**** s1;
	struct Student**** s2;
	char x;
	int y;

	s1 = (struct Student****)200;
	s2 = (struct Student****)100;
	x = ((char)s1 - (char)s2);
	y = s1 - s2;
	printf("x=%d\n", x);
	printf("y=%d\n", y);
	system("pause");
	*/

	/*
	struct Student*	ss;

	ss = (struct Student*)100;
	ss++;
	printf("ss++=%d\n", ss);

	ss = (struct Student*)100;
	ss = ss + 2;
	printf("ss+2=%d\n", ss);

	ss = (struct Student*)100;
	ss = ss - 3;
	printf("ss-3=%d\n", ss);
	*/

	/*struct Student* s01;
	struct Student* s02;
	int x01;
	s01 = (struct Student*)200;
	s02 = (struct Student*)100;
	x01 = s01 - s02;
	printf("x01=%d", x01);*/

	struct Student* a;
	struct Student** b;
	printf("Student* %d\n", sizeof(a));
	printf("Student** %d\n", sizeof(b));


	system("pause");
}