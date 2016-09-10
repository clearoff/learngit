#pragma once 
#include <assert.h>
#include <iostream>
template<class T>
struct Node
{
	Node<T>* _next;
	T _data;
public:
	Node(const T& x)
		:_data(x)
		,_next(NULL)
	{
	}
};

template<class T>
class Queue
{
public:
	Queue()
		:m_front(NULL)
		, m_tail(NULL)
	{}
	//Queue()
	void Push(const T& x)
	{
		if (m_front == m_tail&&m_front == NULL)
		{
			m_front = m_tail = new Node<T>(x);
		}
		else
		{
			m_tail->_next = new Node<T>(x);
			m_tail = m_tail->_next;
		}
	}
	void Pop()
	{
		Node<T>* tmp = m_front;
		m_front = m_front->_next;
		delete tmp;
	}
	T& Front()
	{ 
		assert(m_front);
		return m_front->_data;
	}
	T& Back()
	{
		assert(m_tail);
		return m_tail->_data;
	}
	int Size()
	{
		int size = 0;
		Node<T>* cur = m_front;
		while (cur != m_tail->_next)
		{
			size++;
			cur = cur->_next;
		}
		return size;
	}
	bool Empty()
	{
		return m_front == NULL;
	}
protected:
	Node<T>* m_front;       //队头指针
	Node<T>* m_tail;        //队尾指针
};
