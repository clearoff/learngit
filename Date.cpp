#include "Date.h"



Date::Date(int _year = 1996, int _month = 03, int _day = 24)      //����ȱʡ�����Ĺ��캯��
:m_year(_year)
, m_month(_month)
, m_day(_day)
{
	//
}
Date::Date(const Date& _date)                                     //�������캯��
{
	m_year  = _date.m_year;
	m_day   = _date.m_day;
	m_month = _date.m_month;
}
Date::~Date()                                                     //��������
{
	//��������������ɴ�ӡ��ǰ���ڵĹ�����

}
int Date::Day_of_month() const
{
	int day = 0;
	switch (m_month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		day = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		day = 30;
		break;
	case 2:
		if (Judge_Leap())
			day = 29;
		else
			day = 28;
		break;
	}
	return day;
}

int Date::Get_year()
{
	return this->m_year;
}
int Date::Get_month()
{
	return this->m_month;
}
int Date::Get_day()
{
	return this->m_day;
}
//����
void Date::Set_year(const int year)
{
	m_year = year;
}
void Date::Set_month(const int month)
{
	m_month = month;
}
void Date::Set_day(const int day)
{
	m_day = day;
}


bool Date::Judge_Leap() const
{
	if ((m_year % 400) == 0 || ((m_year % 4) == 0 && (m_year % 100) != 0))
		return true;
	else
		return false;
}

void Date::Print_Date()                         //��ӡ����
{
	cout << m_year << "��" << m_month << "��" << m_day << "��" << endl;
}

Date Date::operator+(const int _day)                             //ʵ�����ڼ�����
{
		m_day += _day;
		while (m_day > Day_of_month())
		{
			m_day -= Day_of_month();
			m_month++;
			if (m_month > 12)
			{
				m_month-=12;
				m_year++;
			}
		}
		return *this;
}
Date Date::operator-(const int _day)                             //ʵ�����ڼ�����
{
	m_day -= _day;
	while (m_day <= 0)
	{
		m_month--;
		if (m_month <= 0)
		{
			m_year--;
			m_month += 12;
		}
		m_day += Day_of_month();
	}
	return *this;
}
bool Date::operator==(const Date& _date)                         //�ж����������Ƿ����
{
	if (m_year == _date.m_year
		&&m_month == _date.m_month
		&&m_day == _date.m_day)
		return true;
	else
		return false;
}
bool Date::operator>(const Date& _date)                          //�ж��������ڵĴ�С��ϵ
{
	if (m_year > _date.m_year)
		return true;
	else if (m_year == _date.m_year)
	{
		if (m_month > _date.m_month)
			return true;
		else if (m_month == _date.m_month)
		{
			if (m_day > _date.m_day)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
void Date::operator++(int)                                          //��������
{
	m_day++;
	if (m_day > Day_of_month())
	{
		m_day -= Day_of_month();
		m_month++;
		if (m_month > 12)
		{
			m_month -= 12;
			m_year++;
		}
	}
	
}
void Date::operator--(int)                                          //�Լ�����
{
	m_day--;
	if (m_day <= 0)
	{
		m_month--;
		if (m_month <= 0)
		{
			m_year--;
			m_month += 12;
		}
		m_day += Day_of_month();
	}
}
int Date::operator-(Date& _date)                         //ʵ�����ڼ�����
{
	int days = 0;
	while (!(*this == _date))
	{
		if (*this > _date)
		{
			_date++;
			days++;
		}
		else
		{
			_date--;
			days--;
		}

	}
	return days;
}