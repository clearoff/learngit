#ifndef SPARESEMARITX_H__
#define SPARESEMARITX_H__


#include <iostream>
using namespace std;
#include <cassert>
#include <vector>

template<class T>
struct Triple     //三元组
{
	Triple(size_t row, size_t col, const T& value)
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
	SparseMartix()
	{}
	SparseMartix(T* _a, size_t _m, size_t _n, const T& invaild)
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
					_v.push_back(Triple<T>(i, j, _a[i*_ColSize + j]));
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
					(_v[index]._row == i) &&
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
		cout << endl;
	}
	void Transport()
	{
		assert(_v.size() > 0);
		SparseMartix<T> _sm;         //存贮转置矩阵有效元素的数组
		_sm._ColSize = _RowSize;
		_sm._RowSize = _ColSize;
		_sm._v.reserve(_size);
		for (int i = 0; i < _RowSize; i++)
		{
			size_t index=0;
			while (index < _v.size())
			{
				if ((_v[index]._Value != _invalid)&&
					_v[index]._col==i)
				{
					_sm._v.push_back(Triple<T>(_v[index]._col, _v[index]._row, _v[index]._Value));
					//index++;
				}
				index++;
			}
		}
		swap(*this, _sm);
	}
protected:
	vector<Triple<T>> _v;
	size_t _ColSize;
	size_t _RowSize;
	T _invalid;
	size_t _size;
};

#endif  //SPARESEMARITX_H__