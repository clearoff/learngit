#include <iostream>

using namespace std;

//inline int Squre(int x)
//{
//	return x*x;
//}
//
//
//int main()
//{
//	int  num = 5;
//	num = Squre(12-1);      //������������
//	cout << num << endl;
//	return 0;
//}

//#define  Squre(x)   (x)*(x)
//
//
//int main()
//{
//	int x = 5;
//	cout<<Squre(++x)<<endl;
//	return 0;
//}
//������Ԫ��
class Date
{
	friend class Time;
private:
	int m_year;
	int m_month;
	int m_day;
public:
	Date(int _year = 1996, int _month = 3, int _day = 24)
		: m_year(_year)
		, m_month(_month)
		, m_day(_day)
	{
		cout << "Date()" << endl;
	}
	Date(const Date& _date)             //ע�⣺�������캯���Ĳ�������д����������
	{
		cout << "Date(const)" << endl;
		m_year  = _date.m_year;
		m_month = _date.m_month;
		m_day   = _date.m_day;
	}
	~Date()
	{
		cout << "~Date()" << endl;
	}
};
//  ��Ԫ����
class Time
{
	friend class Date;
private:
	int m_hour;
	int m_minute;
	int m_second;
	Date m_date;
public:
	Time(Date& _date,int _hour, int _minute, int _second);
	~Time();
	Time(const Time& _time);
	void Display()  const;
	friend Time& operator*(const int num,Time& _time);
	//�汾1
	//friend void operator<<(ostream& os, const Time& _time);
	//friend void operator>>(istream& is, Time& _time);
	//�汾2
	friend ostream& operator<<(ostream& os, const Time& _time);
};


Time::Time( Date& _date,int _hour = 0, int _minute = 0, int _second = 0)
: m_hour(_hour)
, m_minute(_minute)
, m_second(_second)
, m_date(_date)
{
	cout << "Time()" << endl;
}
Time::~Time()
{
	cout << "~Time()" << endl;
}
Time::Time(const Time& _time)
{
	m_hour = _time.m_hour;
	m_minute = _time.m_minute;
	m_second = _time.m_second;
	cout << "Time(const)" << endl;
}
void Time::Display()  const
{ 
	cout << m_date.m_year << "��" << m_date.m_month << "��" << m_date.m_day << "��" << endl;
	cout << m_hour << ":" << m_minute << ":" << m_second << endl;
}
Time& operator*(const int num,Time& _time)
{
	_time.m_second *= num;
	_time.m_hour *= num;
	_time.m_minute *= num;

	return _time;
}
//�汾1
//void operator<<(ostream& os, const Time& _time)   //����<<�����
//{
//	os << _time.m_hour << ":" << _time.m_minute << ":" << _time.m_second << endl;
//}
//void operator>>(istream& is, Time& _time)        //����>>�����
//{
//	is >> _time.m_hour >> _time.m_minute >> _time.m_second;
//}

//�汾2
//����ʹ��  cout<<time1<<time2<<.....<<time n ��ʽ
ostream& operator<<(ostream& os, const Time& _time)
{
	os << _time.m_hour << "hour " << _time.m_minute << "minute " << _time.m_second << "second " << endl;
	return os;
}
//void test()
//{
//	Time time1(3, 13, 15);
//	Time time2(time1);
//	time1.Display();
//	time2 = 3 * time2;  //��Ԫ����
//	time2.Display();
//	//cin >> time2;
//	cout << time2<<time1;
//}

//void test2()
//{
//	int x = 1;
//	int y = 2;
//	cout << x << y << endl;
//}
//void test3()         //��ɾ���Ķ���
//{
//	Time* time3 = new Time();
//	time3->Display();
//	delete time3;
//	time3->Display();
//}
void test4()
{
	Date date1(2016, 8, 9);            //����
	Time time1(date1, 12, 39, 40);     //date1�Ŀ�������  time1�Ĺ���
	time1.Display();
}
int main()
{
	//test3();
	//test2();
	test4();
	return 0;
}