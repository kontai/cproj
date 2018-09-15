/*

函数原型：unsigned long _beginthreadex( void *security, unsigned stack_size, unsigned ( __stdcall *start_address )( void * ), void *arglist, unsigned initflag, unsigned *thrdaddr );

	  //第1个参数：安全属性，NULL为默认安全属性
		   //第2个参数：指定线程堆栈的大小。如果为0，则线程堆栈大小和创建它的线程的相同。一般用0
		   //第3个参数：指定线程函数的地址，也就是线程调用执行的函数地址(用函数名称即可，函数名称就表示地址，注意的是函数访问方式一定是__stdcall，函数返回值一定是unsigned，函数参数一定是void*)
		   //第4个参数：传递给线程的参数的指针，可以通过传入对象的指针，在线程函数中再转化为对应类的指针
		   //第5个参数：线程初始状态，0:立即运行；CREATE_SUSPEND：悬挂（如果出事状态定义为悬挂，就要调用ResumeThread(HANDLE) 来激活线程的运行）
		  //第6个参数：用于记录线程ID的地址

*/



#include<string>
#include<iostream>
#include<process.h>
#include<windows.h>
using namespace std;

struct Arg//用来传参给线程函数
{
	double d_;
	string str_;
	Arg(double dd, string ss) :d_(dd), str_(ss) {}
};

//线程绑定的函数返回值和参数是确定的，而且一定要__stdcall
unsigned __stdcall threadFun(void *)
{
	for (int i = 0; i < 10; i++)
		cout << i << endl;
	return 1;
}

//可以通过结构体来传入参数
unsigned __stdcall threadFunArg(void *arglist)
{
	Arg *p = (Arg *)arglist;
	cout << p->d_ << endl;
	cout << p->str_ << endl;
	return 2;
}

//简单的线程类
class ThreadClass
{
private:
	string str_;
	int i_;
public:
	ThreadClass(string s, int i) :str_(s), i_(i) {}
	static unsigned __stdcall threadStaic(void *arg)
	{
		ThreadClass *p = (ThreadClass *)arg;
		p->threadfun();
		return 3;
	}
	void threadfun()
	{
		cout << str_ << endl;
		cout << i_ << endl;
	}
};

int main3()
{
	unsigned int thID1, thID2, thID3, thID4;
	HANDLE hth1, hth2, hth3, hth4;
	Arg arg(3.14, "hello world");
	ThreadClass tclass("welcome", 999);

	//注意的是_beginthreadex是立即返回的，系统不会等线程函数执行完毕，因此要保证
	//局部arg变量 在线程函数执行完毕前不会释放，更安全的是使用new来构造arg
	hth1 = (HANDLE)_beginthreadex(NULL, 0, threadFun, NULL, 0, &thID1);
	hth2 = (HANDLE)_beginthreadex(NULL, 0, threadFun, NULL, 0, &thID2);
	hth3 = (HANDLE)_beginthreadex(NULL, 0, threadFunArg, &arg, 0, &thID3);
	hth4 = (HANDLE)_beginthreadex(NULL, 0, ThreadClass::threadStaic, &tclass, 0,
		&thID4);

	//主线程一定要等待子线程结束
	WaitForSingleObject(hth1, INFINITE);
	WaitForSingleObject(hth2, INFINITE);
	WaitForSingleObject(hth3, INFINITE);
	WaitForSingleObject(hth4, INFINITE);

	DWORD exitCode1, exitCode2, exitCode3, exitCode4;
	GetExitCodeThread(hth1, &exitCode1);
	GetExitCodeThread(hth2, &exitCode2);
	GetExitCodeThread(hth3, &exitCode3);
	GetExitCodeThread(hth4, &exitCode4);
	cout << endl << "exitcode::" << exitCode1 << " " << exitCode2 << " " << exitCode3 << " "
		<< exitCode4 << endl;
	cout << "ID:" << thID1 << " " << thID2 << " " << thID3 << " " << thID4 << endl;

	//一定要记得关闭线程句柄
	CloseHandle(hth1);
	CloseHandle(hth2);
	CloseHandle(hth3);
	CloseHandle(hth4);

	return 0;
}