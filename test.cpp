//һ��ʵ��һ��ջ��Ҫ��ʵ��Push����ջ����Pop����ջ����Min��������Сֵ�Ĳ�������ʱ�临�Ӷ�ΪO(1)
#include <iostream>
#include <stack>
#include <cassert>
#include <queue>
#include <list>
using namespace std;

//�汾1
//template<class T>
//class Stack_ReturnMin
//{
//public:
//	Stack_ReturnMin()
//		:s1(new stack<T>)
//		, s2(new stack<T>)
//	{
//		cout << "��ջ�������" << endl;
//	}
//	void Push(const T& x)
//	{
//		if (s1->empty())
//		{
//			s1->push(x);
//			s2->push(x);
//		}
//		else
//		{
//			s1->push(x);
//			if (x < s2->top())
//			{
//				s2->push(x);
//			}
//		}
//	}
//	void Pop()
//	{
//		assert(!s1->empty());
//		assert(!s2->empty());
//		if (s1->top() == s2->top())
//		{
//			s1->pop();
//			s2->pop();
//		}
//		else
//		{
//			s1->pop();
//		}
//	}
//	T& Min()
//	{
//		assert(!s2->empty());
//		return s2->top();
//	}
//	T& Top()
//	{
//		assert(!s1->empty());
//		return s1->top();
//	}
//protected:
//	stack<T>*  s1;               
//	stack<T>*  s2;              //ջ����ŵ��ǵ�ǰ��ֵ��С��Ԫ��
//};
//int main()
//{
//	Stack_ReturnMin<int> s;
//	s.Push(1);
//	s.Push(2);
//	s.Push(3);
//	s.Push(4);
//
//	s.Pop();
//	cout << s.Min() << endl;
//	return 0;
//}

//2. ʹ������ջʵ��һ������

//
//template<class T>
//class Queue
//{
//public:
//	Queue()
//		:s1(new stack<T>)
//		,s2(new stack<T>)
//	{
//		cout << "Had Inited" << endl;
//	}
//	void InQueue(const T& x)
//	{
//		if (s1->empty() && s2->empty())
//		{
//			s1->push(x);
//		}
//		else if (s1->empty() && !s2->empty())
//		{
//			while (!s2->empty())
//			{
//				s1->push(s2->top());
//				s2->pop();
//			}
//			s1->push(x);
//		}
//		else
//		{
//			s1->push(x);
//		}
//	}
//	size_t Size()
//	{
//		if (s1->empty())
//		{
//			return s2->size();
//		}
//		if (s2->empty())
//		{
//			return s1->size();
//		}
//		else
//			return -1;
//	}
//	T OutQueue()
//	{
//		assert(!s1->empty() || !s2->empty());              //ִ�г��Ӳ�����s1��s2��������һ������ΪNULL
//		//assert((!s1->empty())&& (!s2->empty()));
//		int ret;
//		if (s2->empty())                            //���������s2Ϊ�գ����s1�ĵ���s2��
//		{
//			while (s1->size()!=1)
//			{
//				s2->push(s1->top());
//				s1->pop();
//			}
//			ret = s1->top();
//			s1->pop();
//		}
//		else                                       //���s1Ϊ��
//		{
//			ret = s2->top();
//			s2->pop();
//		}
//		return ret;
//	}
//protected:
//	stack<T>* s1;
//	stack<T>* s2;
//};
//int main()
//{
//	Queue<int> q1;
//	q1.InQueue(1);
//	q1.InQueue(2);
//	q1.InQueue(3);
//	q1.OutQueue();
//	q1.InQueue(4);
//	int len = q1.Size();
//	for (int i = 0; i < len; i++)
//	{
//		cout << q1.OutQueue() << " ";
//	}
//	cout << endl;
//	return 0;
//}

//3:��������ʵ��һ��ջ
//template<class T>
//class Stack
//{
//public:
//	Stack()
//		:q1(new queue<T>)
//		, q2(new queue<T>)
//	{
//		cout << "The Stack is inited" << endl;
//	}
//	void Push(const T& x)
//	{
//		q1->push(x);
//	}
//	void Pop()
//	{
//		assert(!q1->empty());
//		while (q1->size() != 1)
//		{
//			q2->push(q1->front());
//			q1->pop();
//		}
//		q1->pop();
//		while (!q2->empty())
//		{
//			q1->push(q2->front());
//			q2->pop();
//		}
//	}
//	T& Top()
//	{
//		assert(!q1->empty());
//		/*while (q1->size() != 1)
//		{
//			q2->push(q1->front());
//			q1->pop();
//		}
//		while (!q2->empty())
//		{
//			q1->push(q2->front());
//			q2->pop();
//		}*/
//		return q1->back();
//	}
//	bool Empty()
//	{
//		return q1->size() == 0;
//	}
//protected:
//	queue<T>* q1;
//	queue<T>* q2;
//};




