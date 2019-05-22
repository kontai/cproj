/*
2019/02/27 8:50:42
fastcall¹ê²{.c
*/

#include<stdio.h>
#include<stdlib.h>

//int _fastcall fun_ass(int x, int y, int z) {
//	int a = 2;
//	int b = 3;
//	int c = 4;
//	return x + y + z + a + b;
//}

int _declspec(naked) fun_ass(int x, int y, int z) {
	__asm {
		

		push ebp
		mov ebp,esp
		sub esp,0xc0

		push ebx
		push esi
		push edi

		lea edi,dword ptr [ebp-0xc0]
		mov eax,0xcccccccc
		mov ecx,0x30
		rep stos dword ptr es:[edi]

		xor eax,eax
		mov eax,dword ptr [ebp+0x8]
		add eax,dword ptr [ebp+0xc]
		add eax,dword ptr [ebp+0x10]

		mov dword ptr[ebp - 4], 4
		mov ecx,dword ptr [ebp-4]
		add eax,ecx

		mov dword ptr [ebp-8],3
		mov ecx,dword ptr [ebp-8]
		add eax,ecx

		mov dword ptr [ebp-0xc],2
		mov ecx,dword ptr [ebp-0xc]
		add eax,ecx


		pop edi
		pop esi
		pop ebx

		mov esp,ebp
		pop ebp
		ret  


	}
}

void main23() {
printf("sum=%d",fun_ass(1, 2, 3))	;

	system("pause");
}