/****************************************
[5/24/2017  21:20]
�������Y�B���.cpp
****************************************/

#include<iostream>

using namespace std;

class Date
{
public:
	Date(int y, int m, int d):year(y),month(m),day(d) {
	}
	bool operator==(const Date&);
	bool operator>(const Date&);
	
	
private:
	int year, month, day;
};

	bool Date::operator==(const Date& eq){
		return (year == eq.year) && (month == eq.month) && (day == eq.day);
	}

bool Date::operator>(const Date& le){
	if(year==le.year)
	{
		if (month == le.month)
			return day > le.day;
		return month > le.month;
	}
	return year > le.year;
}



int mainBigger_then(){
	Date s(1920, 2, 4);
	Date s2(1920, 3, 4);
	bool a = s2 > s;
	cout << a << endl;

	



system("pause");
return 0;
}