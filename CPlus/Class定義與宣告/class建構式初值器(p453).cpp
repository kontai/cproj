/****************************************
[4/24/2017  21:05]
class建構式初值器.cpp
****************************************/

#include<iostream>

using namespace std;

/*
 * 對於const類型或reference類型成員變數,或其class型別沒有default建構式的成員變數
 * 必須使用初值器初始化
 */
class constRef {
public:
	//利用初值列初始化
	constRef(int jj) :i(jj), ci(jj), ri(jj) {
	};
/*
	//在建構式主體,利用"賦值"初始化"

	constRefII(int jjj)
	{
		i = jjj;
		//ci = jj;  //錯誤,const無法賦值
		ri = jjj;
	}
*/
private:
	int i;
	const int ci;
	int &ri;
};


	//建構式初始化順序//
/*
 * 建構式初始化順序是根據變數定義順序,不是初始化執行順序
 */

class Order
{
	int i;
	int j;
public:
	Order(int val):j(val),i(j){ } //錯誤,拿未被初始化的j來初始化i
};

int mainClassInitial() {

	system("pause");
	return 0;
}