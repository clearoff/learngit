//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	double a = 1.0;
//	double  pi = 3.14;
//	//pi = 3.0; 
//	//   double *Pi = &pi;        (错误：要用常量指针指向一个常量)
//	 double const * Pi = &pi;
//	// *Pi = 1.0;                  错误
//	 return 0;
//}
//————————————————————————————————————
//#include <iostream>
//using namespace std;
//
//class Date
//{
//private:
//	int m_year=1996;
//	int m_month=03;
//	int m_day=24;
//	mutable int count = 0;
//public:
//	Date() = default;
//	Date(int _year, int _month,int _day,int _count);
//	friend ostream &operator<<(ostream &os,const Date _date);
//	void Display_count() const;
//};
//Date::Date(int _year, int _month, int _day,int _count)
//{
//	m_year = _year;
//	m_month = _month;
//	m_day = _day;
//	count = _count;
//}
//ostream &operator<<(ostream &os,const Date _date)
//{
//	os << _date.m_year << "-" << _date.m_month << "-" << _date.m_day;
//
//	return os;
//}
//void Date::Display_count() const
//{
//	count++;               //mutable（可修该的数据成员） 声明的成员 即使在const成员函数中也可以被修改
//	cout << count << endl;
//}
//
//void test()
//{
//	Date date1;
//	cout << date1<<endl;
//	date1.Display_count();
//}
//int main()
//{
//	test();
//	return 0;
//}
//————————————————————————————————————————
//#include <iostream>
//#include <cstdlib>
//
//using namespace std;
//int main()
//{
//	int *arr = (int *)malloc(sizeof(int)* 4);
//	for (int i = 0; i < 4; i++)
//	{
//		arr[i] = i;
//	}
//	cout << arr[2] << endl;
//	free(arr);
//	cout << arr[2] << endl;
//	calloc开辟一块空间并自动将这块空间初始化为0
//	{
//		int *arr = (int*)calloc(4, sizeof(int));
//		cout << arr[0] << endl;
//		cout << arr[1] << endl;
//		int *p3 = (int*)realloc(arr, sizeof(int)* 6);
//		//调用realloc后arr被置为空
//		cout << arr[0] << endl;
//		cout << p3[3] << endl;
//	}
//	cout << "hehe" << endl;
//	return 0;
//}
//————————————————————————————————————————————-
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int main()
//{
//	char arr[] = "abcd";
//	char *arr1 = "abcd";
//	cout <<"arr[]"<< sizeof(arr) << endl;
//	cout <<"*arr "<< sizeof(arr1) << endl;
//	cout << "arr[]strlen:" << strlen(arr) << endl;
//	cout << "*arr1(strlen):" << strlen(arr1) << endl;
//	return 0;
//}
//——————————————————————————————————-
//#include <iostream>
//using namespace std;
//
//
//int main()
//{
//	int *p1 = new int(3);
//	char *p2 = new char[];
//	p2 = "abcdef";
//	cout << p2 << endl;
//	return 0;
//}
//————————————————————————————————————-
#include <iostream>
#include <cstdlib>

using namespace std;
class  Array
{
public:
	Array(size_t  size = 10)
		: _size(size)
		, _a(0)
	{
		cout << "Array(size_t size)" << endl;
		if (_size  > 0)
		{
			_a = new  int[size];
		}
	}
	~Array()
	{
		cout << "~Array()" << endl;
		if (_a)
		{
			delete[]  _a;
			_a = 0;
			_size = 0;
		}
	}
private:
	int*_a;
	size_t    _size;
};
void  Test()
{
	Array*  p1 = (Array*)malloc(sizeof  (Array));
	Array*  p2 = new  Array;
	Array*  p3 = new  Array(20);
	Array*  p4 = new  Array[10];
	free(p1);
	delete  p2;
	delete  p3;
	delete[]  p4;
}

int main()
{
	Test();
	return 0;
}