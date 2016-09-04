#define _CRT_SECURE_NO_WARNINGS
#include<boost/shared_ptr.hpp>
#include<boost/weak_ptr.hpp>
#include <string>
#include <iostream>
using namespace std;
struct A
{
	int _a;
};

template<class T>
class Auto_ptr    //权限转换
{
public:
	Auto_ptr(T* _ptr=nullptr)
		:m_ptr(_ptr)
	{
		cout << "Use auto_ptr" << endl;
	}
	Auto_ptr(Auto_ptr<T>& _ap)   //拷贝构造函数
	{
		if (_ap.m_ptr != NULL)
		{
			m_ptr = _ap.m_ptr;
		}
		_ap.m_ptr = NULL;
	}
	Auto_ptr<T>& operator=(Auto_ptr<T>& _ap)
	{
		if (m_ptr != NULL)
		{
			delete m_ptr;
			m_ptr = NULL;
		}
		m_ptr = _ap.m_ptr;
		_ap.m_ptr = NULL;
		return *this;
	}
	void Show()
	{
		cout <<"Show()"<< end;
	}
	~Auto_ptr()
	{
		cout << "~Auto_ptr()" << endl;
		if (m_ptr != NULL)
		{
			delete m_ptr;
			m_ptr = NULL;
		}
	}
	T* operator->() const
	{
		return this->m_ptr;
	}
public:
	T *m_ptr;
};

template<class T>
class Scope_ptr         //不允许赋值
{
public:
	Scope_ptr(T* _ptr=nullptr)
	    :m_ptr(_ptr)
	{
		cout << "Scope_Ptr()" << endl;
	}
	~Scope_ptr()
	{
		cout << "~Scope_ptr()" << endl;
		if (m_ptr != NULL)
		{
			delete m_ptr;
			m_ptr = nullptr;
		}
	}
	T* operator->()
	{
		return this->m_ptr;
	}
private:
	Scope_ptr(const Scope_ptr<T>& _ptr);
	Scope_ptr<T>& operator=(const Scope_ptr<T>& _ptr);
private:
	T* m_ptr;
};

//template<class T>
//class Shared_ptr          //写时拷贝技术
//{
//public:
//	Shared_ptr(T* _ptr=NULL)
//		:m_ptr(_ptr)
//		, m_pCount(new int(1))
//	{
//		cout << "Shared_ptr()" << endl;
//	}
//	Shared_ptr(const Shared_ptr<T>& _sp)
//		:m_ptr(_sp.m_ptr)
//	{
//		cout << "shared_ptr<T>(shared_ptr<T>& _sp)" << endl;
//		m_pCount = _sp.m_pCount;
//		++(*m_pCount);
//	}
//	Shared_ptr<T>& operator=(Shared_ptr<T>& _sp)
//	{
//		if (this->m_ptr != _sp.m_ptr)
//		{
//			if (--(*m_pCount) == 0)
//			{
//				delete m_ptr;
//				delete m_pCount;
//				m_ptr = NULL;
//				m_pCount = NULL;
//			}
//			m_ptr = _sp.m_ptr;
//			m_pCount = _sp.m_pCount;
//			++(*m_pCount);
//		}
//		return *this;
//	}
//	T* operator->()
//	{ 
//		return this->m_ptr;
//	}
//	Shared_ptr& operator*()
//	{
//		return *this;
//	}
//	int Get_Count()
//	{
//		cout << "Shared_ptr::Count->";
//		return *m_pCount;
//	}
//	T* Get()
//	{
//		return this->m_ptr;
//	}
//	~Shared_ptr()
//	{
//		if (--(*m_pCount) == 0)
//		{
//			cout << "Realse buffer" << endl;
//			delete m_ptr;
//			delete m_pCount;
//			m_ptr = NULL;
//			m_pCount = NULL;
//		}
//	}
//private:
//	T* m_ptr;
//	int* m_pCount;
//};


//struct Node
//{
//	int Data;
//	boost::weak_ptr<Node> _next;
//	boost::weak_ptr<Node> _prev;
//};
//
//void test2()
//{
//	boost::shared_ptr<Node> sp1(new Node);
//	boost::shared_ptr<Node> sp2(new Node);
//	cout << sp1.use_count() << endl;
//	cout << sp2.use_count() << endl;
//	sp1->_next = sp2;
//	sp2->_prev = sp1;
//	cout << sp1.use_count() << endl;
//	cout << sp2.use_count() << endl;
//}
//
//int main()
//{
//	test2();
//	return 0;
//}


struct  Fclose
{
	void operator()(void* ptr)
	{
		cout << "文件版本定制删除器" << endl;
		fclose((FILE*)ptr);
	}
};

struct Delete
{
	void operator() (void *_ptr)
	{
		cout << "默认定制删除器" << endl;
		delete _ptr;
	}
};

//shared_ptr定制删除器版本
template<class T,class D=Delete>        
class Shared_ptr          //写时拷贝技术
{
public:
	Shared_ptr(T* _ptr = NULL)
		:m_ptr(_ptr)
		, m_pCount(new int(1))
		, m_del(D())
	{
		cout << "Shared_ptr()" << endl;
	}
	Shared_ptr(const Shared_ptr<T,D>& _sp)
		:m_ptr(_sp.m_ptr)
		, m_del(_sp.m_del)
	{
		cout << "shared_ptr<T>(shared_ptr<T,D>& _sp)" << endl;
		m_pCount = _sp.m_pCount;
		++(*m_pCount);
	}
	Shared_ptr<T,D>& operator=(Shared_ptr<T,D>& _sp)
	{
		if (this->m_ptr != _sp.m_ptr)
		{
			if (--(*m_pCount) == 0)
			{
				m_del (m_ptr);
				delete m_pCount;
				m_ptr = NULL;
				m_pCount = NULL;
			}
			m_ptr = _sp.m_ptr;
			m_pCount = _sp.m_pCount;
			++(*m_pCount);
		}
		return *this;
	}
	T* operator->()
	{
		return this->m_ptr;
	}
	Shared_ptr<T,D>& operator*() const
	{
		return *this;
	}
	int Get_Count()
	{
		cout << "Shared_ptr::Count->";
		return *m_pCount;
	}
	T* Get()
	{
		return this->m_ptr;
	}
	~Shared_ptr()
	{
		if (--(*m_pCount) == 0)
		{
			cout << "Realse buffer" << endl;
			m_del (m_ptr);
			delete m_pCount;
			m_ptr = NULL;
			m_pCount = NULL;
		}
	}
private:
	D m_del;      //D为删除器类型
	T* m_ptr;
	int* m_pCount;
};

//void test()   //定制删除器
//{
//	shared_ptr<FILE> sp1(fopen("hello.txt", "w"),Fclose());
//}
void test2()
{
	Shared_ptr<FILE,Fclose> sp1(fopen("hello.txt", "w"));
}
void test3()
{
	Shared_ptr<int> sp2(new int(5));
}
int main()
{
	test3();
	return 0;
}