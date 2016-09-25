#pragma once 
#include <iostream>
using namespace std;
#include <assert.h>
#include <queue>

template<class T>
struct BinaryTreeNode
{
	T _Data;
	BinaryTreeNode<T>* _Left;
	BinaryTreeNode<T>* _Right;
	BinaryTreeNode()
		:_Left(NULL)
		, _Right(NULL)
		, _Data(T())
	{}
	BinaryTreeNode(const T&  x)
		:_Data(x)
		, _Left(NULL)
		, _Right(NULL)
	{}
};


template<class T>
class BinaryTree
{
	typedef BinaryTreeNode<T> Node;
public:
	BinaryTree()
		:_root(NULL)
		//, _index(0)
	{}
	BinaryTree(const T* str,size_t size,const T& invaild)
		//:_index(0)
	{
		cout << "创建二叉树" << endl;
		size_t index = 0;
		_root=_CreateBinaryTree(str,size,invaild,index);          //前序创建二叉树
	}
	~BinaryTree()
	{
		_Destroy(_root);
	}
	BinaryTree(const BinaryTree<T>& BT)
	{
		_root=_Copy(BT._root);
	}
	void PrevOrder()                                        //前序遍历二叉树
	{ 
		assert(_root);
		_PreOrder(_root);
		cout << endl;
	}
	void InOrder()
	{
		assert(_root);
		_InOrder(_root);
		cout << endl;
	}
	void PostOrder()
	{
		assert(_root);
		_PostOrder(_root);
		cout << endl;
	}
	void LevelOrder()   //层序遍历
	{
		queue<Node*> q1;
		q1.push(_root);
		while (!q1.empty())
		{
			cout << q1.front()->_Data << " ";
			if (q1.front()->_Left != NULL)
			{
				q1.push((q1.front()->_Left));
			}
			if (q1.front()->_Right != NULL)
			{
				q1.push((q1.front()->_Right));
			}
			q1.pop();
		}
		cout << endl;
	}
	size_t Depth()        //二叉树的深度
	{
			return _Depth(_root);
	}
	size_t Size()         //二叉树结点个数
	{
		return _Size(_root);
	}
	size_t LeafSize()     //叶子节点个数
	{
		return _LeafSize(_root);
	}
protected:
	void _Destory(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		else if (root->_Left=NULL&&root->_Right==NULL)
		{
			delete root;
		}
		else
		{
			_Destory(root->_Left);
			_Destory(root->_Right);
		}
	}
	Node* _Copy(Node* root)
	{
		Node* NewNode = new Node;
		if (root == NULL)
		{ 
			return NULL;
		}
		else
		{
			NewNode->_Data = root->_Data;
			NewNode->_Left = _Copy(root->_Left);
			NewNode->_Right = _Copy(root->_Right);
		}
		return NewNode;
	}
	size_t _LeafSize(Node* root)
	{
		size_t count = 0;
		if (root == NULL)
			return 0;
		else if ((root->_Left) == NULL && (root->_Right == NULL))
		{
			return 1;
		}
		else
		{
			return count+=(_LeafSize(root->_Left) + _LeafSize(root->_Right));
		}
	}
	size_t _Size(Node* root)
	{
		size_t count = 0;
		if (root != NULL)
		{
			count++;
			count += _Size(root->_Left)+_Size(root->_Right);
		}
		else
		{
			return count;
		}
		return count;
	}
	size_t _Depth(Node* root)
	{
		size_t Left_Depth = 1;
		size_t Right_Depth = 1;
		if (root != NULL)
		{
			Left_Depth += _Depth(root->_Left);
			Right_Depth += _Depth(root->_Right);
			return (Left_Depth > Right_Depth) ? Left_Depth : Right_Depth;
		}
		else
		{
			return 0;
		}
	}
	void _PostOrder(Node* root)
	{
		if (root != NULL)
		{
			_PostOrder(root->_Left);
			_PostOrder(root->_Right);
			cout << root->_Data << " ";
		}
		else
		{
			return;
		}
	}
	void _InOrder(Node* root)
	{
		if (root != NULL)
		{
			_InOrder(root->_Left);
			cout << root->_Data<<" ";
			_InOrder(root->_Right);
		}
		else
		{
			return;
		}
	}
	void _PreOrder(Node* root)
	{
		if (root != NULL)
		{
			cout << root->_Data << " ";
			_PreOrder(root->_Left);
			_PreOrder(root->_Right);
		}
		else
		{
			return;
		}
	}
	Node* _CreateBinaryTree(const T*& a, size_t size, const T& invaild,size_t& index)
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