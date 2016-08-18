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
//const int Date:: NUM_TURNS;    //�Ǿ�̬��Ա�������ܶ���������
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
	Date operator++();        //ǰ��++
	Date& operator++(int);    //����++
	Date& operator=(const Date& _date);         //��ֵ���������
	friend ostream& operator<<(ostream& os,const Date& _date);           //������������
	Date& operator>>(istream& is);           //�������������
};

Date Date :: operator++()        //ǰ��++
{
	//�ȷ���  ��++
	Date _date(*this);
	this->m_year++;
	this->m_month++;
	this->m_day++;
	return _date;
}
Date& Date:: operator++(int)    //����++
{
	this->m_year++;
	this->m_month++;
	this->m_day++;
	return *this;
}
Date& Date:: operator=(const Date& _date)         //��ֵ���������
{
	this->m_year = _date.m_year;
	this->m_month = _date.m_month;
	this->m_day = _date.m_day;
	return *this;
}
ostream& operator<<(ostream& os, const Date& _date)           //������������  ע��  ��Ԫ����Ϊ�ǳ�Ա����  һ����Ҫ������������������
{
	os << _date.m_year << "-" << _date.m_month << "-" << _date.m_day;
	return os;
}
Date& Date:: operator>>(istream& is)           //�������������
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