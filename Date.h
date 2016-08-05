#ifndef DATE_H__
#define DATE_H__
#include <iostream>
using namespace std;

class Date
{
private:
	int m_year;
	int m_month;
	int m_day;
public:
	Date(int _year , int _month , int _day );      //带有缺省参数的构造函数
	Date(const Date& _date);                                     //拷贝构造函数
	~Date();                                                     //析构函数

	int Get_year();
	int Get_month();
	int Get_day();
//设置
	void Set_year(const int year);
	void Set_month(const int month);
	void Set_day(const int day);

	int Day_of_month()const;                   //返回当月天数
	bool Judge_Leap()const;                         //判断是否为闰年

	void Print_Date();                         //打印日期

	bool operator==(const Date& _date);                         //判断两个日期是否相等
	bool operator>(const Date& _date);                          //判断两个日期的大小关系
	void operator++(int);                                          //自增运算
	void operator--(int);                                          //自减运算
	Date operator+(const int _day);                             //实现日期加天数
	Date operator-(const int _day);                             //实现日期减天数
	int  operator-(Date& _date);                         //实现日期减日期
};

#endif