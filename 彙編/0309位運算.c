/*
2019/04/02 9:27:10
0309位運算.c
*/

#include<stdio.h>
#include<stdlib.h>

/*
1、定义一个unsiged char 类型，通过程序为第3、5、7位赋值,赋值时不能
影响到其它位原来的值.
(使用位操作指令、比如：& | ! ^ << >>等)

2、判断某个位的值是否为1.
(使用位操作指令、比如：& | ! ^ << >>等)

3、读取第7、6、5位的值，以十进制显示(unsigned).
(使用位操作指令、比如：& | ! ^ << >>等)

4、用十六进制文本编辑器分别打开一个.exe、.dll、.sys、.txt、.doc
.jpg、.pdf等将前四个字节写在下了.

5、将一个在十六进制编辑器中打开的.exe文件，拖拽到最后，观察文件中的大小和硬盘上的大小.
(下载一个WinHex)
*/

void isTrue(unsigned char ch,size_t bit)
{
	if (ch&(1<<bit-1))
		printf("該位為1\n");
	else
		printf("該位不為1\n");
}

void main0309(){
	//1
	unsigned char ch1 = 0;
	ch1 = ch1 | 1<<2;
	printf("%d\n", ch1);
	ch1 = ch1 | 1<<4;
	printf("%d\n", ch1);
	ch1 = ch1 | 1<<6;
	printf("%d\n", ch1);

	//2
	isTrue(ch1, 4);


	

	system("pause");
}