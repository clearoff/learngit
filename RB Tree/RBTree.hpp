#pragma once

#include <iostream>
using namespace std;
#include <cassert>

enum Colour
{
	RED,
	BLACK,
};

template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _Parent;
	RBTreeNode<K, V>* _Left;
	RBTreeNode<K, V>* _Right;

	K _Key;
	V _Value;
	Colour _Col;

	RBTreeNode(const K& Key, const V& Value)
		:_Parent(NULL)
		, _Left(NULL)
		, _Right(NULL)
		, _Key(Key)
		, _Value(Value)
		, _Col(RED)
	{}
};


template<class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(NULL)
	{}

	bool Insert(const K& Key,const V& Value)
	{
		//若根节点为空，直接插入节点
		if (_root == NULL)
		{
			_root = new Node(Key, Value);
			_root->_Col = BLACK;
			return true;
		}

		Node* parent = NULL;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_Key > Key)
			{
				parent = cur;
				cur = cur->_Left;
			}
			else if (cur->_Key < Key)
			{
				parent = cur;
				cur = cur->_Right;
			}
			else
				return false;
		}

		cur = new Node(Key, Value);
		if (parent->_Key < Key)
		{
			parent->_Right = cur;
			cur->_Parent = parent;
		}
		else
		{
			parent->_Left = cur;
			cur->_Parent = parent;
		}

		//进行调整
		//如果当前节点不为根节点并且parent的颜色为红色则进行调整
		
		while (cur != _root && parent->_Col == RED)
		{
			Node* GrandNode = parent->_Parent;          //定义祖父节点
			//parent 为左树
			if (parent == GrandNode->_Left)
			{
				Node* UncleNode = GrandNode->_Right;
				//情况1
				if (UncleNode&&UncleNode->_Col == RED)
				{
					parent->_Col = UncleNode->_Col = BLACK;
					GrandNode->_Col = RED;

					cur = GrandNode;
					parent = cur->_Parent;
				}
			   //情况二和三
				else
				{
					if (cur == parent->_Right)
					{
						_RotateL(parent);
						swap(parent, cur);
					}
					_RotateR(GrandNode);
					GrandNode->_Col = RED;
					parent->_Col = BLACK;

					cur = parent;
					parent = cur->_Parent;
				}
			}
			//parent 在右树
			else
			{
				Node* UncleNode = GrandNode->_Left;
				//情况1
				if (UncleNode&&UncleNode->_Col == RED)
				{
					parent->_Col = UncleNode->_Col = BLACK;
					GrandNode->_Col = RED;

					//继续向上调整
					cur = GrandNode;
					parent = cur->_Parent;
				}
				//情况2、3
				else
				{
					if (cur == parent->_Left)
					{
						_RotateR(parent);
						swap(cur, parent);
					}
					_RotateL(GrandNode);
					GrandNode->_Col = RED;
					parent->_Col = BLACK;

					cur = parent;
					parent = cur->_Parent;
				}
			}
		}
		_root->_Col = BLACK;
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool IsBalance()
	{

		if (_root == NULL)
			return true;

		//根节点不能为红色
		if (_root->_Col == RED)
			return false;

		//统计一条路径上的黑色节点的个数
		int RefCount = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_Col == BLACK)
				RefCount++;
			cur = cur->_Left;
		}
		int count = 0;
		return _IsBalance(_root,RefCount,count);

	}
protected:
	bool _IsBalance(Node* root,const int RefCount,int count)
	{
		//如果root为空则比较当前节点到根节点路径的黑色节点的数目是否与REF相等
		if (root == NULL)
		{
			return RefCount == count;
		}

		//相邻节点不能为红色
		Node* parent = root->_Parent;
		if (parent && (parent->_Col == RED&&root->_Col == RED))
			return false;

		if (root->_Col == BLACK)
			count++;                     //遇到黑节点 count++

		return _IsBalance(root->_Left, RefCount, count)
			&& _IsBalance(root->_Right, RefCount, count);
	}

	void _RotateL(Node* parent)
	{
		Node* SubR = parent->_Right;
		Node* SubRL = SubR->_Left;
		Node* ppNode = parent->_Parent;

		parent->_Right = SubRL;
		if (SubRL)
			SubRL->_Parent = parent;
		SubR->_Left = parent;
		parent->_Parent = SubR;
		if (ppNode == NULL)
		{
			SubR->_Parent = NULL;
			_root = SubR;
		}
		else
		{
			SubR->_Parent = ppNode;
			if (ppNode->_Left == parent)
				ppNode->_Left = SubR;
			else
				ppNode->_Right = SubR;
		}
	}

	void _RotateR(Node* parent)
	{
		Node* SubL = parent->_Left;
		Node* SubRL = SubL->_Right;
		Node* ppNode = parent->_Parent;

		parent->_Left = SubRL;
		if (SubRL)
			SubRL->_Parent = parent;
		SubL->_Right = parent;
		if (ppNode == NULL)
		{
			SubL->_Parent = NULL;
			_root = SubL;
		}
		else
		{
			SubL->_Parent = ppNode;
			if (ppNode->_Left == parent)
				ppNode->_Left = SubL;
			else
				ppNode->_Right = SubL;
		}
		parent->_Parent = SubL;
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;

		_InOrder(root->_Left);
		cout << root->_Key << " ";
		_InOrder(root->_Right);
	}
protected:
	Node* _root;
};