/*
2019/03/12 9:51:06
0204µ≤∫c≈È.c
*/

#include<stdio.h>
#include<stdlib.h>

struct gamer {
	int hp;
	int level;
	int x, y;
	struct date {
		int day;
		int month;
		int year;
	}win;
};

void set_gamer(struct gamer *I) {
	I->hp = 90;
	I->level = 30;
	I->x = 20, I->y = 40;
	I->win.day = 20;
	I->win.month = 3;
	I->win.year = 2019;
}

void info(struct gamer g) {
	printf("HP=%d\nLevel=%d\nLoc=%d,%d\n", g.hp, g.level, g.x, g.y);
	printf("day=%d\nmonth=%d\nyear=%d\n", g.win.day, g.win.month, g.win.year);
}

void main0204(){
	struct gamer player1;
	struct date a;

	set_gamer(&player1);
	
	info(player1);




//	info(player1);

	

	system("pause");
}