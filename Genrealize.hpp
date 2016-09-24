#pragma once
#include <assert.h>
#include <iostream>
using namespace std;


enum Type
{
	HEAD_TYPE,
	VALUE_TYPE,
	SUB_TYPE,
};

struct GeneralizedNode
{ 
	Type _type;
	GeneralizedNode*  _next;
	union{
		char _value;
		GeneralizedNode* _SubLink;    //指向子表的指针
	};
	GeneralizedNode()
		:_next(NULL)
		, _SubLink(NULL)
	{
	}
};

class GeneralizedList
{
	typedef GeneralizedNode Node;
public:
	GeneralizedList()
		:_Head(NULL)
	{}
	GeneralizedList(const char* _str)
		:_Head(NULL)
	{
		_Head = _CreateList(_str);
	}
	GeneralizedList(const GeneralizedList& gl)
	{
		_Head=_Copy(_Head, gl._Head);
	}
	~GeneralizedList()
	{
		Destory(_Head);
	}
	void Print()
	{
		_Print(_Head);
		cout << endl;
	}
	size_t Size()
	{
		return _size(_Head);
	}
	size_t Depth()
	{ 
		return _Depth(_Head);
	}
private:
	void Destory(Node* head)
	{
		Node* del = head;
		while (head)
		{
			del = head;
			if (head->_type == SUB_TYPE)
			{
				Destory(head->_SubLink);
				head = head->_next;
			}
			else
			{
				head = head->_next;
				delete del;
			}
		}
	}
	Node* _Copy(Node* Dst,Node* src)
	{
		assert(src);
		Node* NewHead = new Node;
		Dst = NewHead;
		Node* cur = src;
		NewHead->_type = cur->_type;
		while (cur)
		{
			if (cur->_type == VALUE_TYPE)
			{
				NewHead->_next = new Node;
				NewHead = NewHead->_next;
				NewHead->_value = cur->_value;
				NewHead->_type = VALUE_TYPE;
				cur = cur->_next;
			}
			else if (cur->_type == SUB_TYPE)
			{
				NewHead->_next = new Node;
				NewHead = NewHead->_next;
				NewHead->_SubLink = _Copy(NewHead->_SubLink, cur->_SubLink);
				NewHead->_type = SUB_TYPE;

				cur = cur->_next;
			}
			else
			{
				cur = cur->_next;
			}
		}
		return Dst;
	}
	size_t _Depth(Node* head)
	{
		Node* cur = head;
		size_t MaxDep = 1;          //空表的深度为1
		size_t Dep = 1;
		while (cur)
		{
			if (cur->_type == SUB_TYPE)
			{
				Dep += _Depth(cur->_SubLink);
				if (Dep > MaxDep)
				{
					swap(Dep, MaxDep);
				}
				Dep = 1;
			}
			cur = cur->_next;
		}
		return MaxDep;
	}
	size_t _size(Node* head)
	{
		size_t size = 0;
		Node* cur = head;
		while (cur)
		{
			if (cur->_type == VALUE_TYPE)
			{
				size++;
			}
			else if (cur->_type == SUB_TYPE)
			{
				size += _size(cur->_SubLink);
			}
			cur = cur->_next;
		}
		return size;
	}
	void _Print(Node* head)
	{
		Node* cur = head;
		while (cur)
		{
			if (cur->_type == VALUE_TYPE)
			{
				cout << cur->_value;
				if (cur->_next != NULL)
				{
					cout << ",";
				}
				cur = cur->_next;
			}
			else if (cur->_type == SUB_TYPE)
			{
				_Print(cur->_SubLink);
				if (cur->_next != NULL)
				{
					cout << ",";
				}
				cur = cur->_next;
			}
			else 
			{
				cout << "(";
				cur = cur->_next;
			}
		}
		cout << ")";
	}
	Node* _CreateList(const char*& str,Node* _head=new Node)
	{
		assert(*(str++) == '(');
		_head->_type = HEAD_TYPE;
		Node* prev = _head;
		while (*str != '\0')
		{
			if (*str == '(')         //子表的创建条件
			{
				prev->_next = new Node;
				prev = prev->_next;
				prev->_SubLink=_CreateList(str);
				prev->_type = SUB_TYPE;
				str++;
			}
			else if (*str == ')')        //递归终止条件
			{
				return _head;
			}
			else if (_IsValue(*str))
			{
				prev->_next = new Node;
				prev = prev->_next;
				prev->_type = VALUE_TYPE;
				prev->_value = *str;
				str++;
			}
			else   // (',', ' ')的处理情况
			{
				str++;
			}
		}
		return _head;
	}
	bool _IsValue(char c)
	{
		if (('a' <= c&&c <= 'z') || ('A' <= c&&c <= 'Z') || ('0' <= c&&c <= '9'))
		{
			return true;
		}
		else
			return false;
	}
protected:
	GeneralizedNode* _Head;
};