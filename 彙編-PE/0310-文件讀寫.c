/*
2019/04/05 10:11:21
0310文件讀寫.c
*/ #define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<Windows.h>

//pe

#define PE_ENTRY 0x3c
#define Signature 0x4
#define DWtoWORD(x)  x&0x1111

//

int file_read(const char* file_name, char** p)
{

	FILE* fp = fopen(file_name, "rb");
	if (!fp)
	{
		perror("file not exist\n");
		getchar();
		exit(EXIT_FAILURE);
	}
	printf("file address:%.2x\n", (int*)fp);

	long int lenth = 0;
	if (!fseek(fp, 0, SEEK_END))//獲取文件長度。
		lenth = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	*p = (char*)malloc(sizeof(char) * lenth);
	if (!*p)
	{
		printf("pointer can't creat..\n");
		getchar();
		return -1;
	}
	printf("%.2x\n", *p);

	memset(*p, 0, lenth);
	long int fread_cnt = fread(*p, sizeof(char), lenth, fp);
	fclose(fp);

	if (fread_cnt == lenth)
	{
		printf("file read successfully..\n");
		return fread_cnt;
	}
	else
	{
		printf("file lenth=%d,buffer size=%d\nfread fail", lenth, fread_cnt);
		return -1;
	}

}
void file_write(char* file_name, char** wptr, int lenth)
{
	FILE* wp = fopen(file_name, "wb");
	if (!wp)
	{
		perror("file can't open\n");
		getchar();
		exit(EXIT_FAILURE);
	}
	long int wfile_cnt = fwrite(*wptr, 1, lenth, wp);

	fclose(wp);
	if (wfile_cnt == lenth) {
		printf("file write to %s successfully.\n", file_name);
	}
	else
	{
		printf("file lenth=%d,buffer size=%d\nfread fail", lenth, wfile_cnt);
		return -1;
	}
}

void show_pe(const char* pep,int len)
{
	//for (int i = 0; i < len; i++)
	//{
	//	if (i % 10 == 0)
	//		putchar('\n');
	//	tmp = *(pep + i);
	//	printf("%.2x ", tmp);
	//	Sleep(500);
	//}
	DWORD	pe_offset = *((DWORD*)(pep + PE_ENTRY));
	DWORD   IMAGE_NT_HEADER = pep+pe_offset;
	DWORD	IMAGE_FILE_HEADER = pep+pe_offset + Signature;
	WORD	NumberOfSections = *((WORD*)(IMAGE_FILE_HEADER+ 0x2));
	WORD	SizeOfOptionalHeader = *((WORD*)(IMAGE_FILE_HEADER+ 0x10));


	printf("IMAGE_NT_HEADER:%.4x\n", IMAGE_NT_HEADER);
	printf("IMAGE_FILE_HEADER:%.4x\n", IMAGE_FILE_HEADER);
	printf("NumberOfSections:%.X\n", NumberOfSections);
	printf("SizeOfOptionalHeader:%.X\n\n", SizeOfOptionalHeader);

	DWORD op_pe_offset = pep + pe_offset + 0x18;
	DWORD IMAGE_OPTIONAL_HEADER = op_pe_offset;
	DWORD AddressOfEntryPoint = *((DWORD*)(op_pe_offset + 0x10));
	DWORD ImageBase = *((DWORD*)(op_pe_offset + 0x1c));
	DWORD SectionAlignment = *((DWORD*)(op_pe_offset+ 0x20));
	DWORD FileAlignment = *((DWORD*)(op_pe_offset + 0x24));
	DWORD SizeOfImage =  *((DWORD*)(op_pe_offset+ 0x38));
	DWORD SizeOfHeaders = *((DWORD*)(op_pe_offset + 0x3c));
	DWORD NumberOfRvaAndSizes = *((DWORD*)(op_pe_offset+ 0x5c));

	printf("IMAGE_OPTIONAL_HEADER:%.4x\n", IMAGE_OPTIONAL_HEADER);
	printf("AddressOfEntryPoint:%.4x\n", AddressOfEntryPoint);
	printf("ImageBase:%.4x\n", ImageBase);
	printf("SectionAlignment:%.4x\n", SectionAlignment);
	printf("FileAlignment:%.4x\n", FileAlignment);
	printf("SizeOfImage:%.4x\n", SizeOfImage);
	printf("SizdOfHeaders:%.4x\n", SizeOfHeaders);
	printf("NumberOfRvaSizes:%.4x\n", NumberOfRvaAndSizes);
}
typedef struct Peconstract
{

};

void main() {
	char in_file[] = "e:\\temp\\1.exe";
	char out_file[] = "e:\\temp\\2.exe";
	
	char* temp=NULL ;

	int file_lenth=	file_read(in_file,&temp);
	printf("%.2x\n", temp);



	file_write(out_file, &temp, file_lenth);


	putchar('\n');
	putchar('\n');
	putchar('\n');

	show_pe(temp,file_lenth);


	free(temp);



	system("pause");
}