//int main()
//{
//	Stack<int> q;
//	q.Push(1);
//	q.Push(2);
//	q.Push(3);
//	q.Push(4);
//	q.Pop();
//	q.Push(5);
//
//	while (!q.Empty())
//	{
//		cout << q.Top() << " ";
//		q.Pop();
//	}
//	cout << endl;
//	return 0;
//}

////4 . �ж�Ԫ�س�ջ����ջ˳��ĺϷ���
//template<class T>
//class OutStack
//{
//public:
//	OutStack()
//		:sL_in(new list<T>)
//		,sL_out(new list<T>)
//		,ss(new stack<T>)
//	{
//		cout << "��ʼ�����" << endl;
//	}
//	void Push(const T& x)
//	{
//		ss->push(x);
//		sL_in->push_back(x);
//	}
//	void Pop()
//	{
//		sL_out->push_back(ss->top());
//		ss->pop();
//	}
//	bool InMatchingOut()
//	{
//		return sL_in->size() == sL_out->size();
//	}
//	~OutStack()
//	{
//		delete sL_in;
//		delete sL_out;
//		delete ss;
//	}
//public:
//  list<T>* sL_in;                 //������ջ���е�ָ�룻
//  list<T>*  sL_out;               //�����ջ���е�ָ�룻��ջ����Ϊ������ʽ
//  stack<T>* ss;              
//};
//
//int main()
//{
//	OutStack<int> s1;
//	s1.Push(1);
//	s1.Push(2);
//	s1.Push(3);
//	s1.Pop();
//	s1.Push(4);
//	s1.Pop();
//	s1.Pop();
//	cout << s1.InMatchingOut() << endl;
//	return 0;
//}

////������
////���������м�������ѹջ
//template<class T>
//class TwoStack
//{
//	enum ConstLen
//	{
//		Len = 6,
//	};
//public:
//	TwoStack(const int& x=0)
//		:len(x)
//		, Array(new vector<T>[len])
//		, top1(len/2)
//		, top2(top1+1)
//		, size1(0)
//		, size2(0)
//	{}
//	void Push1(const T& x)
//	{
//		assert(top1 >= 0);
//		Array->operator[top1];
//		top1--;
//		size1++;
//	}
//	void Push2(const T& x)
//	{
//		assert(top2 <= Array->size());
//		Array->operator[top2];
//		top2++;
//		size2++;
//	}
//	void Pop1()
//	{
//		top1++;
//	}
//	void Pop2()
//	{
//		top2--;
//	}
//	~TwoStack()
//	{
//		if (Array)
//			delete[] Array;
//		Array = NULL;
//	}
//	bool Empty1()
//	{
//		return top1 == len / 2;
//	}
//	bool Empty2()
//	{
//		return top2 == len / 2 + 1;
//	}
//	T& Top1()
//	{
//		return Array->operator[top1];
//	}
//	T& Top2()
//	{
//		return Array->operator[top2];
//	}
//private:
//	//void CheckCapacity()
//	//{
//	//	if (top1 == 0 || top2 == len)
//	//	{
//	//		queue<T> str1;
//	//		queue<T> str2;
//	//		while (!Empty1())
//	//		{
//	//			str1.push(Top1());
//	//			Pop1();
//	//		}
//	//		while (!Empty2())
//	//		{
//	//			str2.push(Top2());
//	//			Pop2();
//	//		}
//	//		int NewLen = len + ConstLen::Len;
//	//		vector<T>* tmp = new vector<T>[NewLen];
//	//		top1 = NewLen / 2;
//	//		top2 = top1;
//	//		while (!str1.empty())
//	//		{
//	//			tmp[str1.front(
//	//		}
//	//	}
//	//}
//protected:
//	int len;                //����ĳ���
//	vector<T>* Array;               //����
//	int top1;
//	int top2;
//	int size1;
//	int size2;
//};
//
//int main()
//{
//	TwoStack<int> s(10);
//	s.Push1(1);
//	s.Push2(2);
//	s.Push1(3);
//	s.Push2(4);
//	while (!s.Empty1())
//	{
//		cout << s.Top1() << " ";
//		s.Pop1();
//	}
//	cout << endl;
//	while (!s.Empty2())
//	{
//		cout << s.Top2() << " ";
//		s.Pop2();
//	}
//	cout << endl;
//	return 0;
//}d


//int main()
//{
//	vector<int>* v1 = new vector<int>[10];
//	(*v1)[1] = 0;
//	cout << (*v1)[1] << endl;
//	cout << (*v1)[3] << endl;
//	return 0;
//}