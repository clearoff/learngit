//#include <iostream>
//
//using namespace std;
//
//class Date
//{
//public:
//	Date()=default;
//	~Date();
//	Date(const Date& _date);
//private:
//	static const int NUM_TURNS = 5;
//	enum{ NUM_TURN=5};
//	int Arr[NUM_TURN] = {1,2,3,4,5};
//public:
//	void Display() const;
//};
//const int Date:: NUM_TURNS;    //非静态成员变量不能定义在类外
//void Date::Display() const
//{
//	int i = 0;
//	for (i = 0; i < NUM_TURN; i++)
//	{
//		cout << Arr[i] << endl;
//	}
//}
//int main()
//{
//	Date date1(1,2,3,4,5);
//	date1.Display();
//	return 0;
//}

#include <iostream>
using namespace std;

class Date
{
private:
	int m_year=1996;
	int m_month=3;
	int m_day=24;
public:
	Date(int _year, int _month, int _day)
		:m_year(_year)
		, m_month(_month)
		, m_day(_day)
	{
		cout << "Date()" << endl;
	}
	Date() = default;
	~Date()
	{
		cout << "~Date()" << endl;
	}
	Date(const Date& _date)
	{
		this->m_year = _date.m_year;
		this->m_month = _date.m_month;
		this->m_day = _date.m_day;
	}
	Date operator++();        //前置++
	Date& operator++(int);    //后置++
	Date& operator=(const Date& _date);         //赋值运算符重载
	friend ostream& operator<<(ostream& os,const Date& _date);           //输出运算符重载
	Date& operator>>(istream& is);           //输入运算符重载
};

Date Date :: operator++()        //前置++
{
	//先返回  在++
	Date _date(*this);
	this->m_year++;
	this->m_month++;
	this->m_day++;
	return _date;
}
Date& Date:: operator++(int)    //后置++
{
	this->m_year++;
	this->m_month++;
	this->m_day++;
	return *this;
}
Date& Date:: operator=(const Date& _date)         //赋值运算符重载
{
	this->m_year = _date.m_year;
	this->m_month = _date.m_month;
	this->m_day = _date.m_day;
	return *this;
}
ostream& operator<<(ostream& os, const Date& _date)           //输出运算符重载  注意  友元函数为非成员函数  一定不要加上作用域解析运算符
{
	os << _date.m_year << "-" << _date.m_month << "-" << _date.m_day;
	return os;
}
Date& Date:: operator>>(istream& is)           //输入运算符重载
{
	is >> m_day >> m_month >> m_day;
	return *this;
}
int main()
{
	Date date(2016, 8, 18);
	
	cout << (date++)<<endl;
	cout << (++date) << endl;
	cout << (date) << endl;
	return 0;
}