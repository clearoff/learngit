//#include <iostream>
//using namespace std;
//#include <boost\shared_ptr.hpp>
//using namespace boost;
////#include <memory>
//
//struct ListNode
//{
//	shared_ptr<ListNode> next;
//	shared_ptr<ListNode> prev;
//
//	ListNode(const int& a)
//		:_a(a)
//	{}
//
//	int _a;
//
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//
//void Test()
//{
//	shared_ptr<ListNode> p1(new ListNode(5));
//	shared_ptr<ListNode> p2(new ListNode(6));
//
//	p1->next = p2;
//	p2->prev = p1;
//
//
//}
//
//int main()
//{
//	//shared_ptr<int> p1(new int(5));
//	//int *q = p1.get();
//	//cout << *q << endl;
//	//delete q;            //p1��ָ����ڴ�Ҳ���ͷţ�����ָ��һ�����ֵ
//
//	//unique_ptr<int> p2 = new int(5);      //error 
//	//unique_ptr<int> p2(new int(5));
//	////unique_ptr<int> p3(p2);              //error unique_ptr��֧�ֿ�����������������
//	////unique_ptr<int> p3 = p2;
//	//p2.release();
//	/*Test();*/
//	int a = 5;
//	shared_ptr<int> p1(&a);
//	shared_ptr<int> p2(&a);
//
//	return 0;
//}


//
//#include<iostream>
//using namespace std;
//
//class A
//{
//public:
//	A()
//		:_a(10)
//	{}
//protected:
//	int _a;
//};
//
//class B :public A
//{
//public :
//	B()
//		:_b(5)
//	{}
//protected:
//	int _b;
//};
//
//template<class Base=A,class Derive=B>
//bool IsDerived(const Base* a, const Derive* b)
//{
//	Derive* c;
//	c=dynamic_cast<Derive>(a);
//	if (c == NULL)
//	{
//		return false;
//	}
//	else
//		return true;
//}
//
//int main()
//{
//	A a;
//	B b;
//	cout<<IsDerived(&a,&b)<<endl;
//	return 0;
//}

//�ж�һ�����ܷ���һ����̳�
#include<iostream>
using namespace std;

class A
{
public:
	A()
		:_a(10)
	{}
protected:
	int _a;
};

class B :public A
{
public:
	B()
		:_b(20)
	{}
protected:
	int _b;
};

template<typename Derive, typename Base> 
class TIsDerived
{
public:
	static int t(Base* base)
	{
		return 1;
	}
	static  char t(void* t2)
	{
		return 0;
	}

	static bool IsDerive()
	{
		/*bool Result = (sizeof(int) == sizeof(t((Derive*)NULL)));*/
		bool Result = (sizeof(int) == sizeof(t(new Derive())));
		return Result;
	};
};


int main()
{
	bool   AISDerviedFromB;
	AISDerviedFromB= TIsDerived<B, A>::IsDerive();
	cout << AISDerviedFromB << endl;
	return 0;
}