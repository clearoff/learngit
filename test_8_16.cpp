//λ���㣺ͳ�ƶ���������1�ĸ���
//#include <iostream>
//using namespace std;
////int Number_of_1(char num)        //����һ:����ͳ�ƵĶ�������������������1������   ȱ��  ����������ѭ��  
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
//int Number_of_1(char num)          //������  ����1����Num���������㣬Ȼ�������ƣ�ֱ��Ϊ0Ϊֹ��
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
////int Number_of_1(char num)           //������   ��һ������ȥ1�ٺ���δ��ȥ1֮ǰ����ȥ�����������ܹ���ȥ��������ұߵ�1��
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
	//  ��̬��Ա����
	static void  PrintCount()                //��̬��Ա����ֻ�ܷ��ʾ�̬��Ա
	{
		cout << "Date count:" << sCount << endl;

	}
private:
	int Return_count()
	{
		return 0;
	}
private:
	int  _year;      //  ��
	int  _month;     //  ��
	int  _day;       //  ��
private:
	static  int  sCount ;  //  ��̬��Ա������ͳ�ƴ���ʱ�����
	static  int Initcount();
	static Date date;      //  ������һ�����У��ø��������������һ����̬��Ա����
	//����ȫ���ͣ�   ��������ȴû�ж��������
	//Date date1;
	Date* date1;
};
int Date::Initcount()
{
	return 0;
}
//  ���岢��ʼ����̬��Ա����
int  Date::sCount =Initcount();             //ע��   ��̬��Ա����������������г�ʼ��  ������ֻ��������
void  Test()
{
	Date  d1, d2;
	//  ���ʾ�̬��Ա
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