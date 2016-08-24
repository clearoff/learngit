#include <iostream>
using namespace std;
#include <string>
#include <cstring>
//
//class Student;
//class   Person
//{
//	friend void Display(Person& _p,Student& _S);
//	protected :
//	string  _name="hehe";                     // 姓名
//};
//class  Student : public  Person
//{
//	friend void Display(Person& _p, Student& _S);
//	protected :
//	int   _stuNum=2016;             // 学号
//};
//void Display(Person& _p,Student& _s)
//{
//	cout <<_p._name<< endl;
//	cout << _s._name<< endl;
//	cout << _s._stuNum <<endl;
//}
//void  TestPerson1()
//{
//	Person  p;
//	Student  s;
//	Display(p,s);
//}
//int main()
//{
//	TestPerson1();
//	return 0;
//}
//
//class A
//{
//public:
//	virtual void Show()
//	{
//		cout << "B::show()" << endl;
//	}
//	virtual void Print()
//	{
//		cout << "B::Print()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A a;
//	typedef void (*pfun_t)();     //指向void的函数指针类型
//		a.Show();
//		(*((int *)*(int *)(&a)))();
//		(*(pfun_t*)(*(int*)(&a)))();
//	return 0;
//}

//class Base
//{
//public:
//	Base()
//		:_b(1)
//	{}
//	virtual void func1()
//	{
//		cout << "Base::func1" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "Base::func1" << endl;
//	}
//private:
//	int _b;
//};
//class Deriver:public Base
//{
//public:
//	Deriver()
//		:_d(2)
//	{}
//	virtual void func1()
//	{
//		cout << "Deriver::func1" << endl;
//	}
//	virtual void func3()
//	{
//		cout << "Deriver::func3" << endl;
//	}
//	virtual void func4()
//	{
//		cout << "Deriver::func4" << endl;
//	}
//private:
//	int _d;
//};
//
//typedef void (*pfun_t)();   //函数指针类型的类型名
//
//void PrintVfptr(pfun_t* ppfun)
//{
//	for (int i = 0;ppfun[i] != NULL; i++)   //虚函数表的结束标志为NULL
//	{
//		ppfun[i]();   //地址()  调用函数
//	}
//	
//}
//
//void test1()
//{
//	Deriver d;
//	PrintVfptr((pfun_t *)(*(int*)&d));
//}
//int main()
//{ 
//	test1();
//	return 0;
//}



//class  Base1
//{
//public:
//	Base1()
//		:b1(1)
//	{}
//	virtual  void  f()
//	{
//		cout << "Base1::f" << endl;
//	}
//	virtual  void  g()
//	{
//		cout << "Base1::g" << endl;
//	}
//private:
//	int  b1;
//};
//class  Base2
//{
//public:
//	Base2()
//		:b2(2)
//	{}
//	virtual  void  f()
//	{
//		cout << "Base2::f" << endl;
//	}
//	virtual  void  g()
//	{
//		cout << "Base2::g" << endl;
//	}
//private:
//	int  b2;
//};
//class  Base3
//{
//public:
//	Base3()
//		:b3(3)
//	{}
//	virtual  void  f()
//	{
//		cout << "Base3::f" << endl;
//	}
//	virtual  void  g()
//	{
//		cout << "Base3::g" << endl;
//	}
//private:
//	int  b3;
//};
//class  Derive : public  Base2, public  Base1,public Base3   //二重继承时有问题！！！！
//{
//public:
//	Derive()
//		:d1(4)
//	{}
//	virtual  void  f()                     //子类如果重写了基类中的虚函数，则会将虚函数表中的基类中的虚函数覆盖
//	{
//		cout << "Derive::f" << endl;
//	}
//	virtual  void  h()                     //派生类自定义的虚函数（非重写）会写在继承列表中的第一个基类的虚函数表
//	{                                      
//		cout << "Derive::h" << endl;
//	}
//private:
//	int  d1;
//};
//
//
//typedef void (*pfun_t)();   //函数指针类型的类型名
//
//void PrintVfptr(pfun_t* ppfun)
//{
//	for (int i = 0;ppfun[i] != NULL; i++)   //虚函数表的结束标志为NULL
//	{
//		ppfun[i]();   //地址()  调用函数
//	}
//	
//}
//
//void test1()
//{
//	Derive d;
//	PrintVfptr((pfun_t*)(*(int *)(&d)));
//	cout << "--------------------------" << endl;
//	PrintVfptr((pfun_t*)(*((int*)&d+2)));
//	cout << "--------------------------" << endl;
//	PrintVfptr((pfun_t*)(*((int*)&d + 4)));
//}
//int main()
//{
//	test1();
//	return 0;
//}


