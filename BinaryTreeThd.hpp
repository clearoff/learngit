#pragma once
#include <iostream>
using namespace std;
#include <assert.h>


enum PointerType
{
	LinkType,
	ThreadType,
};


template<class T>
struct BinaryTreeNode
{
	T _Data;
	BinaryTreeNode<T>* _Left;
	BinaryTreeNode<T>* _Right;
	PointerType _LeftTag;
	PointerType _RightTag;

	BinaryTreeNode()
		:_Data(T())
		, _Left(NULL)
		, _Right(NULL)
		, _LeftTag(LinkType)
		, _RightTag(LinkType)
	{}
	BinaryTreeNode(const T& x)
		:_Data(x)
		, _Left(NULL)
		, _Right(NULL)
		, _LeftTag(LinkType)
		, _RightTag(LinkType)
	{}
};


template<class T>
class BinaryTreeThd
{
	typedef BinaryTreeNode<T> Node;
	typedef BinaryTreeNode<T>* pNode;
public:
	BinaryTreeThd()
		:_root(NULL)
	{}
	BinaryTreeThd(const T* str, const size_t size, const T& invaild)
	{
		cout << "创建二叉树" << endl;
		size_t index = 0;
		_root = _CreateBinaryTree(str, size, invaild, index);
	}

	void InThread()                            //中序线索化
	{
		assert(_root);
		Node* Prev = NULL;
		_InThread(_root, Prev);
	}

	void InThreadOrder()
	{
		assert(_root);
		Node* cur = _root;
		while (cur)
		{
			while (cur->_LeftTag == LinkType)
			{
				cur = cur->_Left;
			}
			cout << cur->_Data << " ";
			while (cur->_RightTag == ThreadType)
			{
				cur = cur->_Right;
				cout << cur->_Data << " ";
			}
			cur = cur->_Right;          //进入右子树
		}
	}

	void  PrevThread()                 //前序线索化（递归）
	{
		assert(_root);
		Node* Prev = NULL;
		_PrevThread(_root, Prev);
	}

	void PrevThreadOrder()             //前序线索化二叉树的遍历
	{
		assert(_root);
		Node* cur=_root;

		while (cur)
		{
			//遍历当前节点
			cout << cur->_Data << " ";

			if (cur->_LeftTag == LinkType)
				cur = cur->_Left;

			else
				cur = cur->_Right;
			
		}
	}

	void PostThread()                //后序线索化二叉树
	{
		assert(_root);
		Node* Prev = NULL;
		_PostThread(_root, Prev);
	}

	void PostThreadOrder()
	{
		assert(_root);
		Node* cur = _root->_Left;
		while (cur != _root)
		{
			while (cur->_LeftTag == LinkType)
				cur = cur->_Left;
			cout << cur->_Data << " ";
			while (cur->_RightTag == ThreadType)
			{
				cur = cur->_Right;
				cout << cur->_Data << " ";
			}

			//cout << cur->_Data << " ";
		}
		cout << endl;
	}
private:
	void _PostThread(Node* root, pNode& Prev)
	{
		if (root == NULL)
			return;

		if (root->_LeftTag == LinkType)
			_PostThread(root->_Left, Prev);

		if (root->_RightTag == LinkType)
			_PostThread(root->_Right, Prev);

		if (root->_Left == NULL)
		{
			root->_LeftTag = ThreadType;
			root->_Left = Prev;                     //当前节点指向上一个节点
		}

		if (Prev&&Prev->_Right == NULL)
		{
			Prev->_RightTag = ThreadType;
			Prev->_Right = root;
		}

		Prev = root;                               //更换前一个节点
	}

	void _PrevThread(Node* root, pNode& Prev)
	{
		if (root == NULL)
			return;

		if (root->_Left == NULL)
		{
			root->_LeftTag = ThreadType;
			root->_Left = Prev;
		}

		if (Prev&&Prev->_Right == NULL)
		{
			Prev->_RightTag = ThreadType;
			Prev->_Right = root;
		}
		Prev = root;

		if (root->_LeftTag==LinkType)                   //线索化左子树
		       _PrevThread(root->_Left, Prev);

		if (root->_RightTag==LinkType)                 //线索化右子树
		       _PrevThread(root->_Right, Prev);
	}

	void _InThread(Node* root, pNode& Prev)
	{
		if (root == NULL)
		{
			return;
		}

		_InThread(root->_Left, Prev);

		if (root->_Left == NULL)            //没有左孩子
		{
			root->_LeftTag = ThreadType;
			root->_Left = Prev;
		}

		if (Prev&&Prev->_Right == NULL)
		{
			Prev->_RightTag = ThreadType;
			Prev->_Right = root;
		}

		Prev = root;

		_InThread(root->_Right, Prev);
	}
	Node* _CreateBinaryTree(const T*& a, size_t size, const T& invaild, size_t& index)
	{
		Node* root = NULL;
		if ((index < size) && (a[index] != invaild))
		{
			root = new Node(a[index]);
			root->_Left = _CreateBinaryTree(a, size, invaild, ++index);
			root->_Right = _CreateBinaryTree(a, size, invaild, ++index);
		}
		return root;
	}
protected:
	Node* _root;
};