/****************************************
[6/3/2017  08:46]
������ƽեξާ@��-2.cpp
****************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template<typename elementMulti>
class IsMulitple
{
public:
	IsMulitple(const elementMulti& add)
	{
		ele_Number = add;
	}
	bool operator()(const elementMulti& get_num){
		return ((get_num%ele_Number) == 0);
	}
private:
	elementMulti ele_Number;

};

int main_�@��(){
	vector<int> ivec;
	for (vector<int>::size_type i = 1;i <= 100;i++)
		ivec.push_back(i);
	IsMulitple<int> a(3);

	vector<int>::iterator itv=find_if(ivec.begin(), ivec.end(), a);
	cout << "�Q3�㰣���Ĥ@�ӼƦr" << *itv << endl;



	



system("pause");
return 0;
}