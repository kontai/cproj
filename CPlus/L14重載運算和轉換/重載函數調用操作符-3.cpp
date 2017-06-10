/****************************************
[6/3/2017  10:46]
������ƽեξާ@��-3.cpp
****************************************/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

template <typename elementMultiply> //���k
class IsMultiply
{
public:
	elementMultiply operator()(const elementMultiply ele1,const elementMultiply ele2){
		return ele1 * ele2;
	}
	
private:
	elementMultiply div;

};

int main_�G��(){
	vector<int> a, b;
	for(vector<int>::size_type i=0,j=0;i<10 ;i++,j++)
	{
		a.push_back(i);
		b.push_back(j);
	}

	vector<size_t>result;
	result.resize(10);

	transform(a.begin(), a.end(), b.begin(), result.begin(), IsMultiply<int>()); //STL
	
	for (vector<int>::size_type i = 0;i != result.size();i++)
		cout << result[i] << "  ";



system("pause");
return 0;
}