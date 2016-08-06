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
//	num = Squre(12-1);      //内联与宏的区别
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

//  友元函数
class Time
{
private:
	int m_hour;
	int m_minute;
	int m_second;
public:
	Time(int _hour, int _minute, int _second);
	~Time();
	Time(const Time& _time);
	void Display()  const;
	friend Time& operator*(const int num,Time& _time);
	//版本1
	//friend void operator<<(ostream& os, const Time& _time);
	//friend void operator>>(istream& is, Time& _time);
	//版本2
	friend ostream& operator<<(ostream& os, const Time& _time);
};
Time::Time(int _hour = 0, int _minute = 0, int _second = 0)
: m_hour(_hour)
, m_minute(_minute)
, m_second(_second)
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
	cout << m_hour << ":" << m_minute << "-" << m_second << endl;
}
Time& operator*(const int num,Time& _time)
{
	_time.m_second *= num;
	_time.m_hour *= num;
	_time.m_minute *= num;

	return _time;
}
//版本1
//void operator<<(ostream& os, const Time& _time)   //重载<<运算符
//{
//	os << _time.m_hour << ":" << _time.m_minute << ":" << _time.m_second << endl;
//}
//void operator>>(istream& is, Time& _time)        //重载>>运算符
//{
//	is >> _time.m_hour >> _time.m_minute >> _time.m_second;
//}

//版本2
//可以使用  cout<<time1<<time2<<.....<<time n 形式
ostream& operator<<(ostream& os, const Time& _time)
{
	os << _time.m_hour << "hour " << _time.m_minute << "minute " << _time.m_second << "second " << endl;
	return os;
}
void test()
{
	Time time1(3, 13, 15);
	Time time2(time1);
	time1.Display();
	time2 = 3 * time2;  //友元函数
	time2.Display();
	//cin >> time2;
	cout << time2<<time1;
}

void test2()
{
	int x = 1;
	int y = 2;
	cout << x << y << endl;
}
int main()
{
	test();
	//test2();
	return 0;
}