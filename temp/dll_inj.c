_declspec(dllexport) void go(){
		int* p = (int*)0x6ff7b8;
		void(*px)() = (void(*)())0xd010b9;
		*p = 20;
		px();
}