#define   _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<io.h>

//_access判斷文件/文件夾是否存在
//_access("file",[option]0-判斷是否存在,2-判斷是否可讀,4-判斷是否可寫,6-判斷是否可讀可寫)
//返回值(0-可以/存在 , 非0 - 不可/不存在)

void main3() {
	char ch = 0;
	char file[20] = "c:\\1.txt";
	//FILE *flp = fopen(file, "w");
	if (_access(file, 0)) {
		printf("can't find file");
	}
	else {
		printf("find file:%s", file);
	}

	system("pause");
}