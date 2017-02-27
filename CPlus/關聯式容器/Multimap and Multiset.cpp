#include<iostream>
#include <map>
#include<string>

using namespace std;


int main()
{
	multimap<string, string>author;
	author.insert(multimap<string,string>::value_type("Barth John", "Sot-Weed"));
	author.insert(make_pair("Barth John", "Lost in the Fun house"));
	
	
	//int erase_count = 0;
	//erase_count = author.erase("Barth John");   //erase()��^�R��key���ҧt�����Ӽ�
	//cout << erase_count << endl;

	//�p���Xkey�̩Ҧ���??
	//�覡�@ �Q��count() , find()
	typedef multimap<string, string>::size_type author_count;
	author_count ac = author.count("Barth John");
	multimap<string, string>::iterator ai = author.find("Barth John");
	for(author_count i=0;i!=ac;i++,ai++)
		cout << ai->second << endl;

	//�覡�G   �Q��multimap & multiset �M�ݰ϶����� lower_bound,upper_bound 
	//�p�Gkey���s�b,lower_bound�|���V����wkey�j���Ĥ@�Ӥ���,�ҥH����lower_bound�Pupper_bound�ۦP
	typedef multimap<string, string>::iterator author_it;
	author_it beg = author.lower_bound("Barth John");  
	author_it end = author.upper_bound("Barth John");
	while(beg!=end)
	{
		cout << beg->second << endl;
		beg++;
	}

	//�覡�T �Q��equal():lower_bound�Pupper_bound���X��;��^�Ȭ�key�Ĥ@�Ӥ�����key�̫�@�Ӥ���
	pair<author_it, author_it>eq_search = author.equal_range("Barth John");
	while(eq_search.first!=eq_search.second)
	{
		cout << eq_search.first->second << endl;
		++eq_search.first;
	}

	system("pause");
	return 0;
}