#pragma once 
#include <cassert>
#include <iostream>
using namespace std;

template<class T>
struct Node
{
	T _Data;
	Node<T>* _Next;
	Node<T>* _Prev;

	Node(const T& x)                  //节点的构造函数
		:_Data(x)
		, _Next(NULL)
		, _Prev(NULL)
	{}
};

template<class T, class Ref, class Ptr>
struct List_Iterator               //迭代器
{
	typedef Node<T> Node;
	typedef List_Iterator<T, Ref, Ptr> Self;

	List_Iterator(Node* node)
		:_Node(node)
	{}
	List_Iterator()
	{}

	Ref operator*()
	{
		return _Node->_Data;
	}
	Self& operator+(int x)
	{
		while (x > 0)
		{
			_Node = _Node->_Next;
			x--;
		}
		return *this;
	}
	Self& operator++()        //前置++
	{
		_Node = _Node->_Next;
		return *this;
	}
	Self operator++(int)     //后置++
	{
		//Self tmp(_Node);
		Self tmp(*this);
		_Node=_Node->_Next;
		return tmp;
	}
	Self& operator--()
	{
		_Node = _Node->_Prev;
		return *this;
	}
	Self operator--(int)
	{
		Self tmp(*this);
		_Node = _Node->_Prev;
		return tmp;
	}
	Ptr operator->() const
	{
		return &(operator*());
	}
	bool operator==(const Self& s)  const
	{
		return  _Node == s._Node;
	}
	bool operator!=(const Self& s) const
	{
		return _Node != s._Node;
	}
public:
	Node* _Node;
};



template<class T>
class List{
	typedef Node<T> Node;
public:
	typedef List_Iterator<T, T&, T*> Iterator;                    //迭代器
	typedef List_Iterator<T, const T&, const T*>  const_Iterator; //const 类型的迭代器
public:
	List()
	{
		_Head = BuyNode(T());
		_Head->_Next = _Head;
		_Head->_Prev = _Head;
	}
	//void PushBack(const T& x)
	//{
	//	Node* _tail = _Head->_Prev;
	//	Node* _tmp = new Node(x);

	//	_tail->_Next = _tmp;
	//	_tmp->_Prev = _tail;

	//	_tmp->_Next = _Head;
	//	_Head->_Prev = _tmp;
	//}
	void PushBack(const T&x)
	{
		Insert(End(), x);
	}
	void PushFront(const T&x)
	{
		Insert(Begin(), x);
	}
	Iterator Begin()
	{
		return Iterator(_Head->_Next);   //返回迭代器
	}

	Iterator End()
	{
		return Iterator(_Head);
	}
	void Erase(Iterator pos)
	{
		assert(pos != End());
		Node* cur = pos._Node;

		cur->_Prev->_Next = cur->_Next;
		cur->_Next->_Prev = cur->_Prev;

		delete cur;
		cur = NULL;
	}
	void Insert(Iterator pos,const T& x)
	{
		Node* cur = pos._Node;
		Node* tmp = BuyNode(x);

		//tmp->_Next = cur;
		//cur->_Prev = tmp;
		tmp->_Prev = cur->_Prev;
		cur->_Prev->_Next = tmp;

		tmp->_Next = cur;
		cur->_Prev = tmp;
	}
	//~List()
	//{
	//	delete 
	//}
protected:
	Node* BuyNode(const T& x)
	{
		Node* _node = new Node(x);
		return _node;
	}
private:
	Node* _Head;                                                  //定义指向头节点的指针，方便维护
};