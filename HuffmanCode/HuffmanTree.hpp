#pragma once 

#include <iostream>
using namespace std;
#include "Heap.hpp"
#include <cassert>


//HuffmanTree节点
template<class T>
struct HuffmanTreeNode
{
	T _Weight;
	HuffmanTreeNode<T>* _Left;
	HuffmanTreeNode<T>* _Right;
	HuffmanTreeNode<T>* _Parent;

	HuffmanTreeNode(const T x)
		:_Weight(x)
		, _Left(NULL)
		, _Right(NULL)
		, _Parent(NULL)
	{}

	HuffmanTreeNode()
		:_Left(NULL)
		, _Right(NULL)
		, _Parent(NULL)
	{}
};



//HuffmanTree
template<class T,class Compare>
class HuffmanTree
{
	typedef HuffmanTreeNode<T> Node;
public:
	HuffmanTree()
		:_root(NULL)
	{}

	HuffmanTree(T* a, size_t size)
	{
		//建HuffmanTree节点的最小堆
		struct NodeLess
		{
			bool operator()(Node* left, Node* right)            //仿函数
			{
				return (left->_Weight) < (right->_Weight);
			}
		};

		//建堆
		Heap<Node*,NodeLess> minHeap;
		for (size_t i = 0; i < size; i++)
		{
			Node* NewNode = new Node(a[i]);
			minHeap.Push(NewNode);            //向堆中push HuffmanTree的节点
		}

		//构造HuffmanTree
		while (minHeap.size()>1)
		{
			Node* left = minHeap.Top();
			minHeap.Pop();
			Node* right = minHeap.Top();
			minHeap.Pop();

			Node* NewNode = new Node((left->_Weight + right->_Weight));
			NewNode->_Left = left;
			NewNode->_Right = right;
			left->_Parent = NewNode;
			right->_Parent = NewNode;
			minHeap.Push(NewNode);
			_root = NewNode;
		}
	}


	//析构函数
	~HuffmanTree()
	{
		assert(_root);
		_HuffmanTreeDestory(_root);
		_root = NULL;
	}
protected:
	void _HuffmanTreeDestory(Node* root)
	{
		if (root != NULL)
		{
			_HuffmanTreeDestory(root->_Left);
			_HuffmanTreeDestory(root->_Right);
			delete root;
			root = NULL;
		}
	}
protected:
	Node* _root;
};