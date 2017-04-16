/****************************************
[4/16/2017  16:20]
class1.cpp
****************************************/

#include<iostream>
#include<string>

using namespace std;

class Pressent
{
public:
	typedef string::size_type index;
	char get();
	int get(int, int)const;
	char str(const string&);

	Pressent(int, int,const string&);
	Pressent(const string& instr);

	Pressent& ask(const string&);
	Pressent& print(ostream &os);
	 Pressent& move(index wd,index ht);

private:
	int x,y;
	string name;
};

Pressent::Pressent(int a,int b,const string &st):x(a),y(b),name(st){}
Pressent::Pressent(const string &ins):name(ins){ }

char Pressent::get()
{
	return this->x;
}

int Pressent::get(int x,int y)const
{
	return	this->y;
}

char Pressent::str(const string& ins)
{
//	return this->name[1];
	return ins[0];
}

Pressent& Pressent::ask(const string& str)
{
	cout << str << endl;
	return *this;
}

	Pressent& Pressent::print(ostream &os)
{
		os << name;
		return *this;
}
	 Pressent& Pressent::move(index wd,index ht)
{
		return *this;
}

int main(){
	Pressent ini(2,3,"abcd\nefgh\nijkl");
	Pressent str1("kkkkkkkk");
	/*cout << ini.get(23,44) << endl;
	cout << str1.str("abcd") << endl;
	str1.ask("defghij");*/
	ini.move(23,44).print(cout);
	

system("pause");
return 0;
}