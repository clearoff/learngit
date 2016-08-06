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

//  ��Ԫ����
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
	//�汾1
	//friend void operator<<(ostream& os, const Time& _time);
	//friend void operator>>(istream& is, Time& _time);
	//�汾2
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
void test()
{
	Time time1(3, 13, 15);
	Time time2(time1);
	time1.Display();
	time2 = 3 * time2;  //��Ԫ����
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