//class  Base1
//{
//public:
//	Base1()
//		:b1(1)
//	{}
//	virtual  void  f()
//	{
//		cout << "Base1::f" << endl;
//	}
//	virtual  void  g()
//	{
//		cout << "Base1::g" << endl;
//	}
//private:
//	int  b1;
//};
//class  Base2
//{
//public:
//	Base2()
//		:b2(2)
//	{}
//	virtual  void  f()
//	{
//		cout << "Base2::f" << endl;
//	}
//	virtual  void  g()
//	{
//		cout << "Base2::g" << endl;
//	}
//private:
//	int  b2;
//};
//class  Derive : public  Base2, public  Base1   //二重继承时有问题！！！！
//{
//public:
//	Derive()
//		:d1(4)
//	{}
//	virtual  void  f()                     //子类如果重写了基类中的虚函数，则会将虚函数表中的基类中的虚函数覆盖
//	{
//		cout << "Derive::f" << endl;
//	}
//	virtual  void  h()                     //派生类自定义的虚函数（非重写）会写在继承列表中的第一个基类的虚函数表
//	{                                      
//		cout << "Derive::h" << endl;
//	}
//private:
//	int  d1;
//};
//
//
//typedef void (*pfun_t)();   //函数指针类型的类型名
//
//void PrintVfptr(pfun_t* ppfun)
//{
//	for (int i = 0;ppfun[i] != NULL; i++)   //虚函数表的结束标志为NULL
//	{
//		ppfun[i]();   //地址()  调用函数
//	}
//	
//}
//
//
//void test()
//{
//	Derive d;
//	PrintVfptr((int*)&d)
//}



class B
{
public:
	B()
		:ib(1)
		, cb('1')
	{}
	virtual void f()
	{
		cout << "B::f()" << endl;
	}
	virtual void Bf()
	{
		cout << "B::Bf()" << endl;
	}
private:
	int ib;
	char cb;
};
class B1:virtual public B
{
public:
	B1()
		:ib1(2)
		, cb1('2')
	{}
	virtual void f() //重写  虚函数表中有 B1::f() /B::Bf() /B1::f1() /B1::Bf1()
	{
		cout << "B1::f()" << endl;
	}
	virtual void f1()
	{
		cout << "B1::f1()" << endl;
	}
	virtual void Bf1()
	{
		cout << "B1::Bf1()" << endl;
	}
private:
	int ib1;
	char cb1;
};
class B2 :virtual public B
{
public:
	B2()
		:ib2(3)
		, cb2('3')
	{}
	virtual void f2()
	{
		cout << "B2::f2()" << endl;
	}
	virtual void f() //重写  虚函数表中有 B2::f() /B::Bf() /B2::f2() /B2::Bf2()
	{
		cout << "B2::f()" << endl;
	}
	virtual void Bf2()
	{
		cout << "B2::Bf2()" << endl;
	}
private:
	int ib2;
	char cb2;
};
class D:public B1,public B2
{
public:
	D()
		:id(4)
		, cd('4')
	{}
	virtual void f3()
	{
		cout << "D::f3()" << endl;
	}
	virtual void f()       //重写
	{
		cout << "D::f()" << endl;
	}
	virtual void Df()
	{
		cout << "D::Df()" << endl;
	}
private:
	int id;
	char cd;
};
typedef void (*pfun_t)();   //函数指针类型的类型名

void PrintVfptr(pfun_t* ppfun)
{
	for (int i = 0;ppfun[i] != NULL; i++)   //虚函数表的结束标志为NULL
	{
		ppfun[i]();   //地址()  调用函数
	}
	
}


void test()
{
	D d;
	PrintVfptr((pfun_t*)(*(int*)&d));   //B2::f2() /B1::Bf1()/D::f3()/D::Df() 6
	cout <<" ---------------------- - "<< endl;
	PrintVfptr((pfun_t*)(*((int*)&d + 4))); //B2::f2() /B2::Bf2() 2
	cout << " ---------------------- - " << endl;
	PrintVfptr((pfun_t*)(*((int*)&d + 11))); //D::f() /B::Bf() 2
}

int main()
{
	test();
	return 0;
}