#pragma once 
#include <iostream>
using namespace std;


template<class K, int M>
struct BTreeNode
{
	K _keys[M];                       //�ؼ�������
	BTreeNode<K, M>* _subs[M + 1];    //�ӽڵ�����
	BTreeNode<K, M>* _parent;         //���ڵ�
	size_t _size;

	BTreeNode()
		:_size(0)
		, _parent(NULL)
	{
		for (size_t i = 0; i < M; i++)
		{
			_keys[i] = K();
			_subs[i] = NULL;
		}
		_subs[M] = NULL;
	}

};

template<class K, int M = 3>
class BTree
{
	typedef BTreeNode<K, M> Node;
public:
	BTree()
		:_root(NULL)
	{}

	pair<Node*, int> Find(const K& key)
	{
		
		Node* cur = _root;
		Node* parent = NULL;
		while (cur)
		{
			size_t i = 0;
			while (i < cur->_size)
			{
				if (cur->_keys[i] < key)               //���cur->_keys[i] < key�����±�����ƶ�
				{
					++i;
				}
				else if (cur->_keys[i] > key)          //���cur->_keys[i] > key
				{
					break;
				}
				else
					return pair<Node*, int>(cur, i);   //�ҵ��˷���cur��Ҫ���ҵ�Ԫ����cur->_keys�е��±�
			}
			parent = cur;
			cur = cur->_subs[i];
		}
		return pair<Node*, int>(parent, -1);
	}

	bool Insert(const K& key)
	{
		if (_root == NULL)                    //���ڵ�Ϊ��
		{
			_root = new Node;
			_root->_keys[0] = key;
			_root->_size = 1;
			return true;
		}

		pair<Node*, int> FindNode = Find(key);
		if (FindNode.second != -1)            //�ڵ��Ѿ����ڲ���Ҫ����
		{
			return false;
		}

		//��Ҫ����key
		Node* cur = FindNode.first;         //Ҫ����ڵ�
		Node* parent = cur->_parent;        //Ҫ����ڵ�ĸ��ڵ�
		Node* sub = NULL;
		K newKey = key;
		while (1)
		{
			InsertKey(cur, newKey, sub);       //����ؼ���key
			//�жϷ���
			if (cur->_size < M)
			{
				//����Ҫ����
				return true;
			}

			//���з���
			size_t mid = cur->_size / 2;    //�ҵ��м�ڵ�
			Node* tmp = new Node;
			size_t j = 0;
			newKey = cur->_keys[mid];
			size_t i = 0;
			for (i = mid + 1; i < cur->_size; i++)    //����cur->_keys�м��±��ұߵĹؼ���
			{
				//subs��keys�Ŀ���
				tmp->_keys[j] = cur->_keys[i];
				tmp->_subs[j] = cur->_subs[i];     //errot
				j++;

				if (cur->_subs[i])
					cur->_subs[i]->_parent = tmp;
				//�ָ�subs��keys��Ĭ��ֵ
				cur->_subs[i] = NULL;
				cur->_keys[i] = K();

				//����size
				cur->_size--;
				tmp->_size++;
			}
			tmp->_subs[j] = cur->_subs[i];
			if (cur->_subs[i])
				cur->_subs[i]->_parent = tmp;
			cur->_subs[i] = NULL;

			cur->_keys[mid] = K();
			cur->_size--;

			if (parent == NULL)   //cur�Ǹ��ڵ�
			{
				_root = new Node;
				_root->_keys[0] = newKey;
				_root->_size = 1;

				_root->_subs[0] = cur;
				_root->_subs[1] = tmp;

				if (cur)
					cur->_parent = _root;
				if (tmp)
					tmp->_parent = _root;
				return true;
			}

			//cur���Ǹ��ڵ㣬�������ϵ���
			cur = parent;
			parent = cur->_parent;
			sub = tmp;
		}
	}

	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
protected:
	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		Node* prev = NULL;
		for (size_t i = 0; (i < root->_size); i++)
		{
			if (root->_subs[i]!=prev)
				_InOrder(root->_subs[i]);
			cout << root->_keys[i] << " ";
			if (root->_subs[i + 1])
			{
				_InOrder(root->_subs[i + 1]);
				prev = root->_subs[i + 1];
			}
		}
	}

	void InsertKey(Node* node, const K& key, Node* sub)
	{
		int i = node->_size - 1;              //ȡ�õ�ǰ�ڵ��keys�����һ���ؼ��ֵ��±�
		while (i >= 0)
		{
			if ((node->_keys[i] < key))
			{
				break;
			}
			else   //node->keys[i] > key    �ƶ��ؼ��ֺ�subs
			{
				node->_keys[i + 1] = node->_keys[i];
				node->_subs[i + 2] = node->_subs[i + 1];
			}
			i--;
		}
		node->_keys[i + 1] = key;          //����ؼ���key
		node->_subs[i + 2] = sub;          //����sub
		node->_size++;
		if (sub)
			sub->_parent = node;          //subָ���丸�ڵ�
	}

protected:
	Node* _root;
};



// _parentָ�������