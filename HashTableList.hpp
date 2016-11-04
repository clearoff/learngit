#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <vector>

//加入仿函数
template<class T>
struct HashFunc
{
	size_t operator()(const T& key)
	{
		return key;
	}
};
template<>
struct HashFunc<string>
{
	static size_t BKDRHash(const char* str)
	{
		unsigned int seed = 131;// 31 131 1313 13131 131313
		unsigned int hash = 0;
		while (*str)
		{
			hash = hash*seed + (*str++);
		}
		return(hash & 0x7FFFFFFF);
	}
	size_t operator()(const string& str)
	{
		return BKDRHash(str.c_str());
	}
};

template<class K,class V>
struct KVNode
{
	K _Key;
	V _Value;
	KVNode<K, V>* _next;

	KVNode(const K& key,const V& value)
		:_Key(key)
		, _Value(value)
		, _next(NULL)
	{}
};


namespace HashTableList
{
	template<class K, class V, class _HashFunc = HashFunc<K>>
	class HashTable
	{
		typedef KVNode<K, V> Node;
	public:
		HashTable()
			:_size(0)
		{}

		bool Insert(const K& key, const V& value)
		{
			_CheckSize();
			size_t index = GetIndex(key);
			Node* cur = Find(key);
			if (cur == NULL)
			{
				//如果cur不为NULL 
				//头插
				Node* newNode = new Node(key, value);
				newNode->_next = _tables[index];
				_tables[index] = newNode;
				_size++;
				return true;
			}
			return false;
		}

		bool Remove(const K& key)
		{
			size_t index = GetIndex(key);
			Node* cur = _tables[index];
			Node* prev = NULL;
			while (cur)
			{
				if (cur->_Key == key)
				{
					//删除操作
					if (prev == NULL)     //如果prev为NULL,说明第一个节点就为要找的节点
					{
						_tables[index] = cur->_next;
						delete cur;
						_size--;
						return true;
					}
					prev->_next = cur->_next;
					delete cur;
					_size--;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}

		Node* Find(const K& key)
		{
			int index = GetIndex(key);
			Node* cur = _tables[index];
			while (cur)
			{
				if (cur->_Key == key)
				{
					return cur;
				}
				cur = cur->_next;
			}
			return NULL;
		}

	protected:
		void _CheckSize()
		{
			if (_tables.size() == _size)
			{
				size_t NewSize = GetNewSize();


				//现代写法
				HashTable<K, V> ht;
				ht._tables.resize(NewSize);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					ht.Insert(_tables[i]->_Key, _tables[i]->_Value);
				}
				_Swap(ht);
			}
		}

		void _Swap(HashTable& ht)
		{
			_tables.swap(ht._tables);
			swap(_size, ht._size);
		}

		size_t GetNewSize()
		{
			//素数表
			const int _PrimeSize = 28;
			static const unsigned long _PrimeList[_PrimeSize] =
			{
				53ul, 97ul, 193ul, 389ul, 769ul,
				1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
				49157ul, 98317ul, 196613ul, 393241ul,
				786433ul,
				1572869ul, 3145739ul, 6291469ul, 12582917ul,
				25165843ul,
				50331653ul, 100663319ul, 201326611ul, 402653189ul,
				805306457ul,
				1610612741ul, 3221225473ul, 4294967291ul
			};
			for (size_t i = 0; i < _PrimeSize; i++)
			{
				if (_PrimeList[i]>_tables.size())
				{
					return _PrimeList[i];
				}
			}
			return _PrimeList[_PrimeSize - 1];
		}

		size_t GetIndex(const K& key)
		{
			_HashFunc hf;
			return hf(key) % _tables.size();
		}
	protected:
		vector<Node*> _tables;
		size_t _size;
	};
}
