#include <stack>
#include <iostream>
#include <cstring>
#include <cassert>
#include <string>
#include <queue>
using namespace std;

//class A
//{
//public:
//	A()
//	{
//		/*memset(this, 0, sizeof(*this));*/
//	}
//	virtual void fun()
//	{
//		cout << "fun()" << endl;
//	}
//};
//int main()
//{
//	A a;
//	a.fun();
//
//	A& ra = a;
//	ra.fun();
//
//	A* pa = &a;
//	pa->fun();
//	return 0;
//}

//堆栈面试题4   判断出栈和入栈序列的合法性
//str1为入栈序列
//str2为出栈序列
//bool CheckInAndOut(const string& str1,const string& str2)
//{
//	assert(str1.size() > 0);
//	assert(str2.size() > 0);
//	assert(str1.size() == str2.size());
//	stack<char> s1;  
//	queue<char> q1;
//	int i = 0;
//	int j = 0;
//	while(j < str2.size())
//	{
//		if (str1[i] == str2[j])
//		{
//			q1.push(str1[i]);
//			//i++;
//			j++;                      //将当前元素入队，并检查之前入栈的元素，如果相等，也入队
//			while ((s1.size() != 0) && (j<str2.size()) && (str2[j] == s1.top()))
//			{
//				q1.push(s1.top());
//				s1.pop();
//				j++;
//			}
//		}
//		else
//		{
//			s1.push(str1[i]);
//			i++;
//		}
//	}        //模拟构造出栈队列
//	int z = 0;
//	for (z = 0; z < str2.size(); z++)
//	{
//		if (str2[z] != q1.front())
//		{
//			break;
//		}
//		else
//		{
//			q1.pop();
//		}
//	}
//	if (z == str2.size()){
//		return true;
//	}
//	else{
//		return false;
//	}
//}
//int main()
//{
//	string s1("12345");
//	string s2("32154");
//	cout << CheckInAndOut(s1, s2) << endl;
//	return 0;
//}