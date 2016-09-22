#pragma once 
#include <iostream>
using namespace std;
#include <cassert>
#include <vector>

template<class T>
struct Triple     //三元组
{
	Triple(size_t row,size_t col,const T& value)
	:_row(row)
	, _col(col)
	, _Value(value)
	{}
	T _Value;
	size_t _row;
	size_t _col;
};


template<class T>
class SparseMartix
{
public:
	SparseMartix(T* _a,size_t _m,size_t _n,const T& invaild)
		:_RowSize(_m)   //行
		, _ColSize(_n)  //列
		, _invalid(invaild)
		, _size(0)
	{
		for (size_t i = 0; i < _m; i++)
		{ 
			for (size_t j = 0; j < _n; j++)
			{
				if (_a[i*_ColSize + j] != _invalid)
				{
					_v.push_back(Triple<T>(i,j,_a[i*_ColSize+j]));
					_size++;
				}
			}
		}
		cout << "The SparseMartix has been inited" << endl;
	}
	void DisPlay()
	{
		assert(_v.size());
		int index = 0;
		for (size_t i = 0; i < _RowSize; i++)
		{
			for (size_t j = 0; j < _ColSize; j++)
			{
				if (((index)< _v.size()) &&
					(_v[index]._row == i)&&
					(_v[index]._col == j))
				{
					
					cout << _v[index++]._Value << " ";
					
				}
				else
				{
					cout << _invalid << " ";
				}
			}
			cout << endl;
		}
	}
protected:
	vector<Triple<T>> _v;
	size_t _ColSize;
	size_t _RowSize;
	T _invalid;
	size_t _size;
};