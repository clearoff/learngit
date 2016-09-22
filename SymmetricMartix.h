#pragma once 
#include <iostream>
#include <cassert>
using namespace std;
#include <vector>

template<class T>
class SymmetricMatrix
{
public:
	SymmetricMatrix(T* a, size_t size)
		:_n(size)
		, _size(0)
		, Array(new T[(_n*(_n + 1)) / 2])
	{
		//for (size_t i = 0; i < _n; i++)
		//{
		//	for (size_t j=0; j <=i; j++)
		//	{
		//		Array[i] = new T[j + 1];
		//	}
		//}
		for (size_t i = 0; i < _n; i++)
		{
			for (size_t j = 0; j < _n; j++)
			{
				if (i >= j)
				{
					Array[i*(i + 1) / 2 + j] = a[i*_n+j];
					_size++;
				}
				else
				{
					continue;
				}
			}
		}
		cout << "SymmetricMatrix had Inited" << endl;
	}
	void DisPlay()
	{
		assert(Array);
		for (size_t i = 0; i < _size; i++)
		{
			cout << Array[i] << " ";
		}
		cout << endl;
		cout << endl;
		for (size_t i = 0; i < _n; i++)
		{
			for (size_t j = 0; j < _n; j++)
			{
				if (j>i)
				{
					swap(i, j);
					cout << Array[i*(i + 1) / 2 + j] << " ";
					swap(i, j);
				}
				else
				{
					cout << Array[i*(i + 1) / 2 + j] << " ";
				}
			/*	cout << Array[i*(i + 1) / 2 + j] << " ";*/
			}
			cout << endl;
		}
	}
	~SymmetricMatrix()
	{
		if (Array)
		{
			cout << "SymmetricMatrix had used over" << endl;
			delete[] Array;
		}
		Array = NULL;
	}
protected:
	size_t _n;      //存储对称数组的行列
	size_t _size;   //存储数组元素的个数
	T* Array;
};