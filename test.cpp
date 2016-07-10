#include <iostream>
using namespace std;

class Date
{
private:
	int m_year;
	int m_month;
	int m_day;
public:
	Date(int _year=1990,int _month=3, int _day=24)
		:m_day(_day)
		, m_month(_month)
		, m_year(_year)
	{
		cout << "Date()" << endl;
	}
	//~Date()
	//{
	//  cout<<
	//}
	void Show() const
	{
		cout << m_year << "-" << m_month << "-" << m_day << endl;
	}
	friend Date operator+(Date _Date1,Date& _Date2);
	friend ostream& operator<<(ostream &os, const Date& _date);
	friend void operator>>(istream &is, Date &_date);
};
 Date operator+(Date _Date1, Date& _Date2)
{
	Date _Date;
	_Date.m_day = _Date1.m_day + _Date2.m_day;
	_Date.m_month = _Date1.m_month + _Date2.m_month+_Date.m_day/31;
	_Date.m_year = _Date1.m_year + _Date2.m_year + _Date.m_month / 12;
	_Date.m_day = _Date.m_day % 31;
	_Date.m_month = _Date.m_month % 12;
	return  _Date;
}
ostream& operator<<(ostream &os, const Date& _date)
 {
	 os << _date.m_year << "-" << _date.m_month << "-" << _date.m_day << endl;
	 return os;
 }
void operator>>(istream &is, Date &_date)
{
	is >> _date.m_year >> _date.m_month >> _date.m_day;
}
int main()
{
	//Date date1;
	//date1.Show();
	//Date date2(2000, 10, 22);
	//date2.Show();
	//Date date = date1 + date2;
	//date.Show();
	Date date;
	Date date1(2000,1,1);
	cout<<date<<date1<<endl;
	cin >> date;
	cout << date;
	return 0;
}

