#pragma once
#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

template<class T>
struct Less
{
	bool operator()(const T& left, const T& right)
	{
		return left < right;
	}
};

template<class T>
struct More
{
	bool operator()(const T& left, const T& right)
	{
		return left > right;
	}
};

//最大堆
template<class T,class Compare=More<int>>
class Heap
{
public:
	Heap(T* arr,size_t size)
	{
		_a.resize(size);
		for (size_t i = 0; i < size; i++)
		{
			_a[i] = arr[i];
		}

		//建堆
		for (int i = (_a.size()-2)/2; i >= 0; i--)
		{
			_AdjustDown(i);
		}
	}

	Heap()
	{

	}

	void Push(const T& x)
	{
		_a.push_back(x);               //插入节点
		_AdjustUp(_a.size() - 1);      //向上调整
	}

	void Pop()
	{
		assert(!_a.empty());

		swap(_a[0], _a[_a.size() - 1]);
		_a.pop_back();
		_AdjustDown(0);
	}

	const T&  Top()
	{
		return _a[0];
	}

	size_t size()
	{
		return _a.size();
	}


private:

	void _AdjustUp(size_t root)
	{
		size_t child = root;
		size_t parent = (child - 1) / 2;
		Compare com;
	/*	while (child > 0 && (_a[child] > _a[parent]))*/
		while (child > 0 && (com(_a[child],_a[parent])))
		{
			swap(_a[child], _a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
	}

	void _AdjustDown(size_t root)
	{
		size_t parent = root;
		size_t child = parent * 2 + 1;
		Compare com;

		while (child< _a.size())             //如果孩子越界则终止向下调整
		{
			/*if ((child+1)<_a.size()
				&&(_a[child + 1]>_a[child]))*/
			if ((child + 1)<_a.size()
				&& (com(_a[child+1],_a[child])))
			{
				++child;
			}

			/*if (_a[child] > _a[parent])*/
			if (com(_a[child],_a[parent]))
			{
				swap(_a[child], _a[parent]);
				parent = child;
				child = parent * 2 + 1;
			}
			else
			{
				break;
			}
		}
	}
protected:
	vector<T> _a;
};