/*
2020/05/02 10:04:03
防止頭文件重複包含.c
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

// 1.
#pragma once

// 2.
//_SOMEHEAD_H_ 自定義宏，每個頭文件的宏都不一樣。
#ifndef _SOMEHEAD_H_
#define _SOMEHEAD_H_

//函數的聲明

#endif

void main() {
	system("pause");
}