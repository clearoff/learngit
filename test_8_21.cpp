#include <iostream>
#include <string>
using namespace std;

//class Person
//{
//public:
//	Person()
//		:_pub(1)
//		, _pro(2)
//		, _pri(3)
//	{}
//	void Show()
//	{
//		cout << "_pub::" << _pub << endl;
//		cout << "_pro::" << _pro << endl;
//		cout << "_pri::" << _pri << endl;
//	}
//public:
//	int _pub;
//protected:
//	int _pri;
//protected:
//	int _pro;
//};
//
//
//class Student :private Person
//{
//public:
//	void Show()
//	{
//		cout << "_pub::" << _pub << endl;
//		cout << "_pro::" << _pro << endl;
//		cout << "_pri::" << _pri << endl;      //子类不能访问从父类的私有成员
//	}
//};
//
//int main()
//{
//	Person per;
//	per.Show();
//	Student stu;
//	stu.Show();
//	return 0;
//}



//class A
//{
//public:
//	int _pub;
//protected:
//	int _pro;
//private:
//	int _pri;
//};
//class B:public A
//{
//	void Show()
//	{
//		cout << "_pub::" << _pub << endl;   
//		cout << "_pro::" << _pro << endl;
//		cout << "_pri::" << _pri << endl;
//	}
//};
//
//class Person
//{
//public:
//	void Show(int x)
//	{
//		cout << _name << endl;
//	}
//public:
//	string _name = "Person";
//};
//class Student :public Person
//{
//public:
//	int Show(void)
//	{
//		cout << _name << endl;
//		return 0;
//	}
//public:
//	string _name = "Student";
//};
//int main()
//{
//	Student stu;
//	cout << stu.Person::_name << endl;
//	stu.Person::Show(1);    //注意基类中与子类同名成员的调用方式
//	return 0;
//}

class A
{
public:
	A(int _num)
		:m_num(_num)
	{
		cout << "A()" << endl;
	}
	A(const A& _a)
		:m_num(_a.m_num)
	{
		cout << "A(const)" << endl;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
	A& operator=(const A& _a)
	{
		cout << "A::operator=()" << endl;
		this->m_num = _a.m_num;
		return *this;
	}
	const A* operator&() const
	{
		cout << "A::const oeprator&()" << endl;
		return this;
	}
	A*  operator&()
	{
		cout << "A::oeprator&()" << endl;
		return this;
	}
protected:
	int m_num;
};
class B :public A
{
public:
	B(const int _num=100,const char _c='\0')
		:A(_num)
		, m_c(_c)
	{
		cout << "B()" << endl;
	}
	B(const B& _b)
		:A(_b)
		, m_c(_b.m_c)
	{
		cout << "B(const)" << endl;
	}
	~B()
	{
		cout << "~B()" << endl;
	}
	B& operator=(const B& _b)
	{
		cout << "B::operator=()" << endl;
		this->m_c = _b.m_c;
		return *this;
	}
	const B* operator&() const
	{
		cout << "B::const oeprator&()" << endl;
		return this;
	}
	B*  operator&()
	{
		cout << "B::oeprator&()" << endl;
		return this;
	}
protected:
	char m_c;
};
void test1()
{
	B b(10,'a');
	&b;
}
int main()
{
	test1();
	return 0;
}