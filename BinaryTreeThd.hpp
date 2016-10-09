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


//迭代器
template<class T,class Ref,class Ptr>
struct Tree_Iterator
{
public:
	typedef BinaryTreeNode<T> Node;
	typedef Tree_Iterator<T, Ref, Ptr> Self;
	typedef Tree_Iterator<T, const T&, const T*> Const_Iterator;
public:
	//constructor
	Tree_Iterator(Node* node=NULL)
		:_Node(node)
	{}
	//Tree_Iterator()
	//	:_Node(NULL)
	//{}

	Self& operator++()                //使搜索二叉树的节点向大的方向移动
	{
		if (_Node->_RightTag == ThreadType)
		{
			_Node = _Node->_Right;
		}

		else if ((_Node->_RightTag == LinkType) && (_Node->_Right != NULL))               //如果_Node的右子树不是线索类型，则找到右子树中的最左边节点
		{
			Node* cur = _Node;
			cur = cur->_Right;
			while ((cur->_Left != NULL) && (cur->_LeftTag == LinkType))
			{
				cur = cur->_Left;
			}
			_Node = cur;
		}
		else
			return *this;
		return *this;
	}

	Self& operator--()
	{
		if ((_Node->_LeftTag == ThreadType) && (_Node->_Left != NULL))        //如果左孩子指针为线索化类型
		{
			_Node = _Node->_Left;
		}

		else if ((_Node->_LeftTag == LinkType) && (_Node->_Left != NULL))         //左孩子指针为节点类型
		{
			Node* cur = _Node->_Left;
			while ((cur->_Right != NULL) && (cur->_RightTag == LinkType))
			{
				cur = cur->_Right;
			}
			_Node = cur;
		}
		else
			return *this;
		return _Node;
	}

	bool operator==(const Self& pos)
	{
		return pos._Node = -_Node;
	}

	bool operator!=(const Self& pos)
	{
		return _Node != pos._Node;
	}

	T& operator*()
	{
		return _Node->_Data;
	}
private:
	Node* _Node;
};

template<class T>
class BinaryTreeThd
{
public:

	typedef BinaryTreeNode<T> Node;
	typedef BinaryTreeNode<T>* pNode;
	typedef Tree_Iterator<T, T&, T*> Iterator;
	typedef Tree_Iterator<T, const T&, const T*> Const_Iterator;

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

	/*void InThreadNR()
	{
		Node* cur = _root;
		Node* Prev = NULL;
		Node* Tail = NULL;
		while (cur)
		{
			while (cur->_Left)
			{
				Tail=T
				cur = cur->_Left;
			}

			if (cur->_Left == NULL)
			{
				cur->_LeftTag = ThreadType;
				cur->_Left = Prev;
			}

			if (Prev&&Prev->_Right == NULL)
			{
				Prev->_RightTag = ThreadType;
				Prev->_Right = cur;
			}
			Prev = cur;
		}
	}*/

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
		cout << endl;
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

//线索化二叉树的插入
	void InsertNode(const T& x)
	{
		Node* cur = _root;
		Node* Prev = NULL;
		if (_root == NULL)
		{
			_root = new Node(x);
				return;
		}

		while (cur)
		{
			Prev = cur;
			if (cur->_Data > x)
			{
				if (cur->_LeftTag == LinkType)
					cur = cur->_Left;

				else
				{
					break;
					/*Node* tmp = cur->_Left;
					Node* NewNode = new Node(x);
					cur->_LeftTag == LinkType;
					cur->_Left = NewNode;
					NewNode->_Left = tmp;
					NewNode->_LeftTag = ThreadType;
					NewNode->_RightTag = ThreadType;
					NewNode->_Right = cur;*/
				}
			}
			else if (cur->_RightTag == LinkType)
				cur = cur->_Right;
			else
				break;
		}
		if (Prev->_Data > x)
		{
			if (Prev->_LeftTag == LinkType)
			{
				Prev->_Left = new Node(x);
				Prev->_Left->_RightTag = ThreadType;
				Prev->_Left->_Right = Prev;
			}

			else      //如果指针是线索化类型
			{
				Node* tmp = Prev->_Left;
				Node* NewNode = new Node(x);
				Prev->_LeftTag = LinkType;
				Prev->_Left = NewNode;
				NewNode->_Left = tmp;
				NewNode->_LeftTag = ThreadType;
				NewNode->_RightTag = ThreadType;
				NewNode->_Right = Prev;
			}
		}
		else if (Prev->_RightTag == LinkType)
		{
			Node* NewNode = new Node(x);
			NewNode->_RightTag = ThreadType;
			Prev->_RightTag = LinkType;
			NewNode->_Right = Prev->_Right;
			Prev->_Right = NewNode;
		}
		else
			Prev->_Right = new Node(x);
	}

	Iterator Begin()
	{
		Node* cur = _root;
		while (cur->_Left != NULL && (cur->_LeftTag == LinkType))
		{
			cur = cur->_Left;
		}
		return Iterator(cur);
	}

	Iterator End()
	{
		Node* cur = _root;
		while (cur->_Right!=NULL)
		{
			cur = cur->_Right;
		}
		return Iterator(cur);                  //返回最后一个节点的下一个节点
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

		_InThread(root->_Left, Prev);       //线索化左子树

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