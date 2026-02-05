#pragma once

#ifndef DRI_SCALE_H
#define DRI_SCALE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
	char x[8];
	char y[8];
	char spc[24];
}POINT;

enum {
	M70 = 0b0001,
	M80 = 0b0010,
	M90 = 0b0100,
}MODE;

void calc_g85(char* ptr, char* g85spc, int x_offset, int y_offset, double xscale, double yscale);

void calc_offset(POINT** origP, int* origSize, int* origCap, int isMOd, int* modeCount, int* mode, char* xOffsetSum, char* yOffsetSum,
	char* offX, char* offY, FILE* fout, double xscale, double yscale);

void calc_point(FILE* fout, double xscale, double yscale, char* x, char* y, char* spc);

void parse_point(char* line, char* x, char* y, char* spc);

void add_point(POINT** array, int* size, int* cap, char* x, char* y, char* spc);

void resest_point(POINT** array, int* size, int* cap);

void read_file();

#endif
