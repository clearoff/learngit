//#include <iostream>
//
//using namespace std;

//int main()
//{
//	int num = 10;
//	int *pNum = &num;
//    int &refnum = *pNum;;
//	cout << "num:" << num << endl;
//	cout << "refnum:" << refnum << endl;
//	int num1 = 20;
//	pNum = &num1;
//	cout << "num1:" << num1 << endl;
//	cout << "refnum:" << refnum << endl;            //�ı���ָ�������ָ��  ��Ȼ���ܸı�refnum��num���õ���ʵ
//	return 0;
//}

//int main()
//{
//	int Num = 10;
//	const int &refNum = Num;
//    cout << "Num:" << Num << endl;
//    cout << "refNum:" << refNum << endl;
//	//refNum = 20;                                  //����Ĵ���  �������������ø�ֵ
//	cout << "Num:" << Num << endl;
//	cout << "refNum:" << refNum << endl;
//	return 0;
//}


//void Cube(int &ra)
//{
//	
//}
//int main()
//{
//	int a = 3;
//	Cube(a+3);             //���󴫲�   �ǳ������õ� ��ʼֵ����Ϊ��ֵ
//	cout << a << endl;
//}



//���ں����β�Ϊconst�������͵���ʱ�����Ƿ񴴽�������
//void Swap(const long int &a, const long int &b)
//{
//	//int tmp;
//	//tmp = (int)a;
//	//(long int)a = (int)b;
//	//(long int)b = tmp;
//}
//
//
//int main()
//{
//    int num1 = 2;
//    int num2 = 3;            //����ʱ������ʱ����
//      long int num3=2;       //����ʱ��������ʱ����
//	cout << "num1:" << num1 << endl;
//	cout << "num2:" << num2 << endl;
//	Swap(num1, num2);
//	cout << "Swap;;num1:" << num1 << endl;
//	cout << "Swap;;num2:" << num2 << endl;
//	return 0;
//}


//#include <iostream>
//
//using namespace std;
//class Time
//{
//
//};
//
//int main()
//{
//	Time time;
//	cout<<sizeof(time)<<endl;
//	return 0;
//}


#include <iostream>

using namespace std;

class Date
{
private:
	int m_month;
	int m_year;
	int m_day;
public:
	void Display()
	{
		cout << "Year:" << m_year << " Month:" << m_month << " Day:" << m_day << endl;
	}
	//Date(int _year,int _month,int _day)       //���캯��û�з���ֵ����
	//{                                         //�൱�ڴ���Ĭ�ϲ����Ĺ��캯��           
	//	S_year = _year;
	//	S_day = _day;
	//	S_month = _month;
	//}
	//Date()
	//{
	//	S_year = 2000;
	//	S_day = 01;
	//	S_month = 01;
	//}
	Date(int _year = 2000, int _month = 01, int _day = 01)       //���캯��û�з���ֵ����
		:m_year(_year)
		, m_month(_month)
		, m_day(_day)
	{                                                
		//m_year = _year;
		//m_day = _day;
		//m_month = _month;
	}
	Date(const Date &_date)             //�������캯��
	{
		m_year = _date.m_year;
		m_day = _date.m_day;
		m_month = _date.m_month;
	}
	bool operator==(const Date & _date)       //�Ⱥ����������
	{
		return (m_day == _date.m_day) && (m_year == _date.m_year) && (m_month == _date.m_month);
	}
	Date& operator=(const Date& date)         //��ֵ���������
	{
		this->m_year = date.m_year;
		this->m_month = date.m_month;
		this->m_day = date.m_day;
		return *this;
	}
};
int main()
{
	Date date;
	Date date1(date);                //���ÿ������캯������������
	Date date2(2015, 01, 01);
	date.Display();
	date1.Display();
	date2.Display();
	cout << date.operator==(date1) << endl;
	cout << (date == date1) << endl;
	date=date1 = date2;
	date1.Display();
	date.Display();
	return 0;
}