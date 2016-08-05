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
	Date(int _year , int _month , int _day );      //����ȱʡ�����Ĺ��캯��
	Date(const Date& _date);                                     //�������캯��
	~Date();                                                     //��������

	int Get_year();
	int Get_month();
	int Get_day();
//����
	void Set_year(const int year);
	void Set_month(const int month);
	void Set_day(const int day);

	int Day_of_month()const;                   //���ص�������
	bool Judge_Leap()const;                         //�ж��Ƿ�Ϊ����

	void Print_Date();                         //��ӡ����

	bool operator==(const Date& _date);                         //�ж����������Ƿ����
	bool operator>(const Date& _date);                          //�ж��������ڵĴ�С��ϵ
	void operator++(int);                                          //��������
	void operator--(int);                                          //�Լ�����
	Date operator+(const int _day);                             //ʵ�����ڼ�����
	Date operator-(const int _day);                             //ʵ�����ڼ�����
	int  operator-(Date& _date);                         //ʵ�����ڼ�����
};

#endif