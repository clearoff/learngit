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
//	cout << "refnum:" << refnum << endl;            //改变了指针变量的指向  依然不能改变refnum是num引用的事实
//	return 0;
//}

//int main()
//{
//	int Num = 10;
//	const int &refNum = Num;
//    cout << "Num:" << Num << endl;
//    cout << "refNum:" << refNum << endl;
//	//refNum = 20;                                  //错误的代码  不能向常量的引用赋值
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
//	Cube(a+3);             //错误传参   非常量引用的 初始值必须为左值
//	cout << a << endl;
//}



//关于函数形参为const引用类型的临时变量是否创建的问题
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
//    int num2 = 3;            //传参时创建临时变量
//      long int num3=2;       //传参时不创建临时变量
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
	//Date(int _year,int _month,int _day)       //构造函数没有返回值类型
	//{                                         //相当于带有默认参数的构造函数           
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
	Date(int _year = 2000, int _month = 01, int _day = 01)       //构造函数没有返回值类型
		:m_year(_year)
		, m_month(_month)
		, m_day(_day)
	{                                                
		//m_year = _year;
		//m_day = _day;
		//m_month = _month;
	}
	Date(const Date &_date)             //拷贝构造函数
	{
		m_year = _date.m_year;
		m_day = _date.m_day;
		m_month = _date.m_month;
	}
	bool operator==(const Date & _date)       //等号运算符重载
	{
		return (m_day == _date.m_day) && (m_year == _date.m_year) && (m_month == _date.m_month);
	}
	Date& operator=(const Date& date)         //赋值运算符重载
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
	Date date1(date);                //利用拷贝构造函数来创建对象
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