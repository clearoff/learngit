#pragma once 
#include <cstring>
#include <assert.h>
#include <iostream>
using namespace std;
template <class T>
class Stack
{
public:
	Stack()
		:m_Size(0)
		,m_Capacity(3)
		,m_ptr(new T[m_Capacity])
	{}
	Stack(const Stack<T>& _s)
		:m_Size(_s.m_Size)
		, m_Capacity(_s.m_Capacity)
		, m_ptr(new T[_s.m_Capacity])
	{
		if (_s.m_ptr != nullptr)
		{
			memcpy(m_ptr, _s.m_ptr, sizeof(T)*_s.m_Size);
		}
	}
	void Push(const T x)
	{
		CheckCapacity();
		m_ptr[m_Size] = x;
		++m_Size;
	}
	bool Empty()
	{
		assert(m_ptr);
		return m_Size == 0;
	}
	T& Top()
	{
		assert(m_ptr);
		return m_ptr[m_Size-1];
	}
	void Pop()
	{
		assert(m_ptr);
		assert(m_Size > 0);
		--m_Size;
	}
	size_t size()
	{
		return m_Size;
	}
	~Stack()
	{
		if (m_ptr != NULL)
		{
			cout << "The memory is realse" << endl;
			delete[] m_ptr;
			m_ptr = NULL;
		}
	}
protected:
	void CheckCapacity()
	{
		if (m_Size == m_Capacity)
		{
			cout << "À©ÈÝ" << endl;
			int NewCapacity = 2 * m_Capacity;
			T* tmp = new T[NewCapacity];
			m_Capacity = NewCapacity;
			memcpy(tmp, m_ptr, sizeof(T)*m_Size);
			delete[] m_ptr;
			m_ptr = tmp;
			tmp = NULL;
		}
	}
protected:
	int m_Size;
	int m_Capacity;
	T* m_ptr;
};