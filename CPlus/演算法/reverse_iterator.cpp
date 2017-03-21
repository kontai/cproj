#include <iostream>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

int mainReverse_iterator()
{
	vector<int>vec;
	for (vector<int>::size_type i = 0;i != 10;++i)
		vec.push_back(i);
	
	// reverse iterator of vector from back to front  
	vector<int>::reverse_iterator r_iter;     
	for (r_iter = vec.rbegin();r_iter != vec.rend();  ++r_iter)
// binds r_iter to last element  ;  vec.rbegin()=vec�̫�@�Ӥ���
//rend refers 1 before 1st element  vec.rend()=vec�Ĥ@�Ӥ������e�@�Ӧ�m
// decrements iterator one element   reverse_iterator+1 
//���дN�|���e�@�Ӧ�m,����rbegin   

		cout << *r_iter << endl;  
	// prints 9,8,7,...0 

///////////////////////////////////////////////////////////////////////////////////

	//find   first word before the comma
	string str = "abc,def,ghi";
	string::iterator comma = find(str.begin(), str.end(), ',');
	cout << string(str.begin(), comma) << endl;

	string::reverse_iterator rcomma = find(str.rbegin(), str.rend(), ',');
	cout << string(str.rbegin(), rcomma)<<endl; 
	cout << string(rcomma.base(),str.end() )<<endl; 
	//base()�O�C��reverse_iterator���O����ƪ������禡
	// [str.rbegin,rcomma] �M [rcomma.base(),str.end()]���ۦP�϶�
	//��rcomma.base �P rcomma �ҫ���m���P(�N�pstr.end()�Pstr.end())


	system("pause");
	return 0;
}