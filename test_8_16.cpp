//位运算：统计二进制数中1的个数
//#include <iostream>
//using namespace std;
////int Number_of_1(char num)        //方法一:（将统计的二进制数进行右移在与1操作）   缺点  容易引起死循环  
////{
////	int count=0;
////	while (num)
////	{
////		if ((num & 1) == 1)
////			count++;
////		num=num >> 1;
////	}
////	return count;
////}
//
//
//int Number_of_1(char num)          //方法二  （将1先与Num进行与运算，然后再左移，直到为0为止）
//{
//	int count = 0;
//	char tmp = 1;
//	while (tmp)
//	{
//		if ((tmp&num) != 0 )
//		{
//			count++;
//		}
//		tmp = tmp << 1;
//	}
//	return count;
//}
//
// 
////int Number_of_1(char num)           //方法三   （一个数减去1再和它未减去1之前的数去进行与运算能够削去这个数最右边的1）
////{
////	int count = 0;
////	while (num)
////	{
////		count++;
////		num = (num - 1)&num;
////	}
////	return count;
////}
//
//
//int main()
//{
//	cout << Number_of_1(255) << endl;
//	return 0;
//}
//-------------------------------------------------------------------------------
#include <iostream>

using namespace std;
class  Date
{
public:
	Date()
	{
		cout << "Date ()" << endl;
		++sCount;
	}
	void  Display()
	{
		cout << "year:" << _year << endl;
		cout << "month:" << _month << endl;
		cout << "day:" << _day << endl;
	}
	//  静态成员函数
	static void  PrintCount()                //静态成员函数只能访问静态成员
	{
		cout << "Date count:" << sCount << endl;

	}
private:
	int Return_count()
	{
		return 0;
	}
private:
	int  _year;      //  年
	int  _month;     //  月
	int  _day;       //  日
private:
	static  int  sCount ;  //  静态成员变量，统计创建时间个数
	static  int Initcount();
	static Date date;      //  可以再一个类中，用该类的类型来声明一个静态成员变量
	//不完全类型：   有声明，却没有定义的类型
	//Date date1;
	Date* date1;
};
int Date::Initcount()
{
	return 0;
}
//  定义并初始化静态成员变量
int  Date::sCount =Initcount();             //注：   静态成员变量必须在类外进行初始化  在类中只能是声明
void  Test()
{
	Date  d1, d2;
	//  访问静态成员
	Date::PrintCount();
}
void    Test2()
{
	Date d1;
	Date::PrintCount();
}
int main()
{
	Test();
	Test2();
	return 0;
